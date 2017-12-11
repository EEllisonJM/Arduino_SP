/*Declaracion e inicializacion de variables*/
/*Temporizador*/
bool encendido = false;
/*MOTORES*/
//Motor Izquierdo
int PinIN1 = 7;
int PinIN2 = 6;
//Motor Derecho
int PinIN3 = 9;
int PinIN4 = 8;


void setup() 
{
  Serial.begin(9600);//Inicializar la comunicación serial   
  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  // configuramos los pines como salida
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void adelante(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);

  digitalWrite (PinIN4, HIGH);
  digitalWrite (PinIN3, LOW);
}

void atras(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  
  digitalWrite (PinIN4, LOW);
  digitalWrite (PinIN3, HIGH);
}


void izquierda(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN4, HIGH);
  digitalWrite (PinIN3, LOW);
}

void derecha(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN4, LOW);
  digitalWrite (PinIN3, HIGH);
}

void loop() {
  if(encendido==false){
    delay(5000);
    encendido=true;
  }
  //adelante();
  //delay(500);
  //atras();
  //delay(800);
  izquierda();
  delay(400);
  derecha();
  delay(400);
}
