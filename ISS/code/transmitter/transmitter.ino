#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial hc12(10, 11); // HC-12 RX, TX
SoftwareSerial gpsSerial(4, 5); // GPS RX, TX

#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

int heartbeatPin = A0; // Analog pin connected to the HW827 heart rate sensor
const int buttonPin = 3; // Pin connected to the pushbutton

int buttonState = 0;

// GPS setup
TinyGPS gps;
long latitude, longitude;
float flat, flon;

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  lcd.init();           // Initialize the LCD
  lcd.backlight();      // Turn on the backlight
  hc12.begin(9600);     // Initialize HC-12 communication
  gpsSerial.begin(9600); // Initialize GPS communication
  pinMode(buttonPin, INPUT_PULLUP); // Setup button
  dht.begin();          // Initialize DHT sensor
}

void loop() {
  // Read heart rate data
  int heartbeatValue = analogRead(heartbeatPin);
  int heartRate = map(heartbeatValue, 0, 1023, 0, 200); // Assuming sensor outputs values between 0 and 1023
  buttonState = digitalRead(buttonPin);

  // Read temperature data
  float temperature = dht.readTemperature();
  float temperatureF = (temperature * 9.0 / 5.0) + 32.0; // Fahrenheit conversion

  // Read GPS data
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    if (gps.encode(c)) {
      gps.f_get_position(&flat, &flon);
    }
  }

  // Display data on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HR: ");
  lcd.print(heartRate); // Subtracting 20 as in the original code
  lcd.print(" bpm");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print(" F");

  // Print GPS data to LCD if valid
  if (flat != TinyGPS::GPS_INVALID_F_ANGLE && flon != TinyGPS::GPS_INVALID_F_ANGLE) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lat: ");
    lcd.print(flat, 6);

    lcd.setCursor(0, 1);
    lcd.print("Lon: ");
    lcd.print(flon, 6);
  }

  // Print data to serial monitor
  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.print(" bpm, Temperature: ");
  Serial.print(temperatureF);
  Serial.print(" F, Latitude: ");
  Serial.print(flat, 6);
  Serial.print(", Longitude: ");
  Serial.println(flon, 6);

  // Transmit data via HC-12 if button is pressed
  if (buttonState == LOW) {
    hc12.print("Heart Rate: ");
    hc12.print(heartRate);
    hc12.print(" bpm, Temp: ");
    hc12.print(temperatureF);
    hc12.print(" F, Lat: ");
    hc12.print(flat, 6);
    hc12.print(", Lon: ");
    hc12.println(flon, 6);
  }

  // Check if heart rate is above 110
  if (heartRate > 110) {
    hc12.print("Heart Rate: ");
    hc12.print(heartRate);
    hc12.print(" bpm, Temp: ");
    hc12.print(temperatureF);
    hc12.print(" F, Lat: ");
    hc12.print(flat, 6);
    hc12.print(", Lon: ");
    hc12.println(flon, 6);
  }

  // Check if temperature is above 101 Fahrenheit
  if (temperatureF > 101) {
    hc12.print("Heart Rate: ");
    hc12.print(heartRate);
    hc12.print(" bpm, Temp: ");
    hc12.print(temperatureF);
    hc12.print(" F, Lat: ");
    hc12.print(flat, 6);
    hc12.print(", Lon: ");
    hc12.println(flon, 6);
  }

  delay(2500); // Delay for readability
}
