#include <Servo.h>

Servo servo1;
const int x_pin = 0; 
 

void setup() {
   Serial.begin(9600);
   pinMode(x_pin,INPUT);
  servo1.attach(3);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(joystick());
  
}

int joystick(){
  Serial.println(analogRead(x_pin));
 if(analogRead(x_pin) > 905){
    return 0;
  }else if(analogRead(x_pin) > 700){
    return 85;
  }else if(analogRead(x_pin) > 300){
    return 90;
  }else if(analogRead(x_pin) > 55){
    return 95;
  }else{
    return 180;
  }
}   
