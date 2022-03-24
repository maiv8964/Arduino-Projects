#define MOSFET 2

void setup() {

  pinMode(MOSFET, OUTPUT); // Set D2 pin (MOSFET + Pump) to output
  digitalWrite(MOSFET, LOW); // Pump off

  pinMode(1, INPUT); // Set Pin 1 (Touch Button) to input

  pinMode(LED_BUILTIN, OUTPUT); // Set LED as output
    
}

void loop() {

  if(digitalRead(1) == HIGH) { // If Button is Touched

    digitalWrite(MOSFET, HIGH); // Turn on Pump
    digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
    
  }else{

    digitalWrite(MOSFET, LOW); // Turn off Pump
    digitalWrite(LED_BUILTIN, LOW); // Turn off LED
    
  }

  delay(100);

}
