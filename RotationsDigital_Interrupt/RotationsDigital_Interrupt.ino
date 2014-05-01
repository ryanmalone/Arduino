volatile int count = 0; //For counting number of times the magnet passes the reed switch
//volatile long lastRiseTime = 0; //Time at which pin2 (interrupt 0) goes from LOW to HIGH


void setup()
{
  Serial.begin(9600);

 digitalWrite(3, HIGH); //Enable pullup
 
 attachInterrupt(1, rising, RISING);
// attachInterrupt(0, falling, FALLING);
 
// pinMode(2, INPUT);

}

void loop()
{
  Serial.print("Counter : ");
  Serial.println(count);
  delay (1000);
}

//void falling()
//{
//  //If more than 50 ms has elapsed since the last time pin 2 went high
//  if ((millis() - lastRiseTime) > 100)
// {
//   counter++;
// }
//} 

void rising()
{
 static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 10ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 30)
  {
    count++;
  }
  last_interrupt_time = interrupt_time;
}
