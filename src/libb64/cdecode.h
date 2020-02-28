/****************************************************************************************************************************
 * cdecode.h - c header for a base64 decoding algorithm
 * 
 * This is part of the libb64 project, and has been placed in the public domain.
 * For details, see http://sourceforge.net/projects/libb64
 *
 * EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer
 *
 * Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
 * Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
 * Licensed under MIT license
 * Version: 1.0.1
 *
 * Original author:
 * @file       Esp8266WebServer.h
 * @author     Ivan Grokhotkov
 *
 * Version Modified By   Date      Comments
 * ------- -----------  ---------- -----------
 *  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
 *  1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
 *****************************************************************************************************************************/

#ifndef BASE64_CDECODE_H
#define BASE64_CDECODE_H

#define base64_decode_expected_len(n) ((n * 3) / 4)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  step_a, step_b, step_c, step_d
} base64_decodestep;

typedef struct {
  base64_decodestep step;
  char plainchar;
} base64_decodestate;

void base64_init_decodestate(base64_decodestate* state_in);

int base64_decode_value(char value_in);

int base64_decode_block(const char* code_in, const int length_in, char* plaintext_out, base64_decodestate* state_in);

int base64_decode_chars(const char* code_in, const int length_in, char* plaintext_out);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* BASE64_CDECODE_H */
