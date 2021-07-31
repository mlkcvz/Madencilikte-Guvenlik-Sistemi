#ifndef MY_TRANSFER_H
#define MY_TRANSFER_H

#include <Arduino.h>



class Transfer {
   
  public:
    Transfer(bool stateFlag);
    bool stateFlag;
    String transferMsg;
String lastTransferMsg;
    void setTransferMsg(String transferMsg);
    String getTransferMsg();
    void setStateFlag(bool stateFlag);
    bool getStateFlag();
    void transferEt(String transferMsg );
    
    
};

#endif
