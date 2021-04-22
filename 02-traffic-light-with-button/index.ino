
// Mon code est en Anglais car c'est plus consistant avec le language de programmation
// Auteur: Nicolas F.
// 21-Avril-2021

// On initialise les constantes ici (en majuscule pour plus de clarté dans le code) ici
const int GREEN_CAR = 10;
const int YELLOW_CAR = 11;
const int RED_CAR = 12;
const int RED_PEDESTRIAN = 9;
const int GREEN_PEDESTRIAN = 8;
const int BUTTON = 2;

// On assigne une valeur initiale a cette variable qui va changer plus tard
int buttonState = 0;


// Declaration de fonction pour eteindre la LED
void turnLightOff(int led) {
    digitalWrite(led, LOW);
}

// Declaration de fonction pour allumer la LED
void turnLightOn(int led) {
    digitalWrite(led, HIGH);
}

// Declaration d'une fonction qui verifie si le bouton est enclenché
void checkPedestrianLight() {
  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    // Si c'est enclenché on commence la logique pièton
    turnLightOff(GREEN_CAR);
    
    turnLightOn(YELLOW_CAR);
    delay(1000);
    turnLightOff(YELLOW_CAR);

    turnLightOn(RED_CAR);
    turnLightOff(RED_PEDESTRIAN);
    turnLightOn(GREEN_PEDESTRIAN);
    delay(5000);
    turnLightOn(RED_PEDESTRIAN);
    turnLightOff(GREEN_PEDESTRIAN);
    turnLightOff(RED_CAR);

    // une fois la logique piéton terminée on allume le feu vert pour les voitures et on continue
    turnLightOn(GREEN_CAR);
    delay(3000);
    turnLightOff(GREEN_CAR);
  } else {
    // Sinon on allume le feu vert pour les voitures comme d'habitude
    turnLightOn(GREEN_CAR);
    delay(3000);
    turnLightOff(GREEN_CAR);
  }
}

void setup() {
  // On initialise le montage
  pinMode(GREEN_CAR, OUTPUT);
  pinMode(YELLOW_CAR, OUTPUT);
  pinMode(RED_CAR, OUTPUT);
  pinMode(RED_PEDESTRIAN, OUTPUT);
  pinMode(GREEN_PEDESTRIAN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // Par defaut le feu est rouge pour les piétons
  turnLightOn(RED_PEDESTRIAN);
  
  // On regarde si le feu est au vert et on vérifie l'état du bouton
  checkPedestrianLight();
  
  turnLightOn(YELLOW_CAR);
  delay(1000);
  turnLightOff(YELLOW_CAR);

  turnLightOn(RED_CAR);
  delay(3000);
  turnLightOff(RED_CAR);
}
