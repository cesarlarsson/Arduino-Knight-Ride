
//Definir los pines de donde conectaremos los leds
byte ledPin[] = {8, 9, 10, 11, 12, 13};

long timeChanged = 0;
//Velocidad inicial
int delayTime = 200;
int currentLED = 0;
//Variable que controla la direccion
int dir = 1;
//Setup
void setup() {
  //Puerto para enviar datos (para escribir lo que esta pasando)
  Serial.begin(9600);
  for (int i=0; i<6; i++) {
      pinMode(ledPin[i], OUTPUT);
    } 
   timeChanged = millis();
}
//Loop
void loop() {

    //Definimos cuando se ejecuta el cambio de luz
    if ((millis() - timeChanged) > delayTime) { 
      
      for (int i=0; i<6; i++) {
        digitalWrite(ledPin[i], LOW);
      }   
      digitalWrite(ledPin[currentLED], HIGH); 
      currentLED = currentLED + dir;      
      if (currentLED ==5) {
        dir=-1;
      }
      if(currentLED ==0){
        dir=1;
      }
      timeChanged = millis();
    }
    //Leemos el potenciometro
    delayTime= analogRead(0);
    Serial.println("Velocidad ");
     Serial.println(delayTime);
    
    delay(5);
    
}
