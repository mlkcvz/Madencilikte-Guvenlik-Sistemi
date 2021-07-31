/* 
 *  Her "period" dakikada bir verilerin iletilmesi için
 *  ABU nesnesini tetikle.
 */

#ifndef MY_ZAMANLAMA_H
#define MY_ZAMANLAMA_H
#include <Arduino.h>
#include "Sensor.h"
#include "Transfer.h"
class Zamanlama {
  public:
    Zamanlama(int period);
    int period;
    unsigned long timeLast;
    unsigned long timeCurrent;
    void trigger(byte tip, int seviye, byte belirtec, Transfer& transferControl );
    void countTime(Sensor& ortam, Transfer& transferControl);
    unsigned long minToMilis( );
};

#endif
