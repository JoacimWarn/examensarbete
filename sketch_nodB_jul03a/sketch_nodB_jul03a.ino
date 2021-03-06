/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2

  pinMode(4, OUTPUT);
  
}

void loop() {
  
  if (mySwitch.available()) {

    int recValue = mySwitch.getReceivedValue();
    
    Serial.print("Mottaget ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    if(recValue == 4436){

      Serial.println("Slå av");
      //stäng av
      digitalWrite(4, LOW);
      
    }
    else if(recValue == 4433){

      Serial.println("Slå på");
      //slå på
      digitalWrite(4, HIGH);
      
    }
    
    mySwitch.resetAvailable();
    
  }

}
