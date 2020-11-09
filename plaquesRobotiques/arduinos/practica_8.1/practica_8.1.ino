int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

byte leds; // numero entre 0 i 255 que el programa mostra el seu binari en forma de leds encesos o apagats
byte lletra;
String data="";

void updateShiftRegister()
{
  
   shiftOut(dataPin, clockPin, LSBFIRST, lletra);
  
}

void asciitoled(String paraula) {

    /* 1.hem d'agafar cadascuna de les lletres de l'string
       2. Cadascuna de aquestes lletres la pintarem 
    */
    for (int i = 0; i < paraula.length(); i++){
    digitalWrite(latchPin, LOW);
    lletra=paraula[i];
    for (int i = 0; i < 8; i++){
        updateShiftRegister();
    }
    digitalWrite(latchPin, HIGH);
    delay(2000);  
    }
     }

void setup() 
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin, LOW);
}

void loop() {
    while (Serial.available())
   {
      char character = Serial.read();
      if (character != '\n')
      {
         data.concat(character);
      }
      else
      {
         Serial.println(data);
         asciitoled(data);
         data = "";
      }

   }}
   
