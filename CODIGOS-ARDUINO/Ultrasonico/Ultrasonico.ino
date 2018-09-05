/*
 D12 - Azul marino
 D11 - Verde
 +5V - Rojo
 GND - Negro
 */
const int pinOUT_Trigger = 12;
const int pinIN_Echo = 11;
long tiempo_ida_y_vuelta;

void setup() {
  pinMode(pinOUT_Trigger, OUTPUT);
  pinMode(pinIN_Echo, INPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  long distancia=CalcularDistanciaUltrasonico();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
}
long CalcularDistanciaUltrasonico(){
  // Clears the pinOUT_Trigger
  digitalWrite(pinOUT_Trigger, LOW);
  delayMicroseconds(2);

  // Sets the pinOUT_Trigger on HIGH state for 10 micro seconds
  digitalWrite(pinOUT_Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinOUT_Trigger, LOW);

  // Reads the pinIN_Echo, returns the sound wave travel time in microseconds
  tiempo_ida_y_vuelta = pulseIn(pinIN_Echo, HIGH);

  if(tiempo_ida_y_vuelta >= 3000 ){//Mas de 50CM
    return 0;
  }


  return CalcularDistanciaSensorUltrasonico(tiempo_ida_y_vuelta);
}

long CalcularDistanciaSensorUltrasonico(long tiempo_ida_y_vuelta){
  /*
    _______________________________________________
   |-----------------------------------------------|
   |                FORMULA GENERAL                |
   |-----------------------------------------------|
   |         Velocidad = Distancia/Tiempo          |
   |-----------------------------------------------|   
   |Velocidad del sonido =  340 m/s = 0.034 cm/µs  |
   |-----------------------------------------------|
   |  Distancia = Velocidad * Tiempo               |
   |-----------------------------------------------|
   |  Distancia = tiempo_ida_y_vuelta * (velocidad del sonido)  |
   |-----------------------------------------------|
   Nota: Como solo estamos calculando la distancia de ida,
   y el sensor HC-SR04 Manda un pulso de ida y regreso, 
   dividimos entre dos y obtenemos la distancia correcta.
   */
  return (tiempo_ida_y_vuelta * 0.034) / 2;
}

