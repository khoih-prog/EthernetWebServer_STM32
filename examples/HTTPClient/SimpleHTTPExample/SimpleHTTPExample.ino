/****************************************************************************************************************************
  SimpleHTTPExample.ino - Simple Arduino web server sample for Ethernet shield

  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Simple example to show how to use the HttpClient library
  Get's the web page given at http://<kHostname><kPath> and outputs the content to the serial port
 *****************************************************************************************************************************/

#include "defines.h"

// This example downloads the URL "http://arduino.cc/"
// Name of the server we want to connect to
const char kHostname[] = "arduino.tips";

// Path to download (this is the bit after the hostname in the URL
// that you want to download
const char kPath[] = "/asciilogo.txt";

// Number of milliseconds to wait without receiving any data before we give up
#define NETWORK_TIMEOUT_MS      30000L

// Number of milliseconds to wait if no data is available before trying again
#define NETWORK_RETRY_MS        1000L

EthernetClient      client;
EthernetHttpClient  httpClient(client, kHostname);

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStarting SimpleHTTPExample on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

#if USE_ETHERNET_GENERIC
  Serial.println(ETHERNET_GENERIC_VERSION);
#endif
  
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

#if !(USE_BUILTIN_ETHERNET)
  #if (USING_SPI2)
    #if defined(CUR_PIN_MISO)
      ET_LOGWARN(F("Default SPI pinout:"));
      ET_LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
      ET_LOGWARN1(F("MISO:"), CUR_PIN_MISO);
      ET_LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
      ET_LOGWARN1(F("SS:"),   CUR_PIN_SS);
      ET_LOGWARN(F("========================="));
    #endif
  #else
    ET_LOGWARN(F("Default SPI pinout:"));
    ET_LOGWARN1(F("MOSI:"), MOSI);
    ET_LOGWARN1(F("MISO:"), MISO);
    ET_LOGWARN1(F("SCK:"),  SCK);
    ET_LOGWARN1(F("SS:"),   SS);
    ET_LOGWARN(F("========================="));
  #endif
#endif

  #if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
    // For other boards, to change if necessary
    #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
      Ethernet.init (USE_THIS_SS_PIN);
      
    #elif USE_CUSTOM_ETHERNET
      // You have to add initialization for your Custom Ethernet here
      // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
      //Ethernet.init(USE_THIS_SS_PIN);
      
    #endif  //( ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
  #endif
  
  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);
  
  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());
}

void loop()
{
  int err = 0;

  err = httpClient.get(kPath);

  if (err == 0)
  {
    Serial.println("startedRequest ok");

    err = httpClient.responseStatusCode();

    if (err >= 0)
    {
      Serial.print("Got status code: ");
      Serial.println(err);

      // Usually you'd check that the response code is 200 or a
      // similar "success" code (200-299) before carrying on,
      // but we'll print out whatever response we get

      err = httpClient.skipResponseHeaders();

      if (err >= 0)
      {
        int bodyLen = httpClient.contentLength();
        Serial.print("Content length is: ");
        Serial.println(bodyLen);
        Serial.println();
        Serial.println("Body returned follows:");

        // Now we've got to the body, so we can print it out
        unsigned long timeoutStart = millis();

        // Whilst we haven't timed out & haven't reached the end of the body
        while ( (httpClient.connected() || httpClient.available()) &&
                ((millis() - timeoutStart) < NETWORK_TIMEOUT_MS) )
        {
          if (httpClient.available())
          {
            Serial.print((char) httpClient.read());

            bodyLen--;

            // We read something, reset the timeout counter
            timeoutStart = millis();
          }
          else
          {
            // We haven't got any data, so let's pause to allow some to
            // arrive
            delay(NETWORK_RETRY_MS);
          }
        }
      }
      else
      {
        Serial.print("Failed to skip response headers: ");
        Serial.println(err);
      }
    }
    else
    {
      Serial.print("Getting response failed: ");
      Serial.println(err);
    }
  }
  else
  {
    Serial.print("Connect failed: ");
    Serial.println(err);
  }

  httpClient.stop();

  // And just stop, now that we've tried a download
  while (1);
}
