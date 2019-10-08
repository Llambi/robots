const int redLed = 5;
const int greenLed = 4;
const int redBtn = 3;
const int greenBtn = 2;
const int maxTurn = 2;
bool redBtnState = false;
bool greenBtnState = false;
const size_t memoSize = 3 + maxTurn;
int memolist[memoSize];
int turn = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Inicializacion - Juego de Memoria");
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redBtn, INPUT_PULLUP);
    pinMode(greenBtn, INPUT_PULLUP);
}

void loop()
{
    if (turn == 0)
    {
        Serial.println("Inicio de juego, inicializando Array...");
        initArray(memolist, 3);
    }
    showMemoList();
    delay(1000); // solo 1seg porque en la anterior funcion ya se produjo una espera de otro seg
    userPlay();
    if (turn != 0) //Comprobar que el juego no se haya reiniciado
        memoPlay();
}

void memoPlay()
{
    // turno + 3(caso base) -1 1(posiciones en listas empiezan en 0)
    memolist[turn + 3 -1] = generateRandom(greenLed, redLed);
}

void userPlay()
{
    
    int btnPressedCounter = 0;
    int userSolution[memoSize];
    while (btnPressedCounter < turn + 3)
    {

        bool redPressed = refreshBotonState(digitalRead(redBtn), redBtnState);
        bool greenPressed = refreshBotonState(digitalRead(greenBtn), greenBtnState);
        
        if (redPressed != greenPressed) // Solo uno de los botones esta pulsado.
        {
            Serial.print("Boton pulsado ");
            if (redPressed)
            {
                Serial.println("Rojo");
                powerOnLed(redLed);
                userSolution[btnPressedCounter] = redLed;
            }
            else
            {
                Serial.println("Verde");
                powerOnLed(greenLed);
                userSolution[btnPressedCounter] = greenLed;
            }
            btnPressedCounter++;
        }
    }
  	checkTurn(userSolution);
}

void powerOnLed(int led)
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  	delay(1000);
}

void checkTurn(int userSolution[])
{
    int succeses = 0;
    for (size_t i = 0; i < turn + 3; i++)
    {
        if (memolist[i] == userSolution[i])
        {
            succeses++;
        }
    }
    if (succeses == turn + 3)
    {
        if (turn == maxTurn)
        {
            Serial.println("Has Ganado!");
            resetGame();
        }
        else
        { 
          turn++;
        }
    }
    else
    {
        Serial.println("Finalizado Juego");
        resetGame();
    }
}

void resetGame()
{
    memset(memolist, 0, sizeof(memolist));
    redBtnState = false;
    greenBtnState = false;
    turn = 0;
}

void showMemoList()
{
    Serial.println("Estado de Memoria:");
    for (size_t i = 0; i < turn + 3; i++) // Habra minimo 3 elementos que recorrer en el turno inicial y se añade uno por turno
    {
        Serial.print(memolist[i]);
        powerOnLed(memolist[i]);
    }
    Serial.println();
}

void initArray(int array[], int count)
{
    for (size_t i = 0; i < count; i++)
    {
        array[i] = generateRandom(greenLed, redLed);
    }
}

int generateRandom(int min, int max)
{
    return random(min, max + 1);
}

bool refreshBotonState(int btnValue, bool &btnState)
{
    if (!btnState and btnValue == HIGH)
    { // Pulsacion
        btnState = true;
        return true;
    }
    else if (btnState and btnValue == HIGH)
    { // Pulsado
        return false;
    }
    else if (btnState and btnValue == LOW)
    { // Liberacion
        btnState = false;
        return false;
    }
    else
    { // Liberado
        return false;
    }
}
