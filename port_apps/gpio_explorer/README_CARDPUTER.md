# GPIO Explorer — Cardputer ADV port

Port of EvgeniGenchev07/gpio_explorer for this ESP32-S3 Flipper runtime.

## Safe GPIO mapping

Only the externally exposed Grove/Qwiic pins are selectable:

- G2 (SDA) = ESP32-S3 GPIO2
- G1 (SCL) = ESP32-S3 GPIO1

The original Flipper PA/PB/PC pin list is intentionally not used because this
firmware maps several of those compatibility aliases onto the CC1101/SD shared
SPI bus and other internal peripherals.

GPIO1 is also used as IR RX in the current ADV board definition. Do not use IR
RX concurrently while GPIO Explorer owns G1.

## RGB mode

The ADV exposes only two safe general-purpose GPIO pins, while a discrete RGB
LED normally needs three channels. RGB mode is retained for compatibility and
testing but channels necessarily share pins. LED and GPIO Reader modes are the
primary useful modes on the stock ADV hardware.

## Build

From the repository root:

    ./buildFap.sh port_apps/gpio_explorer

Expected ADV output:

    build_cardputer_adv/fap/gpio_explorer_app.fap

Copy the FAP to the SD card Apps/GPIO directory.
