/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledCount = 6;
int ledPins[] = {8,10,9,12,11,13};
int ledDelay = 50;
int buttonPin = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int thisLed = 0; thisLed < ledCount; thisLed++)
  {
  pinMode(ledPins[thisLed], OUTPUT); 
  }  
  pinMode(buttonPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
   for (int thisLed = 0; thisLed < ledCount; thisLed++)
  {
   digitalWrite(ledPins[thisLed], HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  while (digitalRead(buttonPin) == HIGH){
  delay (10);
  }
  digitalWrite(ledPins[thisLed], LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay); 
  }
  
     for (int thisLed = ledCount - 1; thisLed > 0; thisLed--)
  {
   digitalWrite(ledPins[thisLed], HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(ledPins[thisLed], LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay); 
  }
               // wait for a second
}
