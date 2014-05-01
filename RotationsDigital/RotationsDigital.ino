int led = 11;
int lightLevel;
int rotations = 0 ;
int buttonPin = 12;

void setup()
{
 Serial.begin(9600);
int reedVal;
}

void loop()
{
  if (analogRead(A0) > 0 ) {
  
  }
  
  while (digitalRead(buttonPin) == LOW){
  delay(1);
  }
  rotations ++ ;
  Serial.print("Rotations : ");
    Serial.println(rotations);
  
   while (digitalRead(buttonPin) == HIGH){
  delay(1);}
  
  }
  
 
