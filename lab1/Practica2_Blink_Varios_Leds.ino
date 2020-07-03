//Practica para apagar y encender varios LEDs
int pulsador = 2;
int led[] = {3, 4, 5, 6, 7};
int numLeds = 5;
int tiempoRetardo = 400;
int pinSalida;

void setup() {
  // put your setup code here, to run once:
  pinMode(pulsador, INPUT);
  for (pinSalida = 0; pinSalida < numLeds; pinSalida++)
  {
    pinMode(led[pinSalida], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean estadoPulsador = digitalRead(pulsador);
  if (estadoPulsador)
  {
    for (pinSalida = 0; pinSalida < numLeds; pinSalida++)
    {
      digitalWrite(led[pinSalida], HIGH);
    }
    delay(tiempoRetardo);

    for (pinSalida = 0; pinSalida < numLeds; pinSalida++)
    {
      digitalWrite(led[pinSalida], LOW);
    }
    delay(tiempoRetardo);
  }
}
