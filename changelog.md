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
4. Restore dependency to [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).

### Releases v1.0.2

1. Remove dependency on [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).
2. Enhance examples and update README.md

### Releases v1.0.1

1. Add support to **W5x00** Ethernet shields to all STM32 boards having 64+K bytes Flash.

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.13+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino Core for STM32 v1.9.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
 3.  [`Functional-VLPP library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
 4. For built-in LAN8742A or LAN8720 Ethernet:
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest)
   - [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest)
 5. For W5x00 Ethernet:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
 6. For ENC28J60 Ethernet:
   - [`EthernetENC library v2.0.0+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.9+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)


---

## Installation

### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for **`EthernetWebServer_STM32`**, then select / install the latest version. 
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32) for more detailed instructions.

### Manual Install

1. Navigate to [**EthernetWebServer_STM32**](https://github.com/khoih-prog/EthernetWebServer_STM32) page.
2. Download the latest release `EthernetWebServer_STM32-master.zip`.
3. Extract the zip file to `EthernetWebServer_STM32-master` directory 
4. Copy whole 
  - `EthernetWebServer_STM32-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**EthernetWebServer_STM32** library](https://platformio.org/lib/show/7077/EthernetWebServer_STM32) by using [Library Manager](https://platformio.org/lib/show/7077/EthernetWebServer_STM32/installation). Search for **EthernetWebServer_STM32** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 2. For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. Optional UIPthernet patch

Check if you need to install the UIPthernet patch [new STM32 core F3/F4 compatibility](https://github.com/UIPEthernet/UIPEthernet/commit/c6d6519a260166b722b9cee5dd1f0fb2682e6782) to avoid errors `#include HardwareSPI.h` on some STM32 boards (Nucleo-32 F303K8, etc.)

---
---

## Configuration Notes

### 1. How to select which built-in Ethernet or shield to use

#### Select **one and only one** Ethernet library to use as follows:

- Standard W5x00 Ethernet library 

Standard W5x00 using Ethernet library is used by default, in the sketch, just be sure to comment out or leave these #defines to be false :

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

#### To use built-in LAN8742A

```
#define USE_BUILTIN_ETHERNET    true
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

#### To use LAN8720

```
#define USING_LAN8720           true
#define USE_BUILTIN_ETHERNET    true
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

#### To use W5x00 Ethernet, for example using EthernetLarge library

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    true
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

#### To use ENC28J60 Ethernet, using EthernetENC library (**NEW and Better**)

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      true
  #define USE_CUSTOM_ETHERNET   false
#endif
```

#### To use ENC28J60 Ethernet, using UIPEthernet library

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        true

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

- To use any of the Ethernet libraries, such as Ethernet2, Ethernet3, EthernetLarge, EthernetENC:

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         true
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif
```

- To use another Ethernet library
For example, Ethernet_XYZ library uses **Ethernet_XYZ.h**

```cpp
#define USE_BUILTIN_ETHERNET    false
#define USE_UIP_ETHERNET        false

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one of the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   true
#endif

....

#elif USE_CUSTOM_ETHERNET
  //#include "Ethernet_XYZ.h"
  #include "EthernetENC.h"
  #warning Using Custom Ethernet library. You must include a library and initialize.
  #define SHIELD_TYPE           "Custom Ethernet & Ethernet_XYZ Library"
#else
  #define USE_ETHERNET          true
  #include "Ethernet.h"
  #warning Using Ethernet lib
  #define SHIELD_TYPE           "W5x00 & Ethernet Library"
#endif  
...

#include <EthernetWebServer.h>
```

---

### Important:

- The **Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported**. Don't use unless you know how to modify those libraries.
- Requests to support for any future custom Ethernet library will be ignored. **Use at your own risk**.

---

### 2. How to connect or select another CS/SS pin to use

**The default CS/SS pin is 10 for all boards, and is configurable in code.**

If the default pin is not corect, select another CS/SS pin (e.e. D22) to use as follows:

```cpp
// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
// Default pin 10 to SS/CS. To change according to your board, if necessary
//#define USE_THIS_SS_PIN       10
```

The current SPI pin usage can be displayed by turn on the debug option. For example:

Increase debug level to 2 in `defines.h` of any example:

```
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       2
```

The Debug Terminal will then show that the current SPI pin usage of **NUCLEO_F767ZI ==> SS/CS: D10, MOSI: D11, MISO: D12 and SCK: D13**

```
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
```

Connect the wires according to the displayed information.


### 3. How to increase W5x00 TX/RX buffer

- For **Ethernet3** library only,  use as follows

```cpp
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #ifndef ETHERNET3_MAX_SOCK_NUM
    #define ETHERNET3_MAX_SOCK_NUM      4
  #endif
  
  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
```


### 4. How to adjust sendContent_P() and send_P() buffer size

sendContent_P() and send_P() buffer size is set default at 4 Kbytes, and minimum is 512 bytes. If you need to change, just add a definition, e.g.:

```cpp
#define SENDCONTENT_P_BUFFER_SZ     2048
```

Note that the buffer size must be larger than 512 bytes. See [Sending GZIP HTML ~ 120kb+ (suggested enhancement)](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/3).


---
---

### Usage

#### Class Constructor

```cpp
  EthernetWebServer server(80);
```

Creates the EthernetWebServer class object.

*Parameters:* 
 
host port number: ``int port`` (default is the standard HTTP port 80)

#### Basic Operations

**Starting the server**

```cpp
  void begin();
```

**Handling incoming client requests**

```cpp
  void handleClient();
```

**Disabling the server**

```cpp
  void close();
  void stop();
```

Both methods function the same

**Client request handlers**

```cpp
  void on();
  void addHandler();
  void onNotFound();
  void onFileUpload();	
```

Example:

```cpp
  server.on("/", handlerFunction);
  server.onNotFound(handlerFunction);   // called when handler is not assigned
  server.onFileUpload(handlerFunction); // handle file uploads
```

**Sending responses to the client**

```cpp
  void send();
  void send_P();
  void sendContent_P();
```

`Parameters:`

`code` - HTTP response code, can be `200` or `404`, etc.

`content_type` - HTTP content type, like `"text/plain"` or `"image/png"`, etc.

`content` - actual content body

#### Advanced Options

**Getting information about request arguments**

```cpp
  const String & arg();
  const String & argName();
  int args();
  bool hasArg();
```

`Function usage:`

`arg` - get request argument value, use `arg("plain")` to get POST body
	
`argName` - get request argument name
	
`args` - get arguments count
	
`hasArg` - check if argument exist

**Getting information about request headers**

```cpp
  const String & header();
  const String & headerName();
  const String & hostHeader();
  int headers();
  bool hasHeader();
``` 
`Function usage:`

`header` - get request header value

`headerName` - get request header name

`hostHeader` - get request host header if available, else empty string
  
`headers` - get header count
	
`hasHeader` - check if header exist

**Authentication**

```cpp
  bool authenticate();
  void requestAuthentication();
```

`Function usage:`

`authenticate` - server authentication, returns true if client is authenticated else false

`requestAuthentication` - sends authentication failure response to the client

`Example Usage:`

```cpp

  if(!server.authenticate(username, password))
  {
    server.requestAuthentication();
  }
```

#### Other Function Calls

```cpp
  const String & uri(); // get the current uri
  HTTPMethod  method(); // get the current method 
  WiFiClient client(); // get the current client
  HTTPUpload & upload(); // get the current upload
  void setContentLength(); // set content length
  void sendHeader(); // send HTTP header
  void sendContent(); // send content
  void sendContent_P();  // send content in PROGMEM
  void collectHeaders(); // set the request headers to collect
  void serveStatic();
  size_t streamFile();
```

---
---

### HOWTO use STM32F4 with LAN8720

#### 1. Wiring

This is the Wiring for STM32F4 (BLACK_F407VE, etc.) using LAN8720


|LAN8720 PHY|<--->|STM32F4|
|:-:|:-:|:-:|
|TX1|<--->|PB_13|
|TX_EN|<--->|PB_11|
|TX0|<--->|PB_12|
|RX0|<--->|PC_4|
|RX1|<--->|PC_5|
|nINT/RETCLK|<--->|PA_1|
|CRS|<--->|PA_7|
|MDIO|<--->|PA_2|
|MDC|<--->|PC_1|
|GND|<--->|GND|
|VCC|<--->|+3.3V|

---

#### 2. HOWTO program using STLink V-2 or V-3

Connect as follows. To program, use **STM32CubeProgrammer** or Arduino IDE with 

- **U(S)ART Support: "Enabled (generic Serial)"**
- **Upload Method : "STM32CubeProgrammer (SWD)"**


|STLink|<--->|STM32F4|
|:-:|:-:|:-:|
|SWCLK|<--->|SWCLK|
|SWDIO|<--->|SWDIO|
|RST|<--->|NRST|
|GND|<--->|GND|
|5v|<--->|5V|


<p align="center">
    <img src="https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/pics/STM32F407VET6.png">
</p>

---

#### 3. HOWTO use Serial Port for Debugging

Connect FDTI (USB to Serial) as follows:

|FDTI|<--->|STM32F4|
|:-:|:-:|:-:|
|RX|<--->|TX=PA_9|
|TX|<--->|RX=PA_10|
|GND|<--->|GND|


---
---

### Examples:

#### Original Examples

 1. [AdvancedWebServer](examples/AdvancedWebServer)
 2. [HelloServer](examples/HelloServer)
 3. [HelloServer2](examples/HelloServer2)
 4. [HttpBasicAuth](examples/HttpBasicAuth)
 5. [**MQTTClient_Auth**](examples/MQTTClient_Auth)
 6. [**MQTTClient_Basic**](examples/MQTTClient_Basic)
 7. [**MQTT_ThingStream**](examples/MQTT_ThingStream)
 8. [PostServer](examples/PostServer)
 9. [SimpleAuthentication](examples/SimpleAuthentication)
10. [UdpNTPClient](examples/UdpNTPClient)
11. [UdpSendReceive](examples/UdpSendReceive)
12. [WebClient](examples/WebClient)
13. [WebClientRepeating](examples/WebClientRepeating)
14. [WebServer](examples/WebServer)

#### HTTP and WebSocket Client New Examples

 1. [BasicAuthGet](examples/HTTPClient/BasicAuthGet)
 2. [CustomHeader](examples/HTTPClient/CustomHeader)
 3. [DweetGet](examples/HTTPClient/DweetGet)
 4. [DweetPost](examples/HTTPClient/DweetPost)
 5. [HueBlink](examples/HTTPClient/HueBlink)
 6. [node_test_server](examples/HTTPClient/node_test_server)
 7. [PostWithHeaders](examples/HTTPClient/PostWithHeaders)
 8. [SimpleDelete](examples/HTTPClient/SimpleDelete)
 9. [SimpleGet](examples/HTTPClient/SimpleGet)
10. [SimpleHTTPExample](examples/HTTPClient/SimpleHTTPExample)
11. [SimplePost](examples/HTTPClient/SimplePost)
12. [SimplePut](examples/HTTPClient/SimplePut)
13. [SimpleWebSocket](examples/HTTPClient/SimpleWebSocket)

#### LAN8720 Examples

 1. [AdvancedWebServer_LAN8720](examples/STM32_LAN8720/AdvancedWebServer_LAN8720)
 2. [HelloServer_LAN8720](examples/STM32_LAN8720/HelloServer_LAN8720)
 3. [HelloServer2_LAN8720](examples/STM32_LAN8720/HelloServer2_LAN8720)
 4. [HttpBasicAuth_LAN8720](examples/STM32_LAN8720/HttpBasicAuth_LAN8720)
 5. [**MQTTClient_Auth_LAN8720**](examples/STM32_LAN8720/MQTTClient_Auth_LAN8720)
 6. [**MQTTClient_Basic_LAN8720**](examples/STM32_LAN8720/MQTTClient_Basic_LAN8720)
 7. [**MQTT_ThingStream_LAN8720**](examples/STM32_LAN8720/MQTT_ThingStream_LAN8720)
 8. [PostServer_LAN8720](examples/STM32_LAN8720/PostServer_LAN8720)
 9. [SimpleAuthentication_LAN8720](examples/STM32_LAN8720/SimpleAuthentication_LAN8720)
10. [UdpNTPClient_LAN8720](examples/STM32_LAN8720/UdpNTPClient_LAN8720)
11. [UdpSendReceive_LAN8720](examples/STM32_LAN8720/UdpSendReceive_LAN8720)
12. [WebClient_LAN8720](examples/STM32_LAN8720/WebClient_LAN8720)
13. [WebClientRepeating_LAN8720](examples/STM32_LAN8720/WebClientRepeating_LAN8720)
14. [WebServer_LAN8720](examples/STM32_LAN8720/WebServer_LAN8720)

#### LAN8720 HTTP and WebSocket Client New Examples

 1. [BasicAuthGet_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/BasicAuthGet_LAN8720)
 2. [CustomHeader_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/CustomHeader_LAN8720)
 3. [DweetGet_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/DweetGet_LAN8720)
 4. [DweetPost_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/DweetPost_LAN8720)
 5. [HueBlink_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/HueBlink_LAN8720)
 6. [node_test_server](examples/STM32_LAN8720/HTTPClient_LAN8720/node_test_server)
 7. [PostWithHeaders_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/PostWithHeaders_LAN8720)
 8. [SimpleDelete_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimpleDelete_LAN8720)
 9. [SimpleGet_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimpleGet_LAN8720)
10. [SimpleHTTPExample_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimpleHTTPExample_LAN8720)
11. [SimplePost_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimplePost_LAN8720)
12. [SimplePut_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimplePut_LAN8720)
13. [SimpleWebSocket_LAN8720](examples/STM32_LAN8720/HTTPClient_LAN8720/SimpleWebSocket_LAN8720)
    
---
---

### Example [AdvancedWebServer](examples/AdvancedWebServer)

#### 1. File [AdvancedWebServer.ino](examples/AdvancedWebServer/AdvancedWebServer.ino)


```cpp
/*
   Currently support
   1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet, 
      - See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running ENC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   3) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 shields
*/

#include "defines.h"

EthernetWebServer server(80);

const int led = 13;

void handleRoot()
{
  digitalWrite(led, 1);

#define BUFFER_SIZE     400

  char temp[BUFFER_SIZE];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  hr = hr % 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='5'/>\
<title>AdvancedWebServer %s</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h2>Hi from EthernetWebServer!</h2>\
<h3>on %s</h3>\
<p>Uptime: %d d %02d:%02d:%02d</p>\
<img src=\"/test.svg\" />\
</body>\
</html>", BOARD_NAME, BOARD_NAME, day, hr % 24, min % 60, sec % 60);

  server.send(200, "text/html", temp);

  digitalWrite(led, 0);
}

void handleNotFound()
{
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void drawGraph()
{
  String out;
  out.reserve(3000);
  char temp[70];
  out += "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n";
  out += "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"1\" stroke=\"rgb(0, 0, 0)\" />\n";
  out += "<g stroke=\"black\">\n";
  int y = rand() % 130;

  for (int x = 10; x < 300; x += 10)
  {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"1\" />\n", x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n</svg>\n";

  server.send(200, "image/svg+xml", out);
}

void setup(void)
{
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  Serial.begin(115200);
  Serial.println("\nStart AdvancedWebServer on " + String(BOARD_NAME) + ", using " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));

  #if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
    // For other boards, to change if necessary
    #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
      // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
      Ethernet.init (USE_THIS_SS_PIN);
    
    #elif USE_ETHERNET3
      // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
      #ifndef ETHERNET3_MAX_SOCK_NUM
        #define ETHERNET3_MAX_SOCK_NUM      4
      #endif
    
      Ethernet.setCsPin (USE_THIS_SS_PIN);
      Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
  
    #elif USE_CUSTOM_ETHERNET
      // You have to add initialization for your Custom Ethernet here
      // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
      //Ethernet.init(USE_THIS_SS_PIN);
      
    #endif  //( ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
  #endif
  
  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  server.on("/", handleRoot);
  server.on("/test.svg", drawGraph);
  server.on("/inline", []()
  {
    server.send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);
  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(Ethernet.localIP());
}

void loop(void)
{
  server.handleClient();
}
```

#### 2. File [defines.h](examples/AdvancedWebServer/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#if !( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
  #error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.
#endif

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       2

// If USE_BUILTIN_ETHERNET == false and USE_UIP_ETHERNET == false => 
// either use W5x00 with EthernetXYZ library
// or ENC28J60 with EthernetENC library
//#define USE_BUILTIN_ETHERNET    true
#define USE_BUILTIN_ETHERNET    false

//#define USE_UIP_ETHERNET        true
#define USE_UIP_ETHERNET        false

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
// Default pin 10 to SS/CS. To change according to your board, if necessary
#define USE_THIS_SS_PIN       10

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one if the following to be true
  #define USE_ETHERNET          false //true
  #define USE_ETHERNET2         false //true
  #define USE_ETHERNET3         false //true
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false //true
  #define USE_ETHERNET_ENC      true
  #define USE_CUSTOM_ETHERNET   false
#endif

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
  #ifdef USE_CUSTOM_ETHERNET
    #undef USE_CUSTOM_ETHERNET
  #endif
  #define USE_CUSTOM_ETHERNET   false //true
#endif

#if (USE_BUILTIN_ETHERNET)
  #warning Using LAN8742A Ethernet & STM32Ethernet lib
  #define SHIELD_TYPE           "LAN8742A Ethernet & STM32Ethernet Library"
#elif (USE_UIP_ETHERNET)
  #warning Using ENC28J60 & UIPEthernet lib
  #define SHIELD_TYPE           "ENC28J60 & UIPEthernet Library"
#elif USE_ETHERNET3
  #include "Ethernet3.h"
  #warning Using W5x00 & Ethernet3 lib
  #define SHIELD_TYPE           "W5x00 & Ethernet3 Library"
#elif USE_ETHERNET2
  #include "Ethernet2.h"
  #warning Using W5x00 & Ethernet2 lib
  #define SHIELD_TYPE           "W5x00 & Ethernet2 Library"
#elif USE_ETHERNET_LARGE
  #include "EthernetLarge.h"
  #warning Using W5x00 & EthernetLarge lib
  #define SHIELD_TYPE           "W5x00 & EthernetLarge Library"
#elif USE_ETHERNET_ESP8266
  #include "Ethernet_ESP8266.h"
  #warning Using W5x00 & Ethernet_ESP8266 lib 
  #define SHIELD_TYPE           "W5x00 & Ethernet_ESP8266 Library" 
#elif USE_ETHERNET_ENC
  #include "EthernetENC.h"
  #warning Using ENC28J60 & EthernetENC lib
  #define SHIELD_TYPE           "ENC28J60 & EthernetENC Library"
#elif USE_CUSTOM_ETHERNET
  //#include "Ethernet_XYZ.h"
  #include "EthernetENC.h"
  #warning Using Custom Ethernet library. You must include a library and initialize.
  #define SHIELD_TYPE           "Custom Ethernet & Ethernet_XYZ Library"
#else
  #define USE_ETHERNET          true
  #include "Ethernet.h"
  #warning Using Ethernet lib
  #define SHIELD_TYPE           "W5x00 & Ethernet Library"
#endif

#if defined(STM32F0)
  #warning STM32F0 board selected
  #define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
  #warning STM32F1 board selected
  #define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
  #warning STM32F2 board selected
  #define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
  #warning STM32F3 board selected
  #define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
  #warning STM32F4 board selected
  #define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
  #warning STM32F7 board selected
  #define BOARD_TYPE  "STM32F7"
#elif defined(STM32L0)
  #warning STM32L0 board selected
  #define BOARD_TYPE  "STM32L0"
#elif defined(STM32L1)
  #warning STM32L1 board selected
  #define BOARD_TYPE  "STM32L1"
#elif defined(STM32L4)
  #warning STM32L4 board selected
  #define BOARD_TYPE  "STM32L4"
#elif defined(STM32H7)
  #warning STM32H7 board selected
  #define BOARD_TYPE  "STM32H7"
#elif defined(STM32G0)
  #warning STM32G0 board selected
  #define BOARD_TYPE  "STM32G0"
#elif defined(STM32G4)
  #warning STM32G4 board selected
  #define BOARD_TYPE  "STM32G4"
#elif defined(STM32WB)
  #warning STM32WB board selected
  #define BOARD_TYPE  "STM32WB"
#elif defined(STM32MP1)
  #warning STM32MP1 board selected
  #define BOARD_TYPE  "STM32MP1"
#else
  #warning STM32 unknown board selected
  #define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#include <EthernetWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
};
// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 232);

