 
 int rpm = 186;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int noChar = Serial.available(); 
  if(noChar) {
    int rpmMotor = Serial.read();
    if(rpmMotor==97)  rpm += 1;
    if(rpmMotor==122) rpm -= 1;
    if(rpmMotor==32)  rpm = 186; 
    rpm = constrain(rpm,0,255);
     analogWrite(5,rpm);
     Serial.print("PWM");
     Serial.print('\t');
     Serial.print(rpm);
     Serial.print('\t');
     Serial.println(rpmMotor);
  } 
delay(5);
}
