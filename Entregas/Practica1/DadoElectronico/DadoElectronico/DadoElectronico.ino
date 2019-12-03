const int led1 = 7;
const int led2 = 8;
const int led3 = 9;
const int interruptor = 2;
bool flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Inicio de sketch - secuencia de numeros aleatorios");
  pinMode(led1 , OUTPUT); 
  pinMode(led2 , OUTPUT); 
  pinMode(led3 , OUTPUT);
  pinMode(interruptor, INPUT); 
}

void loop() { 
  // put your main code here, to run repeatedly:
  reset();
  int value = digitalRead(interruptor);
  Serial.println("Elinterruptor es = ");
  Serial.println(value);
  if(isBotonState(value)){
    int randomNumber = random(1,4);
    selectLedsToPowerOn(randomNumber);
    Serial.println("El numero aleatorio es = ");
    Serial.println(randomNumber);
  }
  delay(1000);
}

void reset(){
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , LOW);
}

bool isBotonState(int value){
  if(value == HIGH and flag){ //pulsandose
    
  }
  else if (value == HIGH and not flag){ //Comenzo pulsacion
    flag = true;
    return true;
  }
  else if (value == LOW and flag){ //Despulso
    flag = false;
  }
  else{ //inicial
    
  }
  return false;
}
void selectLedsToPowerOn(int value){
  if (value >= 1){
     digitalWrite(led1 , HIGH);
  }
  if (value >= 2){
     digitalWrite(led2 , HIGH);
  }
  if (value >= 3){
     digitalWrite(led3 , HIGH);
  }

}
