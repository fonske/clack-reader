# clack-reader
Printed circuit board to read out a Clack WS1CK watersoftener with ultrasonic sensor and pulse relais of the WS1.

See README directory for more information on how to set this up and connect.

# Platforms
Currently supported ESP32 (wemos d32 mini), ESP32S3 (lilygo S3-T7), ESP32 S3 (wemos S3 mini) and ESP8266 (wemos d1 mini) platforms.
By default ESP32 S3 mini is used. If you want to use ESP8266 for example, edit file `esphome/clack.yaml`, comment out esp32 include and uncomment esp8266 include file.

```
packages:
  remote_package:
    url: https://github.com/fonske/clack-reader
    ref: main
    refresh: 0s
    files: [ esphome/.clack-labels-nl.yaml, esphome/board-esp32-wemos-s3.yaml ]
## choices are: esphome/.clack-labels-en.yaml, esphome/.clack-labels-nl.yaml
## esphome/board-esp32.yaml, esphome/board-esp32s3.yaml,
## esphome/board-esp32-wemos-s3.yaml, esphome/board-esp8266.yaml

## for developing/testing, uncomment local includes and comment out above remote_package packages part.
#packages:
#  substitutions: !include .clack-labels-en.yaml
#  substitutions: !include .clack-labels-nl.yaml
#  device_base1:  !include board-esp32.yaml
#  device_base1:  !include board-esp32s3.yaml
#  device_base1:  !include board-esp32-wemos-s3.yaml
#  device_base1:  !include board-esp8266.yaml
```

# Translations
Currently supported languages are en, nl.
In order to change language, edit file `esphome/clack.yaml`, and change include file (esphome-/.clack-labels-<language>.yaml)

## Contact
Contact me: alphonsuijtdehaag at gmail dot com, if you are interested in a PCB with a ESP32 (mh-et-live or lilygo ESP32S3-T7 or Wemos s3 mini) and ultrasonic sensor (DFrobot)
