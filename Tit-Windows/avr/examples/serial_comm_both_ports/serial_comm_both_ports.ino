void setup() {
  //intialiaze both the ports
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // send messages on the ports
  Serial.println("hey, tit on COM0");
  Serial1.println("hey, tit1 on COM1");
  delay(1000);
}
