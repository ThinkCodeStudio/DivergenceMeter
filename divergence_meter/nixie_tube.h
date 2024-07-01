#pragma once
#include "hc595.h"

typedef enum {
  NixieTubeEnum_ZERO,
  NixieTubeEnum_ONE,
  NixieTubeEnum_TWO,
  NixieTubeEnum_THREE,
  NixieTubeEnum_FOUR,
  NixieTubeEnum_FIVE,
  NixieTubeEnum_SIX,
  NixieTubeEnum_SEVEN,
  NixieTubeEnum_EIGHT,
  NixieTubeEnum_NINE,
  NixieTubeEnum_LTDOT,
  NixieTubeEnum_RTDOT,
  NixieTubeEnum_NONE
} NixieTubeEnum;



class NixieTube {
private:
  HC595 *hc595;
  static const int buf_size = 12;
  byte send_buf[buf_size];

  auto setL1(NixieTubeEnum) -> void;
  auto setL2(NixieTubeEnum) -> void;
  auto setL3(NixieTubeEnum) -> void;
  auto setL4(NixieTubeEnum) -> void;
  auto setL5(NixieTubeEnum) -> void;
  auto setL6(NixieTubeEnum) -> void;
  auto setL7(NixieTubeEnum) -> void;
  auto setL8(NixieTubeEnum) -> void;

  auto sendBufSetOne(int index, int position) -> void;

public:
  NixieTube(HC595 &hc595);
  auto close() -> void;
  auto show(NixieTubeEnum (&enums)[8]) -> void;
};