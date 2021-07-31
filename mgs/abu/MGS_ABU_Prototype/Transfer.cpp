#include "Transfer.h"


Transfer::Transfer(bool stateFlag){
  this -> stateFlag = stateFlag;
}



void Transfer::setTransferMsg(String transferMsg){
  this->transferMsg = transferMsg;
}

String Transfer::getTransferMsg(){
  return this->transferMsg;
}

bool Transfer::getStateFlag(){
  return this->stateFlag;
}

void Transfer::setStateFlag(bool stateFlag){
  this -> stateFlag = stateFlag;
}
void Transfer::transferEt(String transferMsg){
 
  if((transferMsg.compareTo(this->lastTransferMsg)) != 0){
  
  Transfer::setTransferMsg(  transferMsg);
  Transfer::setStateFlag(true);
  Serial.println(transferMsg);
  this->lastTransferMsg = transferMsg;
  }
}
