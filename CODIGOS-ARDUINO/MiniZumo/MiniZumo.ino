//Declaracion de variables(pines)
//cny70
int cnyI = 10;
int cnyD = 2;
//Ultrasónico
const int pinecho = 11;
const int pintrigger = 12;
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
  Serial.print(distancia);
  Serial.println(" cm");
  delay(200);
}

void adelante(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);

  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}

void atras(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}

void izquierda(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}

void derecha(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}

void rotar(){
  derecha();
  delay(500);
}

void loop() 
{
  valor_cnyI=digitalRead(cnyI);//Leer y almacenar el valor del sensor
  valor_cnyD=digitalRead(cnyD);//Leer y almacenar el valor del sensor
  delay(50);//Esperar 50 ms 
  //1=Blanco
  //0=Negro
  if(valor_cnyD==1&&valor_cnyI==1)
  {
    Serial.print("Linea blanca Ambos\n");//Imprimir en el monitor serial "linea blanca ambos"
    atras();
    delay(200);
    
    rotar();
    delay(300);
  } else {
    if(valor_cnyI==1&&valor_cnyD==0)
    {
      Serial.print("Linea blanca Izquierda\n");
      derecha();
      delay(200);
    }
    if(valor_cnyD==1&&valor_cnyI==0)
    {
      Serial.print("Linea blanca Derecha\n");
      izquierda();
      delay(200);
    }
  }
  
  ultrasonico();
  
  if (distancia <= 15) {//<= 60) {
    adelante();
    delay(500);
  } else {
    rotar();
    delay(500);
  }
}
