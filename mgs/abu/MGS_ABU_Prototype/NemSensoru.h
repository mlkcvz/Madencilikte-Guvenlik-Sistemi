#ifndef MY_NEMSENSORU_H
#define MY_NEMSENSORU_H
#include "Sensor.h"
#include <Arduino.h>
#include <dht11.h>  
#define DHT11PIN 7 




class NemSensoru : public Sensor {
  public:
    void runAlgorithm() override;
    NemSensoru( byte pin, byte tip );
    void initDHT();
    byte pin;
    dht11 DHT11;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif