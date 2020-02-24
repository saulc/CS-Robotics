/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/

int s = 0;
int old = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  attachInterrupt(digitalPinToInterrupt(2), click, LOW );
  

}
long lastClick = 0;
long cd = 50;

void print(String s){
  Serial.println(s);
}
void click(){ 
  long temp  = millis();
  //print("" + temp);  
  if(temp - lastClick > cd){
   // print("Real Click");
    if(++s > 9) s = 0;
    lastClick = millis();
  }
}
void loop() {
  if(s != old){
  //print out the value of the pushbutton
  Serial.println(s);
  old = s;
  }
 
}
