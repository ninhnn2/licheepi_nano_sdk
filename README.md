![10742fe16f9898c6c189](https://user-images.githubusercontent.com/86546911/126890831-2fc226ee-0686-4011-8c79-c5a47be7d76e.jpg)


MANUAL
=======================
```shell
git clone https://github.com/ninhnn2/licheepi_nano_sdk.git
cd licheepi_nano_sdk/
sudo chmod +x ./build.sh
./build.sh pull_all
```
BUILD ROM FOR SDCARD
=======================

```shell
./build.sh nano_tf
```

BUILD ROM FOR NORFLASH 16MB
=======================

```shell
./build.sh nano_spiflash
```

The norflash rom include wifi module esp8089

Static IP: 192.168.1.100

Change ssid and password for Lichee Pi Nano 

```shell
shell# vim esp8089/wpa_supplicant.conf

network={
        ssid="embedded"
        psk="VIETNAM"
}
```


FLASH ROM TO SDCARD
=======================

```shell
cd licheepi_nano_sdk/output/image/
sudo dd bs=4M if=lichee-nano-normal-size.img of=/dev/sdb conv=fsync
```

ROM FOR TESTING
===============
user/passwd: root/000

[sdcard rom test](https://mega.nz/file/Myp20YxZ#7GH6VL6gQFb6ywQPv-gALdYCResSTUQDG2RmtdAWigw)

[norflash rom test](https://mega.nz/file/xuZBmYRJ#ES87VDUaZ-a5ne9D-fwORBrPsOvWDQMtUYfelrDtgg8)
