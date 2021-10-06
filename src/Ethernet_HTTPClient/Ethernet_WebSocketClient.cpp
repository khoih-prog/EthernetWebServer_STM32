/****************************************************************************************************************************
   Ethernet_WebSocketClient.cpp - Dead simple HTTP WebSockets Client.
   For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

   EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

   Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
   Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
   Licensed under MIT license
   
   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov
   
   Version: 1.2.1

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
    1.0.3   K Hoang      22/07/2020 Fix bug not closing client and releasing socket. Add features.
    1.0.4   K Hoang      23/07/2020 Add support to all STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash.
    1.0.5   K Hoang      16/09/2020 Add support to Ethernet2, Ethernet3, Ethernet Large for W5x00
                                    Add support to new EthernetENC library for ENC28J60. Add debug feature.
    1.0.6   K Hoang      24/09/2020 Add support to PROGMEM-related commands, such as sendContent_P() and send_P()
    1.1.0   K Hoang      17/11/2020 Add basic HTTP and WebSockets Client by merging ArduinoHttpClient
    1.1.1   K Hoang      26/12/2020 Suppress all possible compiler warnings. Add Version String
    1.2.0   K Hoang      11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
    1.2.1   K Hoang      04/10/2021 Change option for PIO `lib_compat_mode` from default `soft` to `strict`. Update Packages Patches
 *************************************************************************************************************************************/
 
// (c) Copyright Arduino. 2016
// Released under Apache License, version 2.0

#define _ETHERNET_WEBSERVER_LOGLEVEL_     0

#include "libb64/base64.h"

#include "detail/Debug_STM32.h"
#include "Ethernet_HTTPClient/Ethernet_WebSocketClient.h"

EthernetWebSocketClient::EthernetWebSocketClient(Client& aClient, const char* aServerName, uint16_t aServerPort)
  : EthernetHttpClient(aClient, aServerName, aServerPort),
    iTxStarted(false),
    iRxSize(0)
{
}

EthernetWebSocketClient::EthernetWebSocketClient(Client& aClient, const String& aServerName, uint16_t aServerPort)
  : EthernetHttpClient(aClient, aServerName, aServerPort),
    iTxStarted(false),
    iRxSize(0)
{
}

EthernetWebSocketClient::EthernetWebSocketClient(Client& aClient, const IPAddress& aServerAddress, uint16_t aServerPort)
  : EthernetHttpClient(aClient, aServerAddress, aServerPort),
    iTxStarted(false),
    iRxSize(0)
{
}

int EthernetWebSocketClient::begin(const char* aPath)
{
  // start the GET request
  beginRequest();
  connectionKeepAlive();
  
  int status = get(aPath);

  if (status == 0)
  {
    uint8_t randomKey[16];
    char base64RandomKey[25];

    // create a random key for the connection upgrade
    for (int i = 0; i < (int)sizeof(randomKey); i++)
    {
      randomKey[i] = random(0x01, 0xff);
    }
    
    memset(base64RandomKey, 0x00, sizeof(base64RandomKey));
    base64_encode(randomKey, sizeof(randomKey), (unsigned char*)base64RandomKey, sizeof(base64RandomKey));

    // start the connection upgrade sequence
    sendHeader("Upgrade", "websocket");
    sendHeader("Connection", "Upgrade");
    sendHeader("Sec-WebSocket-Key", base64RandomKey);
    sendHeader("Sec-WebSocket-Version", "13");
    endRequest();

    status = responseStatusCode();

    if (status > 0)
    {
      skipResponseHeaders();
    }
  }

  iRxSize = 0;

  // status code of 101 means success
  return (status == 101) ? 0 : status;
}

int EthernetWebSocketClient::begin(const String& aPath)
{
  return begin(aPath.c_str());
}

int EthernetWebSocketClient::beginMessage(int aType)
{
  if (iTxStarted)
  {
    // fail TX already started
    return 1;
  }

  iTxStarted = true;
  iTxMessageType = (aType & 0xf);
  iTxSize = 0;

  return 0;
}

int EthernetWebSocketClient::endMessage()
{
  if (!iTxStarted)
  {
    // fail TX not started
    return 1;
  }

  // send FIN + the message type (opcode)
  EthernetHttpClient::write(0x80 | iTxMessageType);

  // the message is masked (0x80)
  // send the length
  if (iTxSize < 126)
  {
    EthernetHttpClient::write(0x80 | (uint8_t)iTxSize);
  }
  else if (iTxSize < 0xffff)
  {
    EthernetHttpClient::write(0x80 | 126);
    EthernetHttpClient::write((iTxSize >> 8) & 0xff);
    EthernetHttpClient::write((iTxSize >> 0) & 0xff);
  }
  else
  {
    EthernetHttpClient::write(0x80 | 127);
    EthernetHttpClient::write((iTxSize >> 56) & 0xff);
    EthernetHttpClient::write((iTxSize >> 48) & 0xff);
    EthernetHttpClient::write((iTxSize >> 40) & 0xff);
    EthernetHttpClient::write((iTxSize >> 32) & 0xff);
    EthernetHttpClient::write((iTxSize >> 24) & 0xff);
    EthernetHttpClient::write((iTxSize >> 16) & 0xff);
    EthernetHttpClient::write((iTxSize >>  8) & 0xff);
    EthernetHttpClient::write((iTxSize >>  0) & 0xff);
  }

  uint8_t maskKey[4];

  // create a random mask for the data and send
  for (int i = 0; i < (int)sizeof(maskKey); i++)
  {
    maskKey[i] = random(0xff);
  }
  
  EthernetHttpClient::write(maskKey, sizeof(maskKey));

  // mask the data and send
  for (int i = 0; i < (int)iTxSize; i++) 
  {
    iTxBuffer[i] ^= maskKey[i % sizeof(maskKey)];
  }

  size_t txSize = iTxSize;

  iTxStarted = false;
  iTxSize = 0;

  return (EthernetHttpClient::write(iTxBuffer, txSize) == txSize) ? 0 : 1;
}

size_t EthernetWebSocketClient::write(uint8_t aByte)
{
  return write(&aByte, sizeof(aByte));
}

size_t EthernetWebSocketClient::write(const uint8_t *aBuffer, size_t aSize)
{
  if (iState < eReadingBody)
  {
    // have not upgraded the connection yet
    return EthernetHttpClient::write(aBuffer, aSize);
  }

  if (!iTxStarted)
  {
    // fail TX not   started
    return 0;
  }

  // check if the write size, fits in the buffer
  if ((iTxSize + aSize) > sizeof(iTxBuffer))
  {
    aSize = sizeof(iTxSize) - iTxSize;
  }

  // copy data into the buffer
  memcpy(iTxBuffer + iTxSize, aBuffer, aSize);

  iTxSize += aSize;

  return aSize;
}

int EthernetWebSocketClient::parseMessage()
{
  flushRx();

  // make sure 2 bytes (opcode + length)
  // are available
  if (EthernetHttpClient::available() < 2)
  {
    return 0;
  }

  // read open code and length
  uint8_t opcode = EthernetHttpClient::read();
  int length = EthernetHttpClient::read();

  if ((opcode & 0x0f) == 0)
  {
    // continuation, use previous opcode and update flags
    iRxOpCode |= opcode;
  }
  else
  {
    iRxOpCode = opcode;
  }

  iRxMasked = (length & 0x80);
  length   &= 0x7f;

  // read the RX size
  if (length < 126)
  {
    iRxSize = length;
  }
  else if (length == 126)
  {
    iRxSize = (EthernetHttpClient::read() << 8) | EthernetHttpClient::read();
  }
  else
  {
    iRxSize =   ((uint64_t)EthernetHttpClient::read() << 56) |
                ((uint64_t)EthernetHttpClient::read() << 48) |
                ((uint64_t)EthernetHttpClient::read() << 40) |
                ((uint64_t)EthernetHttpClient::read() << 32) |
                ((uint64_t)EthernetHttpClient::read() << 24) |
                ((uint64_t)EthernetHttpClient::read() << 16) |
                ((uint64_t)EthernetHttpClient::read() << 8)  |
                (uint64_t)EthernetHttpClient::read();
  }

  // read in the mask, if present
  if (iRxMasked)
  {
    for (int i = 0; i < (int)sizeof(iRxMaskKey); i++)
    {
      iRxMaskKey[i] = EthernetHttpClient::read();
    }
  }

  iRxMaskIndex = 0;

  if (TYPE_CONNECTION_CLOSE == messageType())
  {
    flushRx();
    stop();
    iRxSize = 0;
  }
  else if (TYPE_PING == messageType())
  {
    beginMessage(TYPE_PONG);
    
    while (available())
    {
      write(read());
    }
    
    endMessage();

    iRxSize = 0;
  }
  else if (TYPE_PONG == messageType())
  {
    flushRx();
    iRxSize = 0;
  }

  return iRxSize;
}

int EthernetWebSocketClient::messageType()
{
  return (iRxOpCode & 0x0f);
}

bool EthernetWebSocketClient::isFinal()
{
  return ((iRxOpCode & 0x80) != 0);
}

String EthernetWebSocketClient::readString()
{
  int avail = available();
  String s;

  if (avail > 0)
  {
    s.reserve(avail);

    for (int i = 0; i < avail; i++)
    {
      s += (char)read();
    }
  }

  return s;
}

int EthernetWebSocketClient::ping()
{
  uint8_t pingData[16];

  // create random data for the ping
  for (int i = 0; i < (int)sizeof(pingData); i++)
  {
    pingData[i] = random(0xff);
  }

  beginMessage(TYPE_PING);
  write(pingData, sizeof(pingData));
  
  return endMessage();
}

int EthernetWebSocketClient::available()
{
  if (iState < eReadingBody)
  {
    return EthernetHttpClient::available();
  }

  return iRxSize;
}

int EthernetWebSocketClient::read()
{
  byte b;

  if (read(&b, sizeof(b)))
  {
    return b;
  }

  return -1;
}

int EthernetWebSocketClient::read(uint8_t *aBuffer, size_t aSize)
{
  int readCount = EthernetHttpClient::read(aBuffer, aSize);

  if (readCount > 0)
  {
    iRxSize -= readCount;

    // unmask the RX data if needed
    if (iRxMasked)
    {
      for (int i = 0; i < (int)aSize; i++, iRxMaskIndex++)
      {
        aBuffer[i] ^= iRxMaskKey[iRxMaskIndex % sizeof(iRxMaskKey)];
      }
    }
  }

  return readCount;
}

int EthernetWebSocketClient::peek()
{
  int p = EthernetHttpClient::peek();

  if (p != -1 && iRxMasked)
  {
    // unmask the RX data if needed
    p = (uint8_t)p ^ iRxMaskKey[iRxMaskIndex % sizeof(iRxMaskKey)];
  }

  return p;
}

void EthernetWebSocketClient::flushRx()
{
  while (available())
  {
    read();
  }
}
