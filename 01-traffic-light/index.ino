// La consigne est la suivante : à partir des fonctions vues dans l'exemple Blink et des bases d'électroniques décrites cette semaine, vous devez réaliser un feu tricolore avec trois LED (une verte→broche 4, une orange→broche 3, une rouge→broche 2) qui devront être allumées comme suit :

// Les broches 2, 3 et 4 doivent être placées en OUTPUT
// Verte allumée pendant 3 secondes (la LED verte devra être la première LED à s'allumer)
// Orange allumée pendant 1 seconde (comme dans la vraie vie, verte devra s'éteindre et la LED orange s'allume en second)
// Rouge allumée pendant 3 secondes (après orange, on passe au rouge)
// Cette séquence devra être exécutée encore et encore en utilisant le bloc loop()!


int GREEN = 4;
int YELLOW = 3;
int RED = 2;

void turnLightOn(int led, int duration) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(duration);           // wait for x miliseconds
    digitalWrite(led, LOW); 
}

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  turnLightOn(GREEN, 3000);
  turnLightOn(YELLOW, 1000);
  turnLightOn(RED, 3000);
}

