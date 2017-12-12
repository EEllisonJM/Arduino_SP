/*Declaracion e inicializacion de variables*/
/*Temporizador*/
bool encendido = false;
/*SENSOR OPTICO CNY70*/
int cnyI = 2;//Color - Cafe
int cnyD = 10;//Color - Azul

bool izquier = false;

/*SENSOR ULTRASONICO HC-SR04*/
const int pinecho = 11;//Color - Verde
const int pintrigger = 12;//Color - Azul

/*MOTORES*/
//Motor Izquierdo
int PinIN1 = 7;
int PinIN2 = 6;
//Motor Derecho
int PinIN3 = 9;
int PinIN4 = 8;

//Declaracion de variables
int valor_cnyI = 0;
int valor_cnyD = 0;
//Variables para cálculos
unsigned int tiempo, distancia;

void setup() 
{
  Serial.begin(9600);//Inicializar la comunicación serial 
  
  pinMode(cnyI, INPUT);//Definir el pin como entrada del sensor
  pinMode(cnyD, INPUT);//Definir el pin como entrada del sensor
  
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  
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

void rotar(){
  derecha();
  delay(30);
}

void loop() 
{//Siguiendo la logica del diagrama de flujo  
  /*2. Leer valor de los sensores opticos CNY70.*/
  valor_cnyI=digitalRead(cnyI);//Leer y almacenar el valor del sensor
  valor_cnyD=digitalRead(cnyD);//Leer y almacenar el valor del sensor
  
  //1=Blanco
  //0=Negro
  
  if(valor_cnyD == 1){
      izquierda();
      delay(30);
  }
  /*4. Si sensor derecho detecta blanco*/
  if(valor_cnyI == 1){
      derecha();
      delay(30);
  }
  
  adelante();
    delay(30);
}