#endif    //defines_h
```

---
---

### Debug Terminal Output Samples

#### 1. AdvancedWebServer on NUCLEO_F767ZI using Built-in LAN8742A Ethernet and STM32Ethernet Library

Following is debug terminal output and screen shot when running example [AdvancedWebServer](examples/AdvancedWebServer) on STM32F7 Nucleo-144 NUCLEO_F767ZI using Built-in LAN8742A Ethernet and STM32Ethernet Library

<p align="center">
    <img src="https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/pics/AdvancedWebServer.png">
</p>

```
Start AdvancedWebServer on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
HTTP EthernetWebServer is @ IP : 192.168.2.117
EthernetWebServer::handleClient: New Client
method:  GET
url:  /
search:
headerName: Host
headerValue: 192.168.2.150
headerName: Connection
headerValue: keep-alive
headerName: Cache-Control
headerValue: max-age=0
headerName: DNT
headerValue: 1
headerName: Upgrade-Insecure-Requests
headerValue: 1
headerName: User-Agent
headerValue: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36
headerName: Accept
headerValue: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
headerName: Accept-Encoding
headerValue: gzip, deflate
headerName: Accept-Language
headerValue: en-GB,en-US;q=0.9,en;q=0.8
args:
args count:  0
args:
args count:  0
Request: /
Arguments: 
Final list of key/value pairs:
EthernetWebServer::_handleRequest handle
EthernetWebServer::send1: len =  341
content =  <html><head><meta http-equiv='refresh' content='5'/><title>AdvancedWebServer NUCLEO_F767ZI</title><style>body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style></head><body><h2>Hi from EthernetWebServer!</h2><h3>on NUCLEO_F767ZI</h3><p>Uptime: 0 d 00:00:31</p><img src="/test.svg" /></body></html>
EthernetWebServer::_prepareHeader sendHeader Conn close
EthernetWebServer::send1: write header =  HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 341
Connection: close

EthernetWebServer::sendContent: Client.write content:  <html><head><meta http-equiv='refresh' content='5'/><title>AdvancedWebServer NUCLEO_F767ZI</title><style>body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style></head><body><h2>Hi from EthernetWebServer!</h2><h3>on NUCLEO_F767ZI</h3><p>Uptime: 0 d 00:00:31</p><img src="/test.svg" /></body></html>
EthernetWebServer::_handleRequest OK
EthernetWebServer::handleClient: Don't keepCurrentClient
EthernetWebServer::handleClient: Client disconnected
EthernetWebServer::handleClient: New Client
method:  GET
url:  /test.svg
search:
headerName: Host
headerValue: 192.168.2.150
headerName: Connection
headerValue: keep-alive
headerName: User-Agent
headerValue: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36
headerName: DNT
headerValue: 1
headerName: Accept
headerValue: image/webp,image/apng,image/*,*/*;q=0.8
headerName: Referer
headerValue: http://192.168.2.150/
headerName: Accept-Encoding
headerValue: gzip, deflate
headerName: Accept-Language
headerValue: en-GB,en-US;q=0.9,en;q=0.8
args:
args count:  0
args:
args count:  0
Request: /test.svg
Arguments: 
Final list of key/value pairs:
EthernetWebServer::_handleRequest handle
EthernetWebServer::send1: len =  1949
content =  <svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="310" height="150">
<rect width="310" height="150" fill="rgb(250, 230, 210)" stroke-width="1" stroke="rgb(0, 0, 0)" />
<g stroke="black">
<line x1="10" y1="90" x2="20" y2="22" stroke-width="1" />
<line x1="20" y1="22" x2="30" y2="98" stroke-width="1" />
<line x1="30" y1="98" x2="40" y2="64" stroke-width="1" />
<line x1="40" y1="64" x2="50" y2="104" stroke-width="1" />
<line x1="50" y1="104" x2="60" y2="31" stroke-width="1" />
<line x1="60" y1="31" x2="70" y2="59" stroke-width="1" />
<line x1="70" y1="59" x2="80" y2="139" stroke-width="1" />
<line x1="80" y1="139" x2="90" y2="117" stroke-width="1" />
<line x1="90" y1="117" x2="100" y2="75" stroke-width="1" />
<line x1="100" y1="75" x2="110" y2="72" stroke-width="1" />
<line x1="110" y1="72" x2="120" y2="137" stroke-width="1" />
<line x1="120" y1="137" x2="130" y2="20" stroke-width="1" />
<line x1="130" y1="20" x2="140" y2="94" stroke-width="1" />
<line x1="140" y1="94" x2="150" y2="81" stroke-width="1" />
<line x1="150" y1="81" x2="160" y2="38" stroke-width="1" />
<line x1="160" y1="38" x2="170" y2="33" stroke-width="1" />
<line x1="170" y1="33" x2="180" y2="53" stroke-width="1" />
<line x1="180" y1="53" x2="190" y2="88" stroke-width="1" />
<line x1="190" y1="88" x2="200" y2="32" stroke-width="1" />
<line x1="200" y1="32" x2="210" y2="110" stroke-width="1" />
<line x1="210" y1="110" x2="220" y2="87" stroke-width="1" />
<line x1="220" y1="87" x2="230" y2="11" stroke-width="1" />
<line x1="230" y1="11" x2="240" y2="98" stroke-width="1" />
<line x1="240" y1="98" x2="250" y2="76" stroke-width="1" />
<line x1="250" y1="76" x2="260" y2="121" stroke-width="1" />
<line x1="260" y1="121" x2="270" y2="139" stroke-width="1" />
<line x1="270" y1="139" x2="280" y2="103" stroke-width="1" />
<line x1="280" y1="103" x2="290" y2="60" stroke-width="1" />
<line x1="290" y1="60" x2="300" y2="36" stroke-width="1" />
</g>
</svg>

EthernetWebServer::_prepareHeader sendHeader Conn close
EthernetWebServer::send1: write header =  HTTP/1.1 200 OK
Content-Type: image/svg+xml
Content-Length: 1949
Connection: close

```

---

#### 2. WebClientRepeating on NUCLEO_F767ZI using ENC28J60 and new EthernetENC Library

The following is debug terminal output when running example [WebClientRepeating](examples/WebClientRepeating) on STM32F7 Nucleo-144 NUCLEO_F767ZI using **ENC28J60 and new EthernetENC Library**

```
Start WebClientRepeating on NUCLEO_F767ZI, using ENC28J60 & EthernetENC Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.123

Connecting...
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Wed, 16 Sep 2020 22:17:04 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;; 
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;

Disconnecting from server...

```

---

#### 3. UdpNTPClient on NUCLEO_F767ZI using W5500 and Ethernet2 Library

The following is debug terminal output when running example [UdpNTPClient](examples/UdpNTPClient) on STM32F7 Nucleo-144 NUCLEO_F767ZI using **W5500 and Ethernet2 Library**

```
Start UdpNTPClient on NUCLEO_F767ZI, using W5x00 & Ethernet2 Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.123
UDP Packet received, size 48
From 132.163.97.1, port 123
Seconds since Jan 1 1900 = 3809283621
Unix time = 1600294821
The UTC time is 22:20:21
```

---

#### 4. SimpleWebSocket on NUCLEO_F767ZI using Built-in LAN8742A Ethernet and STM32Ethernet Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library** running [SimpleWebSocket example](examples/HTTPClient/SimpleWebSocket) to demonstrate newly-added WebSocket Client feature.

```
Starting SimpleWebSocket on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
=========================
Using mac index = 10
Connected! IP address: 192.168.2.139
starting WebSocket client
Sending Hello 0
Sending Hello 1
Received a message:
0 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 7297
Sending Hello 2
Received a message:
1 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 12297
Sending Hello 3
Received a message:
2 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 17300
Sending Hello 4
Received a message:
3 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 22303
Sending Hello 5
Received a message:
4 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 27306
```

---

#### 5. SimpleWebSocket on NUCLEO_F767ZI using W5x00 and Ethernet3 Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with W5x00 & Ethernet3 Library** running [SimpleWebSocket example](examples/HTTPClient/SimpleWebSocket) to demonstrate newly-added WebSocket Client feature.

```
Starting SimpleWebSocket on NUCLEO_F767ZI with W5x00 & Ethernet3 Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET3 ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10

Ethernet3 W5500 init, using SPI_CS = 10, number of sockets = 10
=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
SPI_CS:10
=========================
Using mac index = 10
Connected! IP address: 192.168.2.139
starting WebSocket client
Sending Hello 0
Sending Hello 1
Received a message:
0 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 2390
Sending Hello 2
Received a message:
1 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 7391
Sending Hello 3
Received a message:
2 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 12399
Sending Hello 4
Received a message:
3 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 17407
Sending Hello 5
Received a message:
4 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 22416
Sending Hello 6
Received a message:
5 => Hello from SimpleWebSocket on NUCLEO_F767ZI, millis = 27425
```

---

#### 6. SimpleHTTPExample on NUCLEO_F767ZI using Built-in LAN8742A Ethernet and STM32Ethernet Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library** running [SimpleHTTPExample example](examples/HTTPClient/SimpleHTTPExample) to demonstrate newly-added HTTP Client feature.


```
Starting SimpleHTTPExample on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
=========================
Using mac index = 10
Connected! IP address: 192.168.2.139
startedRequest ok
Got status code: 200
Content length is: 2263

Body returned follows:

           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;   
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;  
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;  
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;  
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;  
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;   
```

---

#### 7. MQTTClient_Auth on NUCLEO_F767ZI using Built-in LAN8742A Ethernet and STM32Ethernet Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library** running [MQTTClient_Auth example](examples/MQTTClient_Auth) to demonstrate newly-added HTTP Client feature.

```
Start MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
=========================
Using mac index = 13
Connected! IP address: 192.168.2.152
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
```

---

#### 8. MQTTClient_Auth on NUCLEO_F767ZI using ENC28J60 and EthernetENC Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with ENC28J60 & EthernetENC Library** running [MQTTClient_Auth example](examples/MQTTClient_Auth) to demonstrate newly-added HTTP Client feature.

```
Start MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_ENC ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
C=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
=========================
Using mac index = 13
Connected! IP address: 192.168.2.152
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with ENC28J60 & EthernetENC Library
```

---

#### 9. MQTTClient_Auth on NUCLEO_F767ZI using W5x00 and Ethernet2 Library

The terminal output of **STM32F7 Nucleo-144 NUCLEO_F767ZI with W5x00 & Ethernet2 Library** running [MQTTClient_Auth example](examples/MQTTClient_Auth) to demonstrate newly-added HTTP Client feature.

```
Start MQTTClient_Auth on NUCLEO_F767ZI with W5x00 & Ethernet2 Library
EthernetWebServer_STM32 v1.2.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET2 ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:11
MISO:12
SCK:13
SS:10
=========================
Using mac index = 12
Connected! IP address: 192.168.2.78
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with W5x00 & Ethernet2 Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with W5x00 & Ethernet2 Library
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on NUCLEO_F767ZI with W5x00 & Ethernet2 Library
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on NUCLEO_F767ZI with W5x00 & Ethernet2 Library

```

---

#### 10. SimpleWebSocket_LAN8720 on BLACK_F407VE using LAN8720 Ethernet and STM32Ethernet Library

The terminal output of **STM32F4 BLACK_F407VE with LAN8720 Ethernet and STM32Ethernet Library** running [SimpleWebSocket_LAN8720 example](examples/STM32_LAN8720/SimpleWebSocket_LAN8720) to demonstrate newly-added HTTP Client feature.

```
Starting SimpleWebSocket_LAN8720 on BLACK_F407VE with LAN8720 Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
Using mac index = 6
Connected! IP address: 192.168.2.138
starting WebSocket client
disconnected
starting WebSocket client
Sending Hello 0
Sending Hello 1
Received a message:
0 => Hello from SimpleWebSocket on BLACK_F407VE using LAN8720, millis = 16685
Sending Hello 2
Received a message:
1 => Hello from SimpleWebSocket on BLACK_F407VE using LAN8720, millis = 21685
Sending Hello 3
Received a message:
2 => Hello from SimpleWebSocket on BLACK_F407VE using LAN8720, millis = 26690
```

#### 11. WebClient_LAN8720 on BLACK_F407VE using LAN8720 Ethernet and STM32Ethernet Library

The terminal output of **BLACK_F407VE using LAN8720 Ethernet and STM32Ethernet Library** running [WebClient_LAN8720 example](examples/STM32_LAN8720/WebClient_LAN8720) to demonstrate newly-added HTTP Client feature.


```
Start WebClient_LAN8720 on BLACK_F407VE, using LAN8720 Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
You're connected to the network, IP = 192.168.2.139

Starting connection to server...
Connected to server
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Sun, 11 Apr 2021 04:37:16 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;   
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;  
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;  
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;  
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;  
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;   

Disconnecting from server... 
```

---

#### 12. AdvancedWebServer_LAN8720 on BLACK_F407VE, using LAN8720 Ethernet and STM32Ethernet Library

Following is debug terminal output and screen shot when running example [AdvancedWebServer_LAN8720](examples/STM32_LAN8720/AdvancedWebServer_LAN8720) on BLACK_F407VE, using LAN8720 Ethernet and STM32Ethernet Library

<p align="center">
    <img src="https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/pics/AdvancedWebServer_LAN8720.png">
</p>


```
Start AdvancedWebServer_LAN8720 on BLACK_F407VE, using LAN8720 Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.2.0
HTTP EthernetWebServer is @ IP : 192.168.2.138

```

---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _ETHERNET_WEBSERVER_LOGLEVEL_ to 0

```cpp
// Use this to output debug msgs to Serial
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial
// Use this to disable all output debug msgs
// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       0
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, applying Libraries' Patches, Packages' Patches or this library latest version.

---
---

## Releases

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

#### Major Releases v1.0.5

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

### Releases v1.0.3

1. Fix bug not closing client and releasing socket.
2. Merge new features from latest ESP8266WebServer
3. Add and enhance examples.
4. Restore dependency to [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).

### Releases v1.0.2

1. Remove dependendy on [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).
2. Enhance examples and update README.md

### Releases v1.0.1

1. Add support to W5x00 Ethernet shields to all STM32 boards having 64+K bytes Flash.

