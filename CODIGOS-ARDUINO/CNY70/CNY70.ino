/*
Talos Electronics
8-Noviembre-2015
Rafael lozano Rolón 
*/
//Declaracion de variables
int sensor = 2;
int Valor_cny70 = 0;
//int Led=3;

void setup() 
{
  Serial.begin(9600);//Inicializar la comunicación serial 
  pinMode(sensor, INPUT);//Definir el sensor(pin2) como entrada
  pinMode(LED_BUILTIN, OUTPUT);//Definir el led(pin3) como salida 
  digitalWrite(LED_BUILTIN, LOW);//Iniciar con el led apagado
}

void loop() 
{
  Valor_cny70=digitalRead(sensor);//Leer y almacenar el valor del sensor 
  delay(50);//Esperar 100 ms 
  if(Valor_cny70==0)//si el valor es cero
  {
    Serial.print("Linea negra\n");//Imprimir en el monitor serial "linea negra"
    digitalWrite(LED_BUILTIN, LOW);//Apagar el Led
  }
  else//Si el valor del sensro es 1
  {
    Serial.print("Linea blanca\n");//Imprimir en el monitor serial "linea blanca"
    digitalWrite(LED_BUILTIN, HIGH);//Encender el led
  }
}
