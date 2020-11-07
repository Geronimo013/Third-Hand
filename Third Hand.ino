#include <LiquidCrystal.h>
#include <util/delay.h>
LiquidCrystal lcd(12, NULL, 11, 10,9,8,7);
int trigPin = 3;
int echoPin = 2;
int buzzerPin = 4;
int motorPin = 5;
int ledPin=6;
long duration;
int  distance;
int vit=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Distanta obiect:");
  lcd.setCursor(5,1);
  lcd.print("cm");
  delay(250);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.print(" ");

    if(distance <=35){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  tone(buzzerPin,500);
  analogWrite(motorPin, 200);
  digitalWrite(ledPin,HIGH);
  delay(50);
  }
  else
    if(distance <=50){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  tone(buzzerPin,1500);
  analogWrite(motorPin, 0);
  digitalWrite(ledPin,HIGH);
  delay(50);
  }
  else
    if(distance <=75){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  tone(buzzerPin,2000);
  analogWrite(motorPin, 0);
  digitalWrite(ledPin,LOW);
  delay(50);
  }
  else
  if(distance <=100){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  noTone(buzzerPin);
  analogWrite(motorPin, 0);
  digitalWrite(ledPin,LOW);
  delay(50);
  }

}
