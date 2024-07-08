#include "nixie_tube.h"

auto NixieTube::sendBufSetOne(int index, int position) -> void{
  send_buf[index - 1] |= (1 << position);
}

NixieTube::NixieTube(HC595 &hc595) {
  this->hc595 = &hc595;
  this->close();
}

auto NixieTube::close() -> void {
  hc595->clear();
}

auto NixieTube::show(NixieTubeEnum (&enums)[8]) -> void {
  memset(send_buf, 0, buf_size);
  setL1(enums[0]);
  setL2(enums[1]);
  setL3(enums[2]);
  setL4(enums[3]);
  setL5(enums[4]);
  setL6(enums[5]);
  setL7(enums[6]);
  setL8(enums[7]);
  hc595->write(send_buf, buf_size);
  hc595->send();
}

auto NixieTube::setL1(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(4, 6);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(3, 4);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(3, 3);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(3, 2);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(3, 1);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(4, 2);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(4, 1);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(4, 3);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(4, 4);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(4, 5);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(4, 7);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(4, 0);
      break;
    default:
      break;
  }
}
auto NixieTube::setL2(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(5, 7);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(5, 1);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(5, 0);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(3, 0);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(3, 7);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(3, 5);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(3, 6);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(5, 4);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(5, 5);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(5, 6);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(5, 2);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(5, 3);
      break;
    default:
      break;
  }
}
auto NixieTube::setL3(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(6, 4);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(6, 0);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(6, 1);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(2, 4);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(2, 3);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(2, 2);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(2, 1);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(6, 7);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(6, 6);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(6, 5);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(6, 2);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(6, 3);
      break;
    default:
      break;
  }
}
auto NixieTube::setL4(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(7, 5);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(7, 0);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(7, 1);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(7, 2);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(2, 0);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(2, 7);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(2, 6);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(2, 5);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(7, 7);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(7, 6);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(7, 3);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(7, 4);
      break;
    default:
      break;
  }
}
auto NixieTube::setL5(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(8, 6);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(8, 0);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(8, 1);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(8, 2);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(1, 4);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(1, 3);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(1, 2);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(1, 1);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(8, 7);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(8, 5);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(8, 3);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(8, 4);
      break;
    default:
      break;
  }
}
auto NixieTube::setL6(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(9, 5);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(9, 0);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(9, 1);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(9, 2);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(1, 6);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(1, 0);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(1, 7);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(1, 5);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(9, 7);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(9, 6);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(9, 3);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(9, 4);
      break;
    default:
      break;
  }
}
auto NixieTube::setL7(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(10, 2);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(11, 4);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(11, 5);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(10, 0);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(10, 1);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(10, 5);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(10, 6);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(10, 7);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(10, 4);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(10, 3);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(11, 6);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(11, 7);
      break;
    default:
      break;
  }
}

auto NixieTube::setL8(NixieTubeEnum state) -> void {
  switch (state) {
    case NixieTubeEnum_ZERO:
      sendBufSetOne(11, 0);
      break;
    case NixieTubeEnum_ONE:
      sendBufSetOne(12, 0);
      break;
    case NixieTubeEnum_TWO:
      sendBufSetOne(12, 1);
      break;
    case NixieTubeEnum_THREE:
      sendBufSetOne(12, 2);
      break;
    case NixieTubeEnum_FOUR:
      sendBufSetOne(12, 3);
      break;
    case NixieTubeEnum_FIVE:
      sendBufSetOne(12, 6);
      break;
    case NixieTubeEnum_SIX:
      sendBufSetOne(12, 7);
      break;
    case NixieTubeEnum_SEVEN:
      sendBufSetOne(11, 3);
      break;
    case NixieTubeEnum_EIGHT:
      sendBufSetOne(11, 2);
      break;
    case NixieTubeEnum_NINE:
      sendBufSetOne(11, 1);
      break;
    case NixieTubeEnum_LTDOT:
      sendBufSetOne(12, 4);
      break;
    case NixieTubeEnum_RTDOT:
      sendBufSetOne(12, 5);
      break;
    default:
      break;
  }
}

/***
U1:
  QA(0)->6-5
  QB(1)->5-7
  QC(2)->5-6
  QD(3)->5-5
  QE(4)->5-4
  QF(5)->6-7
  QG(6)->6-4
  QH(7)->6-6
U2:
  QA(0)->4-4
  QB(1)->3-6
  QC(2)->3-5
  QD(3)->3-4
  QE(4)->3-3
  QF(5)->4-7
  QG(6)->4-6
  QH(7)->4-5
U3:
  QA(0)->2-3
  QB(1)->1-4
  QC(2)->1-3
  QD(3)->1-2
  QE(4)->1-1
  QF(5)->2-5
  QG(6)->2-6
  QH(7)->2-4
U4:
  QA(0)->1-R
  QB(1)->1-6
  QC(2)->1-5
  QD(3)->1-7
  QE(4)->1-8
  QF(5)->1-9
  QG(6)->1-0
  QH(7)->1-L
U5:
  QA(0)->2-2
  QB(1)->2-1
  QC(2)->2-L
  QD(3)->2-R
  QE(4)->2-7
  QF(5)->2-8
  QG(6)->2-9
  QH(7)->2-0
U6:
  QA(0)->3-1
  QB(1)->3-2
  QC(2)->3-L
  QD(3)->3-R
  QE(4)->3-0
  QF(5)->3-9
  QG(6)->3-8
  QH(7)->3-7
U7:
  QA(0)->4-1
  QB(1)->4-2
  QC(2)->4-3
  QD(3)->4-L
  QE(4)->4-R
  QF(5)->4-0
  QG(6)->4-9
  QH(7)->4-8
U8:
  QA(0)->5-1
  QB(1)->5-2
  QC(2)->5-3
  QD(3)->5-L
  QE(4)->5-R
  QF(5)->5-9
  QG(6)->5-0
  QH(7)->5-8
U9:
  QA(0)->6-1
  QB(1)->6-2
  QC(2)->6-3
  QD(3)->6-L
  QE(4)->6-R
  QF(5)->6-0
  QG(6)->6-9
  QH(7)->6-8
U10:
  QA(0)->7-3
  QB(1)->7-4
  QC(2)->7-0
  QD(3)->7-9
  QE(4)->7-8
  QF(5)->7-5
  QG(6)->7-6
  QH(7)->7-7
U11:
  QA(0)->8-0
  QB(1)->8-9
  QC(2)->8-8
  QD(3)->8-7
  QE(4)->7-1
  QF(5)->7-2
  QG(6)->7-L
  QH(7)->7-R
U12:
  QA(0)->8-1
  QB(1)->8-2
  QC(2)->8-3
  QD(3)->8-4
  QE(4)->8-L
  QF(5)->8-R
  QG(6)->8-5
  QH(7)->8-6
***/