### Releases v1.0.0

This is simple yet complete WebServer library for `STM32` boards running built-in Ethernet (Nucleo-144, Discovery) or EMC28J60 Ethernet shields. **The functions are similar and compatible to ESP8266/ESP32 WebServer libraries** to make life much easier to port sketches from ESP8266/ESP32.

---

#### Supported Boards

1. **STM32 boards with built-in Ethernet LAN8742A** such as :

  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet**
  - See [EthernetWebServer_STM32 Support and Test Results](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
  
2. **STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 or ENC28J60 shields)**

- Nucleo-144
- Nucleo-64
- Discovery
- Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
- STM32L0, STM32L1, STM32L4
- STM32G0, STM32G4
- STM32H7
- STM32WB
- STM32MP1
- LoRa boards
- 3-D printer boards
- Generic Flight Controllers
- Midatronics boards

3. **STM32 boards using Ethernet LAN8720** such as :

  - **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
  - **Discovery (DISCO_F746NG)**
  - **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

#### Supported Ethernet shields/modules

1. W5x00 using [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge), [`Ethernet2`](https://github.com/adafruit/Ethernet2) or [`Ethernet3`](https://github.com/sstaub/Ethernet3) library

2. ENC28J60 using new [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library

3. LAN8720 using new [`STM32Ethernet`](https://github.com/stm32duino/STM32Ethernet) and [`LwIP`](https://github.com/stm32duino/LwIP) libraries.


#### Not supported boards

These boards are not supported:

- Some Nucleo-32 (small Flash/memory)
- Eval (no Serial, just need to redefine in sketch, library and UIPEthernet)
- Generic STM32F0 (small Flash/memory)
- Generic STM32F1 (with 64-K Flash): C6
- Generic STM32F3 : no HardwareSPI.h
- Electronics Speed Controllers (small Flash/memory)

---
---

### Issues ###

Submit issues to: [EthernetWebServer_STM32 issues](https://github.com/khoih-prog/EthernetWebServer_STM32/issues)

---

### TO DO

1. Bug Searching and Killing
2. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
3. Add mDNS features.
4. Use AsyncTCP features from [Phil Bowles' STM32AsyncTCP](https://github.com/philbowles/STM32AsyncTCP).

### DONE

 1. Add support to **STM32F1,2,3,4,7 boards** with 64K+ Flash.
 2. Add support to **built-in Ethernet LAN8742A** using [STM32Ethernet library](https://github.com/stm32duino/STM32Ethernet), for boards such as Nucleo-144 NUCLEO_F767ZI.
 3. Add support to **Ethernet W5x00**, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/khoih-prog/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 4. Add support to Ethernet **ENC28J60**, using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library 
 5. Add support to all STM32 boards (**STM32F/L/H/G/WB/MP1**) with 32K+ Flash.
 6. Add **High-level HTTP (GET, POST, PUT, PATCH, DELETE) and WebSocket Client**
 7. Add SSL/TLS Server support in [EthernetWebServer_SSL_STM32](https://github.com/khoih-prog/EthernetWebServer_SSL_STM32)
 8. Add support to **Ethernet LAN8720** using [STM32Ethernet library](https://github.com/stm32duino/STM32Ethernet), for boards such as **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG), Discovery (DISCO_F746NG)** and **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**
 
---

### Contributions and Thanks

1. Based on and modified from [Ivan Grokhotkov's ESP8266WebServer](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
2. [Juraj Andrássy](https://github.com/jandrassy) for [`EthernetENC`](https://github.com/jandrassy/EthernetENC) and [UIPEthernet library](https://github.com/UIPEthernet/UIPEthernet)
3. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) to help debug and test.
4. Thanks to [Aron N.](https://github.com/porkyneal) to initiate [Sending GZIP HTML ~ 120kb+ (suggested enhancement)](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/3), to help code and test the solution, to add support to PROGMEM-related commands, such as sendContent_P() and send_P(), leading to v1.0.6.
5. [Adrian McEwen](https://github.com/amcewen) for [HttpClient Library](https://github.com/amcewen/HttpClient) on which the [ArduinoHttpClient Library](https://github.com/arduino-libraries/ArduinoHttpClient) and this [EthernetWebServer library](https://github.com/khoih-prog/EthernetWebServer) are relied.


<table>
  <tr>
    <td align="center"><a href="https://github.com/igrr"><img src="https://github.com/igrr.png" width="100px;" alt="igrr"/><br /><sub><b>⭐️ Ivan Grokhotkov</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/amcewen"><img src="https://github.com/amcewen.png" width="100px;" alt="amcewen"/><br /><sub><b>⭐️ Adrian McEwen</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jandrassy"><img src="https://github.com/jandrassy.png" width="100px;" alt="jandrassy"/><br /><sub><b>⭐️ Juraj Andrássy</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/porkyneal"><img src="https://github.com/porkyneal.png" width="100px;" alt="porkyneal"/><br /><sub><b>⭐️ Aron N.</b></sub></a><br /></td>
  </tr> 
</table>

---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang


