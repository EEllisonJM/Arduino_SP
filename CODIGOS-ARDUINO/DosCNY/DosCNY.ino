//Declaracion de variables(pines)
//cny70
int cnyI = 10;
int cnyD = 2;

//Declaracion de variables
int valor_cnyI = 0;
int valor_cnyD = 0;

void setup() 
{
  Serial.begin(9600);//Inicializar la comunicación serial 
  pinMode(cnyI, INPUT);//Definir el pin como entrada del sensor
  pinMode(cnyD, INPUT);//Definir el pin como entrada del sensor
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
}
