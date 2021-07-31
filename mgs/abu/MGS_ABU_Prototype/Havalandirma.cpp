#include "Havalandirma.h"

Havalandirma::Havalandirma(byte pin){
  this -> pin = pin; 
}




void Havalandirma::turnOnFan(byte fanLevel){ 
  if(this->level != fanLevel) {
  this->level = fanLevel;
  Havalandirma::setFanSpeed();
  analogWrite(6,this->fanSpeed);
  analogWrite(5,0);
  Serial.println("\n");
  Serial.print("fan+");
  Serial.print(this->level);
  Serial.println("\n");
  }
}

void Havalandirma::setFanSpeed( ){ 
  Serial.println("\n");
  Serial.print("fan+");
  Serial.print(this->level);
  Serial.println("\n");
  switch (this->level){
    case 0:
      this->fanSpeed = 0;
      break;
    case 1:
      this->fanSpeed = 50;
      break;
    case 2:
      this->fanSpeed = 100;
      break;
    case 3:
      this->fanSpeed = 150;
      break;
    case 4:
      this->fanSpeed = 250;
      break;
    case 5:
      this->fanSpeed = 250;
      break;
    default:
      this->fanSpeed = 0;
      break;
  }
  
}

void Havalandirma::fanSpeedUp(){
  if(this->level < 5){
    this->level +=1;
    Havalandirma::setFanSpeed();
    analogWrite(6,this->fanSpeed);
    analogWrite(5,0);
     Serial.print("fan+");
  Serial.print(this->level);
  }
}

void Havalandirma::fanSpeedDown(){
   if(this->level > 0){
    this->level -=1; 
    Havalandirma::setFanSpeed();
  analogWrite(6,this->fanSpeed);
  analogWrite(5,0);
   Serial.print("fan+");
  Serial.print(this->level);
  }
}

void Havalandirma::turnOffFan(){
  if(this->level != 0){
  this->level = 0;
   Havalandirma::setFanSpeed();
  analogWrite(6,this->fanSpeed);
  analogWrite(5,0);
  Serial.println("fan+0");
  }
}

void Havalandirma::init(){
  pinMode(this->pin, OUTPUT);
  turnOffFan();
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Havalandirma::setFanSpeed();
}

byte Havalandirma::getFanLevel(){
  return this->level;
}
