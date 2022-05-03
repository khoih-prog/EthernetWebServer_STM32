## EthernetWebServer_STM32

[![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/EthernetWebServer_STM32.svg)](https://github.com/khoih-prog/EthernetWebServer_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/EthernetWebServer_STM32.svg)](http://github.com/khoih-prog/EthernetWebServer_STM32/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.5.0](#releases-v150)
  * [Releases v1.4.1](#releases-v141)
  * [Releases v1.4.0](#releases-v140)
  * [Releases v1.3.4](#releases-v134)
  * [Releases v1.3.3](#releases-v133)
  * [Releases v1.3.2](#releases-v132)
  * [Releases v1.3.1](#releases-v131)
  * [Major Releases v1.3.0](#major-releases-v130)
  * [Releases v1.2.1](#releases-v121)
  * [Releases v1.2.0](#releases-v120)
  * [Releases v1.1.1](#releases-v111)
  * [Major Releases v1.1.0](#major-releases-v110)
  * [Releases v1.0.6](#releases-v106)
  * [Major Releases v1.0.5](#major-releases-v105)
  * [Releases v1.0.4](#releases-v104)
  * [Releases v1.0.3](#releases-v103)
  * [Releases v1.0.2](#releases-v102)
  * [Releases v1.0.1](#releases-v101)

---
---

## Changelog

### Releases v1.5.0

1. Add support to any custom hardware / software `SPI` for W5x00 using [Ethernet_Generic Library](https://github.com/khoih-prog/Ethernet_Generic)
2. Add support to STM32L5 boards, such as `Nucleo-L552ZE-Q`

### Releases v1.4.1

1. Change from `arduino.cc` to `arduino.tips` in examples

### Releases v1.4.0

1. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
2. Rewrite all the examples to support new features
3. Add example [multiFileProject](examples/multiFileProject) to demo how to avoid `multiple-definitions` linker error for multiple-file project

### Releases v1.3.4

1. Fix decoding error bug when using special `&` in data fields. Check [Decoding Error. two times called urlDecode in Parsing-impl.h. #17](https://github.com/khoih-prog/WiFiWebServer/issues/17)

### Releases v1.3.3

1. Fix libb64 `fallthrough` compile warning

### Releases v1.3.2

1. Fix wrong http status header bug. Check [fix for wrong http status header #42](https://github.com/khoih-prog/EthernetWebServer/pull/42)
2. Fix authenticate issue caused by libb64

### Releases v1.3.1

1. Fix bug related to String in examples

### Major Releases v1.3.0

1. Reduce usage of Arduino String with std::string
2. Optimize library code and examples by using **reference-passing instead of value-passing**.
3. Update `Packages' Patches`

### Releases v1.2.1

1. Change option for **PIO** `lib_compat_mode` from default `soft` to `strict` to minimize compile error in cross-platform
2. Update `Packages' Patches`


### Releases v1.2.0

1. Add support to **LAN8720** Ethernet for many **STM32F4** (F407xx, NUCLEO_F429ZI) and **STM32F7** (DISCO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG) boards.
2. Add LAN8720 examples
3. Add Packages' Patches for STM32 to use LAN8720 with STM32Ethernet and LwIP libraries

### Releases v1.1.1

1. Clean-up all compiler warnings possible.
2. Add Table of Contents
3. Add examples
4. Add Version String 

### Major Releases v1.1.0

1. Add high-level **HTTP and WebSockets Client** by merging [ArduinoHttpClient Library](https://github.com/arduino-libraries/ArduinoHttpClient)
2. Add many more examples for HTTP and WebSockets Client.

### Releases v1.0.6

1. Add support to PROGMEM-related commands, such as sendContent_P() and send_P()
2. Update Platform.ini to support PlatformIO 5.x owner-based dependency declaration.
3. Clean up code. 

### Major Releases v1.0.5

1. Add support to new [**`EthernetENC library`**](https://github.com/jandrassy/EthernetENC) for ENC28J60.
2. Add support to [`Ethernet2`](https://github.com/adafruit/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) and [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) libraries on top of [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet).
2. Add debug feature. Clean up code. Restructure examples.
  
#### Releases v1.0.4

1. Add support to all STM32 boards (**STM32F/L/H/G/WB/MP1**) with 32K+ Flash.

  - STM32L0, STM32L1, STM32L4
  - STM32G0, STM32G4
  - STM32H7
  - STM32WB
  - STM32MP1

#### Releases v1.0.3

1. Fix bug not closing client and releasing socket.
2. Merge new features from latest ESP8266WebServer
3. Add and enhance examples.
4. Restore dependency to [`Functional-Vlpp library`](https://github.com/khoih-prog/functional-vlpp).

### Releases v1.0.2

1. Remove dependency on [`Functional-Vlpp library`](https://github.com/khoih-prog/functional-vlpp).
2. Enhance examples and update README.md

### Releases v1.0.1

1. Add support to **W5x00** Ethernet shields to all STM32 boards having 64+K bytes Flash.



