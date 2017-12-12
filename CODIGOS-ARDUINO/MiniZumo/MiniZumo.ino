/*Declaracion e inicializacion de variables*/
/*Temporizador*/
bool encendido = false;
/*SENSOR OPTICO CNY70*/
int cnyI = 2;//Color - Cafe
int cnyD = 10;//Color - Azul

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
  //Serial.begin(9600);//Inicializar la comunicación serial 
  
  pinMode(cnyI, INPUT);//Definir el pin como entrada del sensor
  pinMode(cnyD, INPUT);//Definir el pin como entrada del sensor
  
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  
  // configuramos los pines como salida
  /*MOTOR IZQUIERDO*/
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  // configuramos los pines como salida
  /*MOTOR DERECHO*/
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void ultrasonico(){
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  //Serial.print(distancia);
  //Serial.println(" cm");
  delay(10);//
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
  /*1. Esperar 5 segundos.*/
  if(encendido==false){
    delay(5000);
    encendido=true;
  }
  
  /*2. Leer valor de los sensores opticos CNY70.*/
  valor_cnyI=digitalRead(cnyI);//Leer y almacenar el valor del sensor
  valor_cnyD=digitalRead(cnyD);//Leer y almacenar el valor del sensor
  
  //1=Blanco
  //0=Negro
  /*3. Si ambos sensores detectan color Blanco*/
  if(valor_cnyI == 1 && valor_cnyD == 1){
    //Serial.print("Linea blanca Ambos\n");//Imprimir en el monitor serial "linea blanca ambos"
    atras();
    delay(300);
    
  }
  /*3. Si sensor izquierdo detecta blanco*/
  if(valor_cnyI == 1 && valor_cnyD == 0){
    //Serial.print("Linea blanca Izquierda\n");
    izquierda();
    delay(60);
    atras();
    delay(300);
  }
  /*4. Si sensor derecho detecta blanco*/
  if(valor_cnyD == 1 && valor_cnyI == 0){
    //Serial.print("Linea blanca Derecha\n");
    derecha();
    delay(30);
    atras();
    delay(300);
  }
  
  ultrasonico();
  if (distancia <= 50 || distancia > 400) {
    adelante();
    delay(30);
  } else {
    rotar();
    delay(30);
  }
}
