#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
DHT dht(A0, DHT11);
const int sensorPin= A1;
int smoke_level;
int maximum=600;
void setup()
{
  Serial.begin(9600);
  dht.begin(); 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");

}


void loop() {
Serial.println(smoke_level);

 float h = dht.readHumidity();
 float t = dht.readTemperature();
 Serial.println("tempatura");
Serial.println(t);
Serial.println("humiditiit");
Serial.println(h);
smoke_level= analogRead(sensorPin);
if (smoke_level < maximum)
{
if (smoke_level >= 0 && smoke_level <= 250)
{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("All okay"); // Выводим текст
lcd.setCursor(0, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("hum");
lcd.print(h);
lcd.setCursor(6, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("temp");
lcd.print(t); // Выводим текст
delay(1000);
}
if (smoke_level > 251 && smoke_level <= 450)
{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Be careful"); // Выводим текст
lcd.setCursor(0, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("hum");
lcd.print(h);
lcd.setCursor(6, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("temp");
lcd.print(t); // Выводим текст
delay(1000);
}
if (smoke_level > 451 && smoke_level <= 599)
{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("DANDER, BE CAREFUL!!!!"); // Выводим текст
lcd.setCursor(0, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("hum");
lcd.print(h);
lcd.setCursor(6, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("temp");
lcd.print(t); // Выводим текст
delay(1000);
}
delay(100);
}
if (smoke_level > maximum)
{
  lcd.clear();
lcd.setCursor(0, 0); // Устанавливаем курсор в начало 1 строки
lcd.print("Danger! Danger! Danger!");
lcd.setCursor(0, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("Danger! Danger! Danger!");
}
delay(100);
}
