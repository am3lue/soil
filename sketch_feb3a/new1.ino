#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// RS485 sensor pins
int rxPin = 2;
int txPin = 3;

// RS485 sensor object
SoftwareSerial rs485(rxPin, txPin);

// LCD object
LiquidCrystal_I2C lcd(0x27, 16, 4);

// Soil sensor command bytes
byte readSoilMoistureCmd[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0x84, 0x0A};
byte readSoilTemperatureCmd[] = {0x01, 0x03, 0x00, 0x02, 0x00, 0x02, 0xC4, 0x0B};
byte readSoilLightCmd[] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x02, 0x04, 0x0C};
byte readSoilPHCmd[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x02, 0x44, 0x0E};

void setup() {
  Serial.begin(9600);
  rs485.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Simulate reading sensor data
  int soilMoisture = 50;
  int soilTemperature = 20;
  int soilLight = 500;
  int soilPH = 6;

  // Display the results on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil pH: ");
  lcd.print(soilPH);

  // Provide recommendations based on sensor data
  if (soilMoisture < 30) {
    lcd.setCursor(0, 4);
    lcd.print("Water the plant");
  } else if (soilMoisture > 70) {
    lcd.setCursor(0, 4);
    lcd.print("Reduce watering");
  } else {
    lcd.setCursor(0, 4);
    lcd.print("Soil moisture is good");
  }

  if (soilTemperature < 15 || soilTemperature > 30) {
    lcd.setCursor(0, 5);
    lcd.print("Adjust temperature");
  } else {
    lcd.setCursor(0, 5);
    lcd.print("Temperature is good");
  }

  if (soilPH < 6 || soilPH > 7) {
    lcd.setCursor(0, 6);
    lcd.print("Adjust soil pH");
  } else {
    lcd.setCursor(0, 6);
    lcd.print("Soil pH is good");
  }

  delay(2000); // Wait for 2 seconds before the next "reading"
}
