#include <Servo.h>
Servo servo1;
const int boton_pin = 2; // Pin para el boton pin2
const int x_pin = 0; // eje X A0
const int y_pin = 1; // eje Y A1
const int choque1 = 5;  // sensor choque 1
const int choque2 = 4;  // sensor choque 2
int modo = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  pinMode(boton_pin, INPUT);
  pinMode(choque1, INPUT);
  pinMode(choque2, INPUT);
  digitalWrite(boton_pin, HIGH);
}

void loop() {
  if(modo == 0){ // Calibrar
    modo = 1;
  }
  if(modo == 1){ // Manual
    int dir = valorJoys();
    if(dir > 80 and dir <100){
       servo1.write(90);
        Serial.println("Parado");
    }
    else {
        servo1.write(dir);
        Serial.println(dir);
    }
    int boton = digitalRead(boton_pin);
    if( boton == LOW){
      Serial.println(boton);
      if(modo == 1) modo = 2;
      else modo = 1;
    }
  }
  if(modo == 2){ // Automatico
    moverAuto();
  }
  // delay(500);
}

int valorJoys(){
  return map(analogRead(x_pin),0,1023,0,180);
}

void moverAuto(){
  int dir = 0;
  while(modo == 2){
    if(digitalRead(choque1) == LOW) dir = 180;
    if(digitalRead(choque2) == LOW) dir = 0;
    while(digitalRead(choque1) == HIGH && digitalRead(choque2) == HIGH){
      if(dir == 0) servo1.write(dir);
      else if(dir == 180) servo1.write(dir);
      if(digitalRead(boton_pin) == LOW){
        if(modo == 1) modo = 2;
        else modo = 1;
        return;
      }
    }
    
  }
}
