#define ENABLE 3
#define DIRA 6
#define DIRB 5
#define ENABLI 11
#define DISA 10
#define DISB 9

// Joystick pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int p1;
int p2;
int pwma1;
int pwma2;
int pwmb1;
int pwmb2;

void setup() {
  //pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  //pinMode(ENABLI,OUTPUT);
  pinMode(DISA,OUTPUT);
  pinMode(DISB,OUTPUT);
  //el Joystick
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  }
  
void loop() {
  //rebo els valors del Joystick
  //els mostro i emmagatzemo
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  p1=analogRead(X_pin);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  p2=analogRead(Y_pin);
  Serial.print("\n\n");
  
  //mapejo motor1
  pwma1 = map(p1, 0, 1023, 0, 255);
  pwma2 = map(p1, 0, 1023, 255, 0);
  //mapejo motor2
  pwmb1 = map(p2, 0, 1023, 0, 255);
  pwmb2 = map(p2, 0, 1023, 255, 0);
  
  //enviem el pwm a motor1
  analogWrite(DIRA,pwma1);
  analogWrite(DIRB,pwma2);
  //enviem el pwm a motor2
  analogWrite(DISA,pwmb1);
  analogWrite(DISB,pwmb2);
  
  delay(500);
  }
