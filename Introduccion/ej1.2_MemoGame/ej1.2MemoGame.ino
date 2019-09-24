const int redLed = 5;
const int greenLed = 4;
const int redBtn = 3;
const int greenBtn = 2;
const int maxTurn = 5;
bool redBtnPressed = false;
bool greenBtnPressed = false;
const size_t memoSize = 3 + maxTurn;
int memolist[memoSize];
int turn = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Inicio de sketch - Juego de Memoria");
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redBtn, INPUT);
    pinMode(greenBtn, INPUT);
}

void loop()
{
    if (turn == 0)
    {
        initArray(memolist, 3);
    }
    showMemoList();
    delay(1000); // solo 1seg porque en la anterior funcion ya se produjo una espera de otro seg
    play();
}

void play()
{
    if (turn < maxTurn)
    {
        int btnPressedCounter = 0;
        int userSolution[memoSize];
        while (btnPressedCounter < turn + 3)
        {

            bool redBtnValue = isBotonState(digitalRead(redBtn), redBtnPressed);
            bool greenBtnValue = isBotonState(digitalRead(greenBtn), greenBtnPressed);

            if (not(redBtnValue and greenBtnValue)) // Solo uno de los botones esta pulsado.
            {
                Serial.print("Boton pulsado ");
                if (redBtnValue)
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
            else
            {
                Serial.println("No se pueden pulsar los dos botones!");
            }
        }
        turn++;
    }
    checkTurn();
}

void powerOnLed(int led)
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
}

void checkTurn()
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
        turn++;
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
    redBtnPressed = false;
    greenBtnPressed = false;
    turn = 0;
}

void showMemoList()
{
    for (size_t i = 0; i < turn + 3; i++) // Habra minimo 3 elementos que recorrer en el turno inicial y se añade uno por turno
    {
        digitalWrite(memolist[i], HIGH);
        delay(1000);
    }
}

void initArray(int[] & array, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        array[i] = generateRandom(greenLed, redLed)
    }
}

int generateRandom(int min, int max)
{
    return random(min, max + 1);
}

bool isBotonState(int value, bool &btnState)
{
    if (value == HIGH and btnState)
    { //pulsandose
    }
    else if (value == HIGH and not btnState)
    { //Comenzo pulsacion
        btnState = true;
        return true;
    }
    else if (value == LOW and btnState)
    { //Despulso
        btnState = false;
    }
    else
    { //inicial
    }
    return false;
}