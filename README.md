# clack-reader
Printed circuit board to read out a Clack WS1CK watersoftener with ultrasonic sensor

See README directory for more information on how to set this up.

# Platforms
Currently supprted ESP32 (wemos d32 mini), ESP32S3 (lilygo S3-T7) and ESP8266 (wemos d1 mini) platforms.
By default ESP32 is used. If you want to use ESP8266 for example, edit file `esphome/clack.yaml`, comment out esp32 include and uncomment esp8266 include file.

```
packages:
  remote_package:
    url: https://github.com/fonske/clack-reader
    ref: main
    files: 
      - esphome/.clack-labels-en.yaml
      # - esphome/.clack-labels-nl.yaml
      # - esphome/board-esp32.yaml
      # - esphome/board-esp32s3.yaml
      # - esphome/board-esp32-wemos-s3
      - esphome/board-esp8266.yaml
```

# Translations
Currently supported languages are en, nl.
In order to change language, edit file `esphome/clack.yaml`, and change include file (esphome-/.clack-labels-<language>.yaml)

## Contact
Contact me: alphonsuijtdehaag at gmail dot com, if you are interested in a PCB with a ESP32 (mh-et-live or lilygo ESP32S3-T7 or Wemos s3 mini) and ultrasonic sensor (DFrobot)
