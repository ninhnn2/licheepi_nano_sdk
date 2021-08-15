#!/bin/sh

mount -t jffs2 /dev/mtdblock4 /rom

insmod /root/esp8089.ko

sleep 5

wpa_supplicant -Dwext -iwlan0 -c/etc/wpa_supplicant.conf &

ifconfig wlan0 up
ifconfig wlan0 192.168.1.100 netmask 255.255.255.0
route add default gw 192.168.1.1

