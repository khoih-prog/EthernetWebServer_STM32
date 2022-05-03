/****************************************************************************************************************************
  cencoder.h - c source to a base64 decoding algorithm implementation
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Original author:
  @file       Esp8266WebServer.h
  @author     Ivan Grokhotkov

  Version: 1.5.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
  ...
  1.3.0   K Hoang      20/12/2021 Reduce usage of Arduino String with std::string. Use reference passing instead of value-passing
  1.3.1   K Hoang      25/12/2021 Fix bug
  1.3.2   K Hoang      28/12/2021 Fix wrong http status header bug and authenticate issue caused by libb64
  1.3.3   K Hoang      11/01/2022 Fix libb64 fallthrough compile warning
  1.3.4   K Hoang      02/03/2022 Fix decoding error bug
  1.4.0   K Hoang      04/04/2022 Use Ethernet_Generic library as default for W5x00 Ethernet
  1.4.1   K Hoang      27/04/2022 Change from `arduino.cc` to `arduino.tips` in examples
  1.5.0   K Hoang      04/04/2022 Add support to custom SPI, such as SPI2, SPI3, SPI_New, etc.
 *****************************************************************************************************************************/

#pragma once

// Reintroduce to prevent duplication compile error if other lib/core already has LIB64
// pragma once can't prevent that
#ifndef BASE64_CENCODE_H
#define BASE64_CENCODE_H

#define base64_encode_expected_len(n) ((((4 * n) / 3) + 3) & ~3)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
  step_A, step_B, step_C
} base64_encodestep;

typedef struct 
{
  base64_encodestep step;
  char result;
  int stepcount;
} base64_encodestate;

void base64_init_encodestate(base64_encodestate* state_in);

char base64_encode_value(char value_in);

int base64_encode_block(const char* plaintext_in, int length_in, char* code_out, base64_encodestate* state_in);

int base64_encode_blockend(char* code_out, base64_encodestate* state_in);

int base64_encode_chars(const char* plaintext_in, int length_in, char* code_out);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* BASE64_CENCODE_H */

