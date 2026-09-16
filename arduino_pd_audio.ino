#include <Arduino.h> 
#include <Bounce2.h>

Bounce2::Button bouton1; //classe bouton
Bounce2::Button bouton2; //classe bouton

#define BROCHE_BOUTON1 2 //D2 sur l'arduino
#define BROCHE_BOUTON2 7 //D7 sur l'arduino
#define BROCHE_DEL1 3 //D3 sur l'arduino

bool etatBtn = LOW;
bool etatDel1 = LOW;

void setup() {
  Serial.begin(115200); //Initalize la vitesse de communication 

  // Configuration des boutons
  bouton1.attach(BROCHE_BOUTON1, INPUT_PULLUP); //Attache le bouton à la broche
  bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP); //Attache le bouton à la broche
  //pinMode(BROCHE_BOUTON, INPUT_PULLUP);
  bouton1.setPressedState (LOW);
  bouton2.setPressedState (LOW);

  // Configuration de la DEL
   pinMode(BROCHE_DEL1, OUTPUT);
   digitalWrite(BROCHE_DEL1, etatDel1); //Pour que la lumière soit éteinte au démarrage. Envoi 0 volts au DEL.
}

void loop() { 
    
    bouton1.update(); //Met à jour l'état du bouton
    bouton2.update(); //Met à jour l'état du bouton

    if (bouton1.isPressed()) {
        Serial.print("bouton1"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne

    } 
    
    if (bouton2.pressed()) {
        Serial.print("bouton2"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(2); // Valeur
        Serial.println(); // Saut de ligne

            //etatDel2 = LOW;
    }

    

    //Serial.print("TEMP ");  // Envoie le descripteur et son espace en un seul bloc
    //Serial.println(23); // Envoie la valeur et ajoute automatiquement le saut de ligne final
}



/*

#include <Arduino.h>
#include <Chrono.h>
#include <Bounce2.h>
 
#define BROCHE_DEL 3
#define BROCHE_BOUTON 2
 
#define INTERVALLE 500
 
Bounce2::Button bouton = Bounce2::Button();
Chrono minuterieDel;
 
bool etatDel = LOW;
bool clignotementActif = false;
 
void setup()
{
    // Configuration de la DEL
    pinMode(BROCHE_DEL, OUTPUT);
    digitalWrite(BROCHE_DEL, etatDel);
 
    // Configuration du bouton
    bouton.attach(BROCHE_BOUTON, INPUT_PULLUP);
    bouton.setPressedState(LOW);
}
 
void loop()
{
    // Mise à jour du bouton
    bouton.update();
 
    // Gestion de l'événement de pression
    if (bouton.pressed())
    {
        if (clignotementActif) {
            clignotementActif = false;
        } else {
             clignotementActif = true;
        }
    }
 
    // Gestion indépendante du clignotement
    if (clignotementActif) {
        if ( minuterieDel.hasPassed(INTERVALLE))
        {
            minuterieDel.restart();
 
            if ( etatDel == 0 ) {
                etatDel = 1;
            } else {
                etatDel = 0;    
            }
           
        }
    }
 
    digitalWrite(BROCHE_DEL, etatDel);
}











#include <Arduino.h>
#include <Bounce2.h>
 
#define TOGGLE_BUTTON_PIN 2
#define TOGGLE_LIGHT_PIN 3
#define TOGGLE_PREFIX "bouton0"
 
#define MOMENTARY_BUTTON_PIN 4
#define MOMENTARY_LIGHT_PIN 5
#define MOMENTARY_PREFIX "bouton1"
 
#define BAUD 115200
 
Bounce2::Button toggleButton = Bounce2::Button();
Bounce2::Button momentaryButton = Bounce2::Button();
 
bool toggleState = LOW;
 
void setup() {
  // LED config
  pinMode(TOGGLE_LIGHT_PIN, OUTPUT);
  digitalWrite(TOGGLE_LIGHT_PIN, toggleState);
  pinMode(MOMENTARY_LIGHT_PIN, OUTPUT);
  digitalWrite(MOMENTARY_LIGHT_PIN, LOW);
 
  // button config
  toggleButton.attach(TOGGLE_BUTTON_PIN, INPUT_PULLUP);
  toggleButton.setPressedState(LOW);
 
  momentaryButton.attach(MOMENTARY_BUTTON_PIN, INPUT_PULLUP);
  momentaryButton.setPressedState(LOW);
 
  // serial config
  Serial.begin(BAUD);
}
 
void loop() {
  toggleButton.update();
  momentaryButton.update();
 
  if (toggleButton.pressed()) {
    toggleState = !toggleState;
 
    digitalWrite(TOGGLE_LIGHT_PIN, toggleState);
 
    Serial.print(TOGGLE_PREFIX);
    Serial.print(" ");
    if(toggleState) {
        Serial.print("1");
    } else{
        Serial.print("0");
    }
    Serial.println();
  }
 
  if (momentaryButton.pressed()) {
 
    digitalWrite(MOMENTARY_LIGHT_PIN, HIGH);
 
    Serial.print(MOMENTARY_PREFIX);
    Serial.println(" 1");
 
  } else if (momentaryButton.released()) {
    digitalWrite(MOMENTARY_LIGHT_PIN, LOW);
  }
 
}
*/
