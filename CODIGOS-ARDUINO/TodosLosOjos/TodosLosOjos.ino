//Declaracion de variables(pines)
//cny70
int cnyI = 2;//Cafe
int cnyD = 10;//Azul Marino
//Ultrasónico
const int pinecho = 11;//Verde
const int pintrigger = 12;//Azul marino
//Declaracion de variables
int valor_cnyI = 0;
int valor_cnyD = 0;
// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;

void setup() 
{
  Serial.begin(9600);//Inicializar la comunicación serial 
  pinMode(cnyI, INPUT);//Definir el pin como entrada del sensor
  pinMode(cnyD, INPUT);//Definir el pin como entrada del sensor
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
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
    delay(200);
  } else{
    if(valor_cnyI==1&&valor_cnyD==0)
    {
      Serial.print("Linea blanca Izquierda\n");//Imprimir en el monitor serial "linea blanca Izquierda"
      delay(200);
    }
    if(valor_cnyD==1&&valor_cnyI==0)
    {
      Serial.print("Linea blanca Derecha\n");//Imprimir en el monitor serial "linea blanca Derecha"
      delay(200);
    }
  }
  ultrasonico();
  // ENCENDER EL LED CUANDO SE CUMPLA CON CIERTA DISTANCIA
  if (distancia <= 10) {//<= 60) {
    digitalWrite(LED_BUILTIN, HIGH);
    //delay(500);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
