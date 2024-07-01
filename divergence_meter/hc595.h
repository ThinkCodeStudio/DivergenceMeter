#pragma once
#include "Arduino.h"
#include "inttypes.h"

struct HC595Pins {
  uint8_t RCK;
  uint8_t SCK;
  uint8_t DAT;
};

class HC595 {
private:
  struct HC595Pins info;
  int ic_num;
  int pin_num;
  auto oneClock()->void;
  auto reset()->void;
public:
  HC595(struct HC595Pins &pins, int ic_num);
  auto clear() -> void;
  auto write(byte (&data)[], int ic_num) -> void;
  auto send()->void;
};