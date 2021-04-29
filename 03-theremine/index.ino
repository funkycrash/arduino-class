/*
  L'exercice consiste réaliser un montage pour que la fréquence jouée un buzzer (branché sur la broche 8)  
  soit proportionnelle à la luminosité mesurée par la photorésistance (branchée sur la broche A2) : 
  plus la luminosité reçue par la photorésistance est importante, plus la fréquence jouée par le buzzer sera élevée 
  (et inversement, si on passe notre main devant le capteur de luminosité alors le son émis sera grave→fréquence basse).

  Auteur: Nicolas F.
  28 Avril 2021
 */

// Initialisation des constantes :
const int analogInPin = A2;   // Numéro de la broche à laquelle est connecté la photorésistance
const int analogOutPin = 8;   // Numéro de la broche à laquelle est connectée la LED

int sensorValue = 0;          // Valeur lue sur la photorésistance
int outputValue = 0;          // Valeur envoyée au buzzer

void setup() {
  // Initialise la communication avec l'ordinateur a 9600 bauds
  Serial.begin(9600);
  
  // Indique que la broche analogOutPin est une sortie :
  pinMode(analogOutPin, OUTPUT);      
  // Indique que la broche analogInPin est une entrée :
  pinMode(analogInPin, INPUT);     
}

void loop() {
  // lit la valeur de la photorésistance et
  // stocke le résultat dans sensorValue :
  sensorValue = analogRead(analogInPin);            
  // change sensorValue vers une intervalle de 50 à 30 000
  // et stocke le résultat dans outputValue :
  outputValue = map(sensorValue, 0, 1023, 50, 30000);  
  // envoie de cette nouvelle valeur sur le buzzer qui va jouer la frequence en Hz
  tone(8, outputValue); 
}