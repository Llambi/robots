#include <Servo.h>

Servo servo1;
const int x_pin = 0;
int modo = 0;
const int bt1 = 9;
const int pl1 = 11;
const int pl2 = 2;


void setup() {
  Serial.begin(9600);
  pinMode(x_pin, INPUT);
  digitalWrite(bt1, HIGH);
  pinMode(pl1, INPUT);
  pinMode(pl2, INPUT);
  servo1.attach(3);

}

void loop() {
  //Serial.println(digitalRead(bt1));
  //Serial.println(digitalRead(pl1));
  //Serial.println(digitalRead(pl2));
  //Serial.println(analogRead(x_pin));
  if (modo == 0) {
    modo = 2;
  }
  else if (modo == 1) { // Automatico
    automatico();

  } else if (modo == 2) { // Controlado

    servo1.write(joystick());

    if (digitalRead(bt1) == LOW) {
      if ( modo == 2) {
        modo = 1;
      } else {
        modo = 2;
      }
    }
  }


}

int joystick() {
  
  if (analogRead(x_pin) > 905) {
    return 0;
  } else if (analogRead(x_pin) > 700) {
    return 85;
  } else if (analogRead(x_pin) > 300) {
    return 90;
  } else if (analogRead(x_pin) > 55) {
    return 95;
  } else {
    return 180;
  }
}

void automatico() {
  //Serial.println("HOLAAAAAAAAAA");
  int direccion = 0;
  while (modo == 1) {
    if (digitalRead(pl1) == LOW) {
      direccion = 0;
    }
    if (digitalRead(pl2) == LOW) {
      direccion = 180;
    }
    Serial.println(String(digitalRead(pl1)) + " " + String(digitalRead(pl2)));
    while (digitalRead(pl1) == HIGH && digitalRead(pl2) == HIGH) {
      Serial.println("HOLAAAAAAAAAA");
      if (direccion == 0 || direccion == 180) {
        servo1.write(direccion);
      }
      if (digitalRead(bt1) == LOW) {
        if (modo == 1) {
          modo  = 2;
        } else {
          modo = 1;
        }
        
      }
      return;
    }

  }
}
