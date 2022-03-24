#include <Arduino.h>

// Make synonyms using #define.  No semi-colons needed here.
#define MOSFET 2   // The MOSFET driver for the water pump on digital I/O 2
#define REDLED 4   // Big red LED on digital I/O 4
#define BUTTON 6   // Push button on digital I/O 6
#define MOISTURE A1
#define WET_THRESH 600

void setup() {

    Serial.begin(9600); //enable serial @ 9600  
    pinMode(MOSFET, OUTPUT); // Sets the D2 pin (MOSFET + Pump) to output
    pinMode(REDLED, OUTPUT); // Sets the D4 pin (LED) to output
    pinMode(BUTTON, INPUT); // Sets the D6 pin (Button) to input
    digitalWrite(MOSFET, LOW);    // pump off

    while(true){
   
      int moistureValue = analogRead(MOISTURE);
   
      if(moistureValue >= WET_THRESH){ //If the moisture value is higher or equal than the value 600, turn on the pump

        digitalWrite(MOSFET,HIGH);  
        
      }

      if(moistureValue < WET_THRESH){ //If the moisture value is lower than the value 600, turn off the pump
        
        digitalWrite(MOSFET,LOW);
      
      }
    }  
}
