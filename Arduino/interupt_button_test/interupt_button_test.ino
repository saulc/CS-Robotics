/*
  2/24/20
  Saul C.
  
  Input Pull-up Serial example  modified for interupts,
  multiple states cycled by a push button.
  with basic timed debounce.
  
  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

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
