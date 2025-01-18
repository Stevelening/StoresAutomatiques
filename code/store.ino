// source : https://www.gotronic.fr/pj2-guide-de-mise-en-marche-du-module-bluetooth-hc-1546.pdf

#include <SoftwareSerial.h>
#include <Servo.h>

#define rxPin 11 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 // Broche 10 en tant que TX, à raccorder sur RX du HC-05

const int servoPin = 8; // Broche connectée au servomoteur
const int sensorPin = A0; // Broche connectée au capteur de lumière

const int moteurNoRotation = 85;

const int moteurUp = 10;
const int moteurDelayUp = 9000;

const int moteurDown = 10;
const int moteurDelayDown = 8500;

bool autoEnable;
int seuil;

int luminosity;
int luminosityAvg;
int nbValAvg = 5;

bool isStoreUp;


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

  isStoreUp = true;
  seuil = 50;
  luminosityAvg = 0;

  monServo.write(moteurNoRotation); 
}

void loop()
{
  getCmd();
  getLuminosity(); 
  setMoteur();
  delay(3000);
}

void getLuminosity() {
  // on récupère la luminosité
  int sensorValue = analogRead(sensorPin); // Lecture de la valeur du capteur
  luminosity = map(sensorValue, 0, 1023, 100, 0); // Conversion en pourcentage de luminosité
  debug("Degré de luminosité : ", luminosity, "%");
  luminosityAvg = (luminosityAvg * (nbValAvg - 1) + luminosity) / nbValAvg;
  debug("Degré de luminosité moyen : ", luminosityAvg, "%");

}

void setMoteur() {
  if(!autoEnable) {return;}

  // on fait tourner le moteur en fonction des paramètres
  if(luminosityAvg <= seuil) {
    storeUp();
  } else {
    storeDown();
  }
}


void storeUp() {
  if(isStoreUp) {return;}

  monServo.write(moteurNoRotation - moteurUp); 
  delay(moteurDelayUp);
  isStoreUp = true;
  monServo.write(moteurNoRotation); 
}

void storeDown() {
  if(!isStoreUp) {return;}

  monServo.write(moteurNoRotation + moteurDown); 
  delay(moteurDelayDown);
  isStoreUp = false;
  monServo.write(moteurNoRotation); 
}




void getCmd() {
  // Par Bluetooth
  while(mySerial.available()){
    char value = mySerial.read();
    Serial.print("valeur: ");
    Serial.print(value);
    Serial.println();
    
    if(value == 'm') {
      // passe en mode manuel
      autoEnable = false;
      char value = mySerial.read();
      if(value == 'u'){
        debug("Passage en mode manuel Up", -1, "");
        storeUp();
      }
      if(value == 'd'){
        debug("Passage en mode manuel Down", -1, "");
        storeDown();
      }
    }

    if(value == 'a'){
      // passe en mode automatique
      autoEnable = true;
      debug("Passage en mode automatique", -1, "");
    }

    if(value == 's') {
      // change le seuil de fermeture du mode automatique
      int value = (int)mySerial.read();
      seuil = value;
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