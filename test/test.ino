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
 
  bool autoEnable;
  int height; // 0 pas de store ; 100 plein store ;
  int seuil; // seuil a définir par default
  getCmd(&autoEnable, &height, &seuil);

  int luminosity;
  getLuminosity(&luminosity); 

  setMoteur(autoEnable, height, seuil, luminosity);
  
  delay(3000);
}

void setMoteur(bool autoEnable, int height, int seuil, int luminosity) {
  // on fait tourner le moteur en fonction des paramètres
  if(autoEnable) {
    monServo.write(seuil); 
  } else {
    monServo.write(88); 
  }
}

void getLuminosity(int * luminosity) {
  // on récupère la luminosité
  int sensorValue = analogRead(sensorPin); // Lecture de la valeur du capteur
  *luminosity = map(sensorValue, 0, 1023, 100, 0); // Conversion en pourcentage de luminosité
  debug("Degré de luminosité : ", *luminosity, "%");
}

void getCmd(bool* autoEnable, int* height, int* seuil) {
  // Par Bluetooth
  while(mySerial.available()){
    char value = mySerial.read();
    Serial.print("valeur: ");
    Serial.print(value);
    Serial.println();
    
    if(value == 'm') {
      // passe en mode manuel
      *autoEnable = false;
      debug("Passage en mode manuel", -1, "");
    }

    if(value == 'h') {
      // change la hauteur du store en mode manuel
      int value = (int)mySerial.read();
      *height = value;
      debug("Reglage de la hauteur à : ", value, "");
    }

    if(value == 'a'){
      // passe en mode automatique
      *autoEnable = true;
      debug("Passage en mode automatique", -1, "");
    }

    if(value == 's') {
      // change le seuil de fermeture du mode automatique
      int value = (int)mySerial.read();
      *seuil = value;
      debug("Reglage du seuil à : ", value, "");
    }
  }
}


void debug(char * message, int value, char * unite) {
  Serial.print(message);
  if(value != -1) {
    Serial.print(value);
  }
  Serial.println(unite);
}