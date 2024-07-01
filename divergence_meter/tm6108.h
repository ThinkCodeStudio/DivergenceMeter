#pragma once
#include <stdint.h>

class TM6108 {
private:
  uint8_t sck_pin;
  uint8_t dat_pin;
public:
  TM6108(uint8_t sck, uint8_t dat);
  auto read()->uint8_t;
};