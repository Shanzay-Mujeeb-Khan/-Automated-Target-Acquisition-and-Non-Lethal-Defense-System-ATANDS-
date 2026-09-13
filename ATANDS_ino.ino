#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

int trigPin = 10;           //pins
int echoPin = 11;
int servoPin = 9;
int buzzerPin = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);    
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  myServo.attach(servoPin);
  
  lcd.init();
  lcd.backlight();
  
  
  lcd.setCursor(0, 0);
  lcd.print("ATANDS SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("READY TO SCAN");
  delay(2000);
  lcd.clear();
}

void loop() {
  
  for (int angle = 0; angle <= 180; angle += 5) {  //rotation
    checkTarget(angle);  
  }
  
  
  for (int angle = 180; angle >= 0; angle -= 5) {    //return 
    checkTarget(angle);
  }
}


long getDistance() {                              //Distance calculation
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; 
  return distance;
}


void checkTarget(int angle) {                     //motor rotation
  myServo.write(angle);
  delay(50); 
  
  long dist = getDistance();

  
  if (dist > 0 && dist <= 40) {                  //Threshold =40cm
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TARGET LOCKED!");
    lcd.setCursor(0, 1);
    lcd.print("DIST: ");
    lcd.print(dist);
    lcd.print(" cm");

    
    tone(buzzerPin, 1000);
    delay(2000); 
    noTone(buzzerPin);

    
    lcd.clear();
  } 
  else {
       
    digitalWrite(buzzerPin, LOW);               //Scanning
    lcd.setCursor(0, 0);
    lcd.print("SCANNING...    ");
    lcd.setCursor(0, 1);
    lcd.print("ANGLE: ");
    lcd.print(angle);
    lcd.print("  ");
  }
}