#include "Sensor.h"

Sensor::Sensor(byte pin, byte tip){
  this -> pin = pin;
  this -> tip = tip;
  init(); 
}

void Sensor::init(){
  seviye = 0;
  belirtec = 0; 
  
}