/*- - - - - - - - -
 D9 - PinIN3 - Rojo
 D8 - PinIN4 - Naranja
 D7 - PinIN1 - Amarillo
 D6 - PinIN2 - Verde
 - - - - - - - - -*/
//Motor Izquierdo
int PinIN1 = 7;
int PinIN2 = 6;

//Motor Derecho
int PinIN3 = 8;
int PinIN4 = 9;


void setup() {
  // Inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // Configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  // Configuramos los pines como salida
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void loop() {  

  GirarMotoresHorario(1000);
  /*DetenerMotores(500);
   GirarMotoresAntihorario(1000);
   DetenerMotores(500);
   MotorIzquierdoAdelante(3000);
   DetenerMotorIzquierdo(1000);
   MotorIzquierdoAtras(3000);
   DetenerMotorIzquierdo(1000);
   
   MotorDerechoAdelante(3000);
   DetenerMotorDerecho(1000);
   MotorDerechoAtras(3000);
   DetenerMotorDerecho(1000);*/
}

/*CONTROL AMBOS MOTORES*/
void MotoresAdelante(int tiempo_en_segundos){
  MotorIzquierdoAdelante();
  MotorDerechoAdelante();
  delay(tiempo_en_segundos);
}
void MotoresAtras(int tiempo_en_segundos){
  MotorIzquierdoAtras();
  MotorDerechoAtras();
  delay(tiempo_en_segundos);
}
void DetenerMotores(int tiempo_en_segundos){
  DetenerMotorIzquierdo();
  DetenerMotorDerecho();
  delay(tiempo_en_segundos);
}
void GirarMotoresHorario(int tiempo_en_segundos){
  MotorIzquierdoAdelante();
  MotorDerechoAtras();
  delay(tiempo_en_segundos);
}
void GirarMotoresAntihorario(int tiempo_en_segundos){
  MotorIzquierdoAtras();
  MotorDerechoAdelante();
  delay(tiempo_en_segundos);
}

/*CONTROL MOTOR DERECHO SIN PARAMETROS*/
void MotorDerechoAtras(){
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}
void MotorDerechoAdelante(){
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}
void DetenerMotorDerecho(){
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}

/*CONTROL MOTOR DERECHO CON PARAMETROS*/
void MotorDerechoAtras(int tiempo_en_segundos){
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  delay(tiempo_en_segundos);
}
void MotorDerechoAdelante(int tiempo_en_segundos){
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  delay(tiempo_en_segundos);
}
void DetenerMotorDerecho(int tiempo_en_segundos){
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
  delay(tiempo_en_segundos);
}

/*CONTROL MOTOR IZQUIERDO SIN PARAMETROS*/
void MotorIzquierdoAtras(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
}
void MotorIzquierdoAdelante(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
}
void DetenerMotorIzquierdo(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
}

/*CONTROL MOTOR IZQUIERDO CON PARAMETROS*/
void MotorIzquierdoAtras(int tiempo_en_segundos){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  delay(tiempo_en_segundos);
}
void MotorIzquierdoAdelante(int tiempo_en_segundos){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  delay(tiempo_en_segundos);
}
void DetenerMotorIzquierdo(int tiempo_en_segundos){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  delay(tiempo_en_segundos);
}







