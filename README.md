![10742fe16f9898c6c189](https://user-images.githubusercontent.com/86546911/126890831-2fc226ee-0686-4011-8c79-c5a47be7d76e.jpg)


MANUAL
=======================
```shell
git clone https://github.com/ninhnn2/licheepi_nano_sdk.git
cd licheepi_nano_sdk/
sudo chmod ++x ./build.sh
./build.sh pull_all
```
BUILD ROM FOR SDCARD
=======================

```shell
./build.sh nano_tf
```

FLASH ROM TO SDCARD
=======================

```shell
cd licheepi_nano_sdk/output/image/
sudo dd bs=4M if=lichee-nano-normal-size.img of=/dev/sdb conv=fsync
```

ROM FOR TESTING
=======================
## user   : root

## passwd : 000

[Example rom for test](https://mega.nz/file/Myp20YxZ#7GH6VL6gQFb6ywQPv-gALdYCResSTUQDG2RmtdAWigw)
