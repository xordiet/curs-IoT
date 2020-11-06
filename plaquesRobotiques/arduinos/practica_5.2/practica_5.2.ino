#include <LiquidCrystal.h>
#include "IRremote.h"

int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 13

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
// takes action based on IR code received
// describing Remote IR codes
void translateIR() {
  switch (results.value){
    case 0xFFA25D: Serial.println("POWER"); break;
    case 0xFFE21D: Serial.println("FUNC/STOP"); break;
    case 0xFF629D: Serial.println("VOL+"); break;
    case 0xFF22DD: Serial.println("FAST BACK");    break;
    case 0xFF02FD: Serial.println("PAUSE");    break;
    case 0xFFC23D: Serial.println("FAST FORWARD");   break;
    case 0xFFE01F: Serial.println("DOWN");    break;
    case 0xFFA857: Serial.println("VOL-");    break;
    case 0xFF906F: Serial.println("UP");    break;
    case 0xFF9867: Serial.println("EQ");    break;
    case 0xFFB04F: Serial.println("ST/REPT");    break;
    case 0xFF6897: Serial.println("0");    break;
    case 0xFF30CF: Serial.println("1");    break;
    case 0xFF18E7: Serial.println("2");    break;
    case 0xFF7A85: Serial.println("3");    break;
    case 0xFF10EF: Serial.println("4");    break;
    case 0xFF38C7: Serial.println("5");    break;
    case 0xFF5AA5: Serial.println("6");    break;
    case 0xFF42BD: Serial.println("7");    break;
    case 0xFF4AB5: Serial.println("8");    break;
    case 0xFF52AD: Serial.println("9");    break;
    case 0xFFFFFFFF: Serial.println(" REPEAT"); break;

    default:
      Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR


//Crea l'objete LCD amb els núms assignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


void setup() {
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.setCursor(0, 0);
  lcd.print("Hola Mon!");
  lcd.setCursor(0, 1);
  lcd.print("Hello World!");
  delay(1000);
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
if (irrecv.decode(&results)) { // have we received an IR signal?
    translateIR(); 
    irrecv.resume(); // receive the next value
  } 
}
