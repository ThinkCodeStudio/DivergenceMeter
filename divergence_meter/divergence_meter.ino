#include <NTPClient.h>
#include <WiFiManager.h>
#include <WiFiUdp.h>
#include <Ticker.h>
#include <WiFiClient.h>
#include <stdint.h>

#include "nixie_tube.h"
#include "tm6108.h"
#include "hc595.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define LOG(x) Serial.println(x)
#define LOGF(x, ...) Serial.printf(x, __VA_ARGS__)
#else
#define LOG(x)
#define LOGF(x, ...)
#endif

union u8buf {
  uint8_t u8;
  struct {
    uint8_t d0 : 1;
    uint8_t d1 : 1;
    uint8_t d2 : 1;
    uint8_t d3 : 1;
    uint8_t d4 : 1;
    uint8_t d5 : 1;
    uint8_t d6 : 1;
    uint8_t d7 : 1;
  } buf;
};

const uint8_t t0_pin = 4;

const uint8_t tc_pin = 5;
const uint8_t td_pin = 6;

const uint8_t hsck_pin = 7;
const uint8_t hsda_pin = 8;

const uint8_t sck_pin = 0;
const uint8_t rck_pin = 1;
const uint8_t data_pin = 2;

const uint8_t bat_pin = 3;

const uint8_t light_pin = 10;

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, "cn.ntp.org.cn", 60 * 60 * 8, 30 * 60 * 1000);

struct HC595Pins hc595Pins = {
  .RCK = rck_pin,
  .SCK = sck_pin,
  .DAT = data_pin
};
HC595 hc595(hc595Pins, 12);
NixieTube nixie(hc595);
TM6108 tm6108(tc_pin, td_pin);

void setNixieTubeEnum(NixieTubeEnum *sendState, NixieTubeEnum state, int size) {
  for (int i = 0; i < size; i++) {
    sendState[i] = state;
  }
}

void setup() {
  WiFiManager wifiManager;

  Serial.begin(115200);
  pinMode(t0_pin, INPUT);
  pinMode(light_pin, INPUT);
  wifiManager.autoConnect("DivergenceMeter");

  LOG(WiFi.softAPIP());
  LOG("");
}

void loop() {
  // union u8buf touch;
  // touch.u8 = tm6108.read();
  // LOGF("%d\n", touch.u8);
  NixieTubeEnum sendState[8] = { NixieTubeEnum_ZERO };
  // if (touch.buf.d0) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_ZERO, 8);
  // } else if (touch.buf.d1) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_ONE, 8);
  // } else if (touch.buf.d2) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_TWO, 8);
  // } else if (touch.buf.d3) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_THREE, 8);
  // } else if (touch.buf.d4) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_FOUR, 8);
  // } else if (touch.buf.d5) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_FIVE, 8);
  // } else if (touch.buf.d6) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_SIX, 8);
  // } else if (touch.buf.d7) {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_SEVEN, 8);
  // } else {
  //   setNixieTubeEnum(sendState, NixieTubeEnum_NONE, 8);
  // }

  static int count = 0;

  switch(count){
    case 0:
      setNixieTubeEnum(sendState, NixieTubeEnum_ZERO, 8);
      break;
    case 1:
      setNixieTubeEnum(sendState, NixieTubeEnum_ONE, 8);
      break;
    case 2:
      setNixieTubeEnum(sendState, NixieTubeEnum_TWO, 8);
      break;
    case 3:
      setNixieTubeEnum(sendState, NixieTubeEnum_THREE, 8);
      break;
    case 4:
      setNixieTubeEnum(sendState, NixieTubeEnum_FOUR, 8);
      break;
    case 5:
      setNixieTubeEnum(sendState, NixieTubeEnum_FIVE, 8);
      break;
    case 6:
      setNixieTubeEnum(sendState, NixieTubeEnum_SIX, 8);
      break;
    case 7:
      setNixieTubeEnum(sendState, NixieTubeEnum_SEVEN, 8);
      break;
    case 8:
      setNixieTubeEnum(sendState, NixieTubeEnum_EIGHT, 8);
      break;
    case 9:
      setNixieTubeEnum(sendState, NixieTubeEnum_NINE, 8);
      break;
    case 10:
      setNixieTubeEnum(sendState, NixieTubeEnum_LTDOT, 8);
      break;
    case 12:
      setNixieTubeEnum(sendState, NixieTubeEnum_RTDOT, 8);
      break;
  }

  nixie.show(sendState);
  count++;
  count%=13;
  delay(100);
}

/***
T0    ->4
TC    ->5
TD    ->6
HSCK  ->7
HSDA  ->8
SCK   ->0
RCK   ->1
DATA  ->2
BADC  ->3
DP    ->19
DN    ->18
TX
RX
LIGHT ->10
***/