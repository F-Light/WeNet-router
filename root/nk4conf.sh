#!/bin/sh
######开始切换电脑版
sleep 1
lock="/www/origin.lock"
if [ -f "$lock" ]; then
	echo "非初始环境.不需要备份"
else
	echo "初始环境.开始备份"
	
	cp /etc/config/wireless /etc/config/wireless.origin
	cp /etc/config/firewall /etc/config/firewall.origin
	cp /etc/config/network /etc/config/network.origin
	echo origin > /www/origin.lock
	wan_mac_old=$(ifconfig $(ubus call network.interface.wan status | grep device | awk -F '\"' '{print $4}' | tail -n 1) | grep HWaddr | awk '{print $5}')
	echo $wan_mac_old
	echo $wan_mac_old > /www/mac_save_old
	echo "完成备份"
fi



sleep 1 

#######自动安装pppoe服务器
if [ -z "$(opkg list-installed | grep "rp-pppoe-server")" ]
then
    echo "未发现pppoe服务器，下面开始安装。"
	opkg install /root/rp-pppoe-common_3.11-1_mipsel_24kec_dsp.ipk
	opkg install /root/rp-pppoe-server_3.11-1_mipsel_24kec_dsp.ipk
	sleep 2
    #exit 0
	else
	echo "已安装。"
fi




######################
pc="/etc/init.d/nk4"
if [ -f "$pc" ]; then
	echo "当前环境为电脑版。不需要操作"
	echo "pc is running, exit!"
	exit 0
	
else
	# echo "即将执行电脑版切换，开始备份手机版文件"
	# cp /etc/config/wireless /etc/config/wireless.backpc
	# cp /etc/config/firewall /etc/config/firewall.backpc
	# cp /etc/config/network /etc/config/network.backpc
	echo "开始切换"
	
fi

sleep 1
 #####防止在执行中，wifi配置出现严重崩溃
	faaa=$(grep wifi-iface /etc/config/wireless | wc -l)
	if [  "$faaa" -ge 1 ]; then
	
		echo "非首次运行"
		cp /etc/config/wireless.back /etc/config/wireless
	
	else 
		echo "首次运行，不用重置."
	fi
	uci commit
	sleep 1
######


#Check PPPoE-Server
if [ -z "$(opkg list-installed | grep "rp-pppoe-server")" ]
then
    echo "Please install PPPoE-Server first"
    exit 0
fi

#change log location & enable debug & show password
sed -i "s/\/dev\/null/\/tmp\/pppoe.log/" /etc/ppp/options
sed -i "s/#debug/debug/" /etc/ppp/options
echo "show-password" >> /etc/ppp/options

cp /etc/ppp/plugins/rp-pppoe.so /etc/ppp/plugins/rp-pppoe.so.bak
cp /usr/lib/pppd/2.4.7/rp-pppoe.so /etc/ppp/plugins/rp-pppoe.so

#set network
uci delete network.wan6
uci commit network

uci set network.wan=interface
uci set network.wan.ifname=$(uci get network.wan.ifname)
#uci set network.wan.macaddr=aabbccddeeff
uci set network.wan.proto=pppoe
uci set network.wan.username=username
uci set network.wan.password=password
uci set network.wan.metric='0'
uci set network.wan.auto='0'
uci commit network

#set firewall
uci set firewall.@zone[1].network='wan wan'
uci commit firewall
/etc/init.d/firewall restart
/etc/init.d/network reload
/etc/init.d/network restart

#enable \r in PPPoE
cp /lib/netifd/proto/ppp.sh /lib/netifd/proto/ppp.sh_bak
sed -i '/proto_run_command/i username=`echo -e "$username"`' /lib/netifd/proto/ppp.sh

#set init script
cp /root/nk4 /etc/init.d/nk4
chmod +x /etc/init.d/nk4
/etc/init.d/nk4 enable
sleep 5
(/etc/init.d/nk4 start &)
