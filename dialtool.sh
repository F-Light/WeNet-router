#!/bin/sh
sleep 3
pid="/tmp/dialtool.pid"
if [ -f "$pid" ]; then
	echo "dialtool is running, exit!"
	exit 0
fi
echo runnig > /tmp/dialtool.pid
flag="/etc/config/wireless.back"
if [ -f "$flag" ]; then
	echo "second."
else
	echo "first."
	uci set dhcp.@dhcp[0].force="1"
	wan_mac_old=$(ifconfig $(ubus call network.interface.wan status | grep device | awk -F '\"' '{print $4}' | tail -n 1) | grep HWaddr | awk '{print $5}')
	echo $wan_mac_old
	echo $wan_mac_old > /www/mac_save_old
fi

mark=$1
if [ $mark -eq 1 ]; then
	echo "dialtool start."
	cp /etc/config/wireless /etc/config/wireless.back
	wifi_name_old=$(uci get wireless.@wifi-iface[0].ssid)
	echo $wifi_name_old > /www/wifi_name_old
	wifi_old_num=$(grep wifi-iface /etc/config/wireless | wc -l)
	case "$wifi_old_num" in
		1)
			uci add wireless wifi-iface
			wifi_encryption_old=$(uci get wireless.@wifi-iface[0].encryption)
			if [ "$wifi_encryption_old"x = "none"x ]; then
				uci set wireless.@wifi-iface[1].encryption="none"
			else
				wifi_key_old=$(uci get wireless.@wifi-iface[0].key)
				uci set wireless.@wifi-iface[1].encryption="psk2"
				uci set wireless.@wifi-iface[1].key="$wifi_key_old"
			fi
			uci set wireless.@wifi-iface[1].device="radio0"
			uci set wireless.@wifi-iface[1].network="lan"
			uci set network.wan6.type="bridge"
			uci set wireless.@wifi-iface[1].mode="ap"
			uci set wireless.@wifi-iface[1].maxassoc="1"
			wifi_name_old=$(cat /www/wifi_name_old | awk '{print $1}')
			if [ ${#wifi_name_old} -ge 13 ]; then
				wifi_name_old=${wifi_name_old:0:13}
			fi
			uci set wireless.@wifi-iface[1].ssid="${wifi_name_old}_辅助_$(head /dev/urandom |tr -cd a-f0-9|cut -c 1-6)"
			uci set wireless.@wifi-iface[1].disabled="0"
			;;
		2)
			uci add wireless wifi-iface
			wifi_encryption_old=$(uci get wireless.@wifi-iface[0].encryption)
			if [ "$wifi_encryption_old"x = "none"x ]; then
				uci set wireless.@wifi-iface[2].encryption="none"
			else
				wifi_key_old=$(uci get wireless.@wifi-iface[0].key)
				uci set wireless.@wifi-iface[2].encryption="psk2"
				uci set wireless.@wifi-iface[2].key="$wifi_key_old"
			fi
			uci set wireless.@wifi-iface[2].device="radio0"
			uci set wireless.@wifi-iface[2].network="lan"
			uci set network.wan6.type="bridge"
			uci set wireless.@wifi-iface[2].mode="ap"
			uci set wireless.@wifi-iface[2].maxassoc="1"
			wifi_name_old=$(cat /www/wifi_name_old | awk '{print $1}')
			if [ ${#wifi_name_old} -ge 13 ]; then
				wifi_name_old=${wifi_name_old:0:13}
			fi
			uci set wireless.@wifi-iface[2].ssid="${wifi_name_old}_辅助_$(head /dev/urandom |tr -cd a-f0-9|cut -c 1-6)"
			uci set wireless.@wifi-iface[2].disabled="0"
			
			uci add wireless wifi-iface
			wifi_encryption_old=$(uci get wireless.@wifi-iface[1].encryption)
			if [ "$wifi_encryption_old"x = "none"x ]; then
				uci set wireless.@wifi-iface[3].encryption="none"
			else
				wifi_key_old=$(uci get wireless.@wifi-iface[1].key)
				uci set wireless.@wifi-iface[3].encryption="psk2"
				uci set wireless.@wifi-iface[3].key="$wifi_key_old"
			fi
			uci set wireless.@wifi-iface[3].device="radio1"
			uci set wireless.@wifi-iface[3].network="lan"
			uci set network.wan6.type="bridge"
			uci set wireless.@wifi-iface[3].mode="ap"
			uci set wireless.@wifi-iface[3].maxassoc="1"
			wifi_name_old=$(cat /www/wifi_name_old | awk '{print $1}')
			if [ ${#wifi_name_old} -ge 13 ]; then
				wifi_name_old=${wifi_name_old:0:13}
			fi
			uci set wireless.@wifi-iface[3].ssid="${wifi_name_old}_辅助_$(head /dev/urandom |tr -cd a-f0-9|cut -c 1-6)"
			uci set wireless.@wifi-iface[3].disabled="0"
	esac
	uci commit
	/etc/init.d/odhcpd restart 1>/dev/null 2>&1
	/etc/init.d/network restart 1>/dev/null 2>&1
	/etc/init.d/firewall restart 1>/dev/null 2>&1
	wifi down
	wifi up
	while ( [ ${#cellphone_mac_wlan0} -lt 6 ] && [ ${#cellphone_mac_wlan1} -lt 6 ] )
	do
		cellphone_mac_wlan0=$(iwinfo wlan0-1 assoclist | head -n 1 | awk '{print $1}')
		cellphone_mac_wlan1=$(iwinfo wlan1-1 assoclist | head -n 1 | awk '{print $1}')
		echo $cellphone_mac_wlan0 > /www/mac_save_new_wlan0
		echo $cellphone_mac_wlan1 > /www/mac_save_new_wlan1
		sleep 3
		echo $cellphone_mac_wlan0 > /www/mac_save_new
		if [ ${#cellphone_mac_wlan0} -lt 6 ]; then
			echo $cellphone_mac_wlan1 > /www/mac_save_new
		fi
	done
else
	echo "dialtoll stop."
	#uci set wireless.@wifi-iface[1].disabled="1"
	cp /etc/config/wireless.back /etc/config/wireless
	wan_mac_new=$(cat /www/mac_save_new_wlan0 | awk '{print $1}')
	if [ ${#wan_mac_new} -lt 6 ]; then
		wan_mac_new=$(cat /www/mac_save_new_wlan1 | awk '{print $1}')
	fi
	uci set network.wan.proto="dhcp"
	uci set network.wan.macaddr="$wan_mac_new"
	uci set network.@device[1].macaddr="$wan_mac_new"
	uci delete network.wan6.type
	
	uci commit
	/etc/init.d/odhcpd restart 1>/dev/null 2>&1
	/etc/init.d/network restart 1>/dev/null 2>&1
	/etc/init.d/firewall restart 1>/dev/null 2>&1
	wifi down
	wifi up
fi
rm /tmp/dialtool.pid
