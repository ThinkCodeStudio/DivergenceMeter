#include "esp32-hal.h"
#include "esp32-hal-gpio.h"
#include "hc595.h"
#include <Arduino.h>

HC595::HC595(struct HC595Pins &pins, int ic_num) {
  this->info = pins;
  this->ic_num = ic_num;
  this->pin_num = ic_num * 8;
  pinMode(this->info.DAT, OUTPUT);
  pinMode(this->info.RCK, OUTPUT);
  pinMode(this->info.SCK, OUTPUT);
  reset();
}

auto HC595::reset() -> void {
  digitalWrite(info.DAT, 0);
  digitalWrite(info.RCK, 0);
  digitalWrite(info.SCK, 0);
}

auto HC595::oneClock() -> void {
  digitalWrite(info.SCK, 0);
  delayMicroseconds(1);
  digitalWrite(info.SCK, 1);
  delayMicroseconds(1);
}

auto HC595::send() -> void {
  digitalWrite(info.RCK, 1);
}

auto HC595::clear() -> void {
  reset();
  for (int i = 0; i < pin_num; i++) {
    oneClock();
  }
  send();
}

auto HC595::write(byte (&data)[], int ic_num) -> void {
  reset();
  for (int i = ic_num; i >= 0; --i) {
    byte t = data[i];
    for (int j = 0; j < 8; j++) {
      digitalWrite(info.DAT, t / 0b10000000);
      t <<= 1;
      oneClock();
    }
  }
}
