// source https://arduino-france.site/servo-arduino/
// source https://arduino.developpez.com/tutoriels/arduino-a-l-ecole/?page=projet-12-utiliser-un-servomoteur
/*
// code
#include <Servo.h>

Servo monServo;  // Crée un objet servo

void setup() {
  monServo.attach(9);  // Connecte le servomoteur à la broche 9
}

void loop() {
  // Tourner dans le sens des aiguilles d'une montre
  for (int position = 0; position <= 180; position += 1) {
    monServo.write(position);  // Définit la position du servomoteur
    delay(15);  // Attendre que le servomoteur atteigne la position
  }

  // Tourner dans le sens inverse des aiguilles d'une montre
  for (int position = 180; position >= 0; position -= 1) {
    monServo.write(position);  // Définit la position du servomoteur
    delay(15);  // Attendre que le servomoteur atteigne la position
  }
}

#include <math.h>

//const int ledPin = 9; // Broche connectée à la LED
const int sensorPin = A0; // Broche connectée au capteur de lumière

int ldrPin = A0;  // Pin du capteur de lumière

void setup() {
  Serial.begin(9600);    // Initialise la communication série
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Lit la valeur du LDR
  
  // Conversion de la valeur analogique (0-1023) à un degré de luminosité (0-100)
  int luminosity = map(ldrValue, 0, 1023, 100, 0);
  
  // Affiche la valeur de luminosité
  Serial.print("Degré de luminosité : ");
  Serial.print(luminosity);
  Serial.println("%");

  delay(1000);  // Attente de 1 seconde avant la prochaine lecture
}
*/

#include <Servo.h>

const int servoPin = 8; // Broche connectée au servomoteur
const int sensorPin = A0; // Broche connectée au capteur de lumière

Servo monServo;  // Crée un objet servo

void setup() {
  monServo.attach(servoPin);  // Connecte le servomoteur à la broche 8
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Lecture de la valeur du capteur
  int luminosity = map(sensorValue, 0, 1023, 100, 0); // Conversion en pourcentage de luminosité

  Serial.print("Degré de luminosité : ");
  Serial.print(luminosity);
  Serial.println("%");

  if (luminosity > 70) {
    // Servomoteur à 0 degrés (ou une autre position "avant")
    monServo.write(0); 
  } else if (luminosity < 40) {
    // Servomoteur à 180 degrés (ou une autre position "arrière")
    monServo.write(180); 
  } else {
    // Servomoteur à 90 degrés (ou une autre position "statique")
    monServo.write(90); 
  }

  delay(100); // Délai pour la fluidité
}