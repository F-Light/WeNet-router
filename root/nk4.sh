#!/bin/sh

#start pppoe-server
if [ -n "$(ps | grep pppoe-server | grep -v grep)" ]
then
    killall pppoe-server
fi
pppoe-server -k -I br-lan

#clear logs
cat /dev/null > /tmp/pppoe.log

while :
do
    #read the last username in pppoe.log
    userinfo=$(grep 'user=' /tmp/pppoe.log | grep 'rcvd' | tail -n 1)
    name=${userinfo#*'"'}
    username=${name%'" password="'*}
    word=${userinfo#*'" password="'}
    password=${word%'"]'}

    if [ "$username" != "$username_old" ]
    then
        ifdown wan
        uci set network.wan.username="$username"
        uci set network.wan.password="$password"
        uci commit
        ifup wan
        username_old="$username"
        logger -t nk4 "new username $username"
    fi
    
    sleep 10

    #close pppoe if log fail
    if [ -z "$(ifconfig | grep "wan")" ]
    then
        ifdown wan
    fi

done
