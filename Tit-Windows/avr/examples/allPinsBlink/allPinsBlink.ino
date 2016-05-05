
#define maxPins 23 //(0 to 23): 24 pins

int pinCount = 0;
long shifter  = 1; 
void setup() {
  // put your setup code here, to run once:

  for(pinCount = 0; pinCount <= maxPins; pinCount++ )
  {
      pinMode(pinCount, OUTPUT);    
  }    
}

void loop() {
  // put your main code here, to run repeatedly:

    for(pinCount = 0; pinCount <= maxPins; pinCount++)
    {
        digitalWrite(pinCount, HIGH);
        delay(50);
    }

    for(pinCount = maxPins; pinCount >= 0; pinCount-- )
    {
        digitalWrite(pinCount, LOW);
        delay(50);
    }

}
