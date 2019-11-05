
#include <Servo.h>
const int motD = 9; // pin motor derecho
const int motI = 8; // pin motor izquierdo
Servo servoIzq;
Servo servoDer;
const int PhotoSensorLeft = 2; // pin del Arduino conectado al sensor óptico Izquierdo
const int PhotoSensorRight = 3; // pin del Arduino conectado al sensor óptico Derecho
// constantes
const int BLANCO = 0;
const int NEGRO = 1;

/**
 * Metodo que inicializa los pines y variables
 */
void setup(){
  // put your setup code here, to run once:
  pinMode(motD, OUTPUT);
  pinMode(motI, OUTPUT);
  pinMode(PhotoSensorLeft,INPUT);
  pinMode(PhotoSensorRight,INPUT);
  servoIzq.attach(motI);
  servoDer.attach(motD);

}

/**
 * Metodo que se repite en bucle
 */
void loop() {
  
    int valLeft = digitalRead(PhotoSensorLeft);
    int valRight = digitalRead(PhotoSensorRight);

    //Hacia delante
    if (valLeft == NEGRO && valRight == NEGRO) {
        alante(100);
    } 
    //Hacia la izquierda
    else if (valLeft == NEGRO && valRight == BLANCO) {
        derecha(100);
    }
    //Hacia la derecha
    else if (valLeft == BLANCO && valRight == NEGRO) {
        izquierda(100);
    }
    
       para();
      
  }

/**
 * Metodo que hace que el robot avance
 */
void para() {
    servoIzq.write(90);
    servoDer.write(90);
}

/**
 * Metodo que hace que el robot avance
 */
void alante(int del) {
    servoIzq.write(0);
    servoDer.write(180);
    delay(del);
}

/**
 * Metodo que hace que el robot gire a la derecha
 */
void derecha (int del) {
    servoIzq.write(125);
    servoDer.write(125);
    delay(del);
}

/**
 * Metodo que hace que el robot gire a la izquierda
 */
void izquierda(int del) {
    servoIzq.write(45);
    servoDer.write(45);
    delay(del);
  }
