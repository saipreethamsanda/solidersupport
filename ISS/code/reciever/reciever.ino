#include <SoftwareSerial.h>

// Define RX and TX pins for HC-12 communication
SoftwareSerial hc12(10, 11); // RX on pin 10, TX on pin 11

void setup() {
  // Start communication with Serial Monitor
  Serial.begin(9600);
  
  // Start communication with HC-12 module
  hc12.begin(9600); // HC-12 default baud rate is 9600
}

void loop() {
  // Check if HC-12 has received any data
  if (hc12.available()) {
    String receivedData = "";
    
    // Read incoming data from HC-12
    while (hc12.available()) {
      receivedData += (char)hc12.read();
    }
    
    // Display the received data on Serial Monitor
    Serial.print("Data received: ");
    Serial.println(receivedData);
  }
}
