/*
  2/24/20
  Saul C.
  
  Input Pull-up Serial example  modified for interupts,
  multiple states cycled by a push button.
  with basic timed debounce.
  up/down with 2 button.
  
  The circuit:
  Simple circuit:
  - momentary switch attached from pin 2 to ground
  - momentary switch attached from pin 3 to ground

  original circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

*/

int s = 0;
int old = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
 
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), click3, LOW );
  
 pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), click, LOW );
  
}
long lastClick = 0;
long cd = 50;

long lastClick3 = 0; 

void print(String s){
  Serial.println(s);
}
void click3(){ 
  long temp  = millis();
  //print("" + temp);  
  if(temp - lastClick3 > cd){
    print("Real Click alt");
    if(--s < 0) s = 9;
    lastClick3 = millis();
  }
}
void click(){ 
  long temp  = millis();
  //print("" + temp);  
  if(temp - lastClick > cd){
    print("Real Click");
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
