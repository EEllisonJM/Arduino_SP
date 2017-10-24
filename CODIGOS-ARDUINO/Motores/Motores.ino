/*- - - - - - - - -
D9 - PinIN3 - Naranja
D8 - PinIN4 - Rojo

D7 - PinIN1 - Amarillo
D6 - PinIN2 - Verde
- - - - - - - - -*/

int PinIN1 = 7;
int PinIN2 = 6;

int PinIN3 = 9;
int PinIN4 = 8;


void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  // configuramos los pines como salida
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void loop() {
  
  MotorHorario();
  Serial.println("Giro del Motor en sentido horario");
  delay(3000);

  MotorStop();
  Serial.println("Motor Detenido");
  delay(1000);
  
  MotorAntihorario();
  Serial.println("Giro del Motor en sentido antihorario");
  delay(3000);
  
  
}

void MotorHorario()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);

  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}
void MotorAntihorario()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}

void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);

  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
