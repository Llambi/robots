#include <Keypad.h>

const byte nfilas = 4;
const byte ncolumnas = 4;
char teclas[nfilas][ncolumnas] = {
    {'*','0','#','D'},
    {'7','8','9','C'},
    {'1','2','3','A'},
    {'4','5','6','B'}
  };
byte pfilas[nfilas] = {2, 3, 4, 5}; //Filas
byte pcolumnas[ncolumnas] = {A0, A1, A2, A3}; //Columnas
Keypad teclado = Keypad(makeKeymap(teclas), pfilas, pcolumnas, nfilas, ncolumnas);
const int colVerde = 9, colRojo = 8, colAzul = 10;
double tiempo;
bool estadoPuerta = true;
String contra = "";
int contador = 0;
int luzValue = 0;
int segundosPuerta = 5;

void setup() {
  pinMode(colVerde,OUTPUT);
  pinMode(colRojo,OUTPUT);
  pinMode(colAzul,OUTPUT);
  digitalWrite(colVerde,HIGH);
  tiempo = 0;
  Serial.begin(9600);
  //delay(1500);
}

void loop() {
  
  char tecla = teclado.getKey();
  Serial.println(tecla);
  if(tecla == 'A')
    abrirPuerta(true);
  if(tecla == 'C')
      cerrarPuerta();
}

void abrirPuerta(bool saliendo){
    digitalWrite(colVerde,LOW);
    //delay(1000);
    //tiempo = millis();
    digitalWrite(colRojo,HIGH);
    estadoPuerta = false;
}

void cerrarPuerta(){
  //if(millis() - tiempo >= (segundosPuerta*1000)){
      estadoPuerta = true;
      //tiempo = 0;
      digitalWrite(colAzul,LOW);
      digitalWrite(colRojo,LOW);
      digitalWrite(colVerde,HIGH);
      //delay(1000);
 //}
}
