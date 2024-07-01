#include "esp32-hal-gpio.h"
#include "tm6108.h"



TM6108::TM6108(uint8_t sck, uint8_t dat) {
  sck_pin = sck;
  dat_pin = dat;
  pinMode(sck_pin, OUTPUT_OPEN_DRAIN);
  pinMode(dat_pin, INPUT_PULLDOWN);
  digitalWrite(sck_pin, 1);
}

auto TM6108::read() -> uint8_t {
  if (digitalRead(dat_pin)) {
    return 0;
  }
  uint16_t buf = 0;
  for (int i = 0; i < 16; i++) {
    digitalWrite(sck_pin, 0);
    delayMicroseconds(30);
    digitalWrite(sck_pin, 1);
    delayMicroseconds(30);
    buf >>= 1;
    buf |= (digitalRead(dat_pin) << 15);
  }
  // if(buf / 0b1000000000000 == 0b1010)
  uint8_t *p = (uint8_t*)&buf;
  return p[0];
}