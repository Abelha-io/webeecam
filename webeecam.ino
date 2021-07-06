//Programa: Contador de abelhas com sensor reflexivo e Arduino
//Autor: Gustavo Lassala - Meliponário Tapajós

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27, 16,2);
int pino_sensor = 7;
int valor = 1; //Variavel leitura sensor
int contador = 0;
void setup()
{
lcd.backlight(); //acende o monitor lcd
  Serial.begin(9600);
  //Define o pino do sensor como entrada
  pinMode(pino_sensor, INPUT);
  //Inicializa o display LCD 16x2 I2C
  lcd.init();
  //informacoes iniciais
  lcd.setCursor(0, 0);
  lcd.print("Sensor indutivo");
  lcd.setCursor(0, 1);
  lcd.print("Contador: 0");
  Serial.println("Meliponario Tapajos");
}
void loop()
{
  //Le o pino do sensor
  valor = digitalRead(pino_sensor);
  //Verifica se algum objeto foi detectado (valor = 0)
  if (valor == 0)
  {
    //Incrementa o contador
    contador++;
    //Mostra o valor do contador no display
    lcd.setCursor(10, 1);
    lcd.print(contador);
    //Mostra o valor do contador no serial monitor
    Serial.print("Contador: ");
    Serial.println(contador);
    //Loop caso o objeto fique parado em frente ao sensor
    while (digitalRead(pino_sensor) == 0)
    {
      delay(100);
    }
  }
}

