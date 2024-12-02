// source : https://www.gotronic.fr/pj2-guide-de-mise-en-marche-du-module-bluetooth-hc-1546.pdf

#include <SoftwareSerial.h>
#include <Servo.h>

#define rxPin 11 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 // Broche 10 en tant que TX, à raccorder sur RX du HC-05

const int servoPin = 8; // Broche connectée au servomoteur
const int sensorPin = A0; // Broche connectée au capteur de lumière

Servo monServo;  // Crée un objet servo

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  monServo.attach(servoPin);  // Connecte le servomoteur à la broche 8

  // define pin modes for tx, rx pins:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  // Bluetooth
  int i = 0;
  int someChar[32] = {0};
  // when characters arrive over the serial port...
  // if(Serial.available()) {
  //   do{
  //   someChar[i++] = Serial.read();
  //   delay(3);
  //   }while (Serial.available() > 0);
  //   mySerial.println(someChar);
  //   Serial.println(someChar);
  // }

  while(Serial.available()){
    int value = (int)Serial.read();
    mySerial.print(value);
    mySerial.print(" ");
    //Serial.print(getChar(value));
    Serial.print(char(value));
    Serial.print(" ");
  }
  while(mySerial.available()){
    int value = (int)mySerial.read();
    // on exécute une action en fonction de la valeur lue
    Serial.print((char)value);
    Serial.print(" ");
    if(value == (char)"l"){
      // on tourne vers la gauche
    }
    if(value == (char)"r"){
      // on tourne vers la droite
    }
    mySerial.print(value);
    mySerial.print(" ");
  }

  // Moteur
  int sensorValue = analogRead(sensorPin); // Lecture de la valeur du capteur
  int luminosity = map(sensorValue, 0, 1023, 100, 0); // Conversion en pourcentage de luminosité

  Serial.print("Degré de luminosité : ");
  Serial.print(luminosity);
  Serial.println("%");
 
}
