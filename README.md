![Viewers](https://hits.sh/github.com/saipreethamsanda/solidersupport.svg?style=flat-square&label=Viewers)

This project proposes a wireless embedded system through which the defence services can provide our soldiers with highly secure safety. In this system, army base stations can monitor soldiers' heart rate and body temperature using sensors such as temperature and heart rate sensors. The base stations can also trace the soldier's location using GPS and guide them to safe places whenever necessary. The system allows soldiers to request the location from the army control unit if they are lost or wish to implement a new strategy against their enemy.
Soldiers of the present day are progressing in terms of putting technology in place. With new inventions and discoveries, the twenty first century's science and technology are escalating tremendously. The army, navy, and air force ensure national security, and the soldiers serving their country are the backbone of such endeavours. It is of high importance that the safety aspects for the soldiers be maintained because, during some of the military operations, such as surgical strikes and search operations, they might have to put their lives at stake.Connectivity issues often result in soldiers being lost in enemy territory. Therefore, the army control station must track every soldier's location and health status. Many soldiers lost their lives in battle due to inadequate health support and lack of communication between the soldiers on the battlefield and the army control base stations.
  
   
  # List of Components with Quantities:
1.   Microcontroller  
    Arduino UNO: 2
     
2.   Sensors  
   DHT11 Temperature and Humidity Sensor: 1 piece

     HW827 Heart Rate Sensor: 1 piece
   
3.   Wireless Communication  
   HC 12 Wireless Transceiver Module: 2 pieces (one for the transmitter and one for the receiver)
4.   GPS Module

     GPS Module (e.g., NEO 6M): 1 piece
   
5.   Display  
   16x2 LCD Display (I2C): 1 piece
6.   Pushbutton
   Pushbutton: 1 piece

7.   Breadboard and Jumper Wires 
   Breadboard: 1 piece
   Jumper Wires: Approx. 20 (male to male and male to female for connections)

8.   Additional Components:
   USB Cable: 1 piece (for programming the Arduino)

     
  # Connections for   Transmitter (Arduino + HC 12 + Sensors):
1.   HC 12 Transmitter Module:
   
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	TX   → Pin 11 on Arduino (SoftwareSerial TX)

     •	RX   → Pin 10 on Arduino (SoftwareSerial RX)

2.   DHT11 Temperature Sensor:
   
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	Data   → Pin 2 on Arduino

3.   Heart Rate Sensor (HW827):
   
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	Analog Out   → A0 on Arduino

4.   GPS Module:
   
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	TX   → Pin 4 on Arduino (SoftwareSerial RX)

     •	RX   → Pin 5 on Arduino (SoftwareSerial TX)

5.   LCD Display (I2C):
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	SDA   → A4 on Arduino

     •	SCL   → A5 on Arduino

6.   Pushbutton:
     •	One side of the button → Pin 3 on Arduino

     •	Other side of the button → GND

   

     # Connections for   Receiver (Arduino + HC 12):

1.   HC 12 Receiver Module:
   
     •	VCC   → 5V on Arduino

     •	GND   → GND on Arduino

     •	TX   → Pin 11 on Arduino (SoftwareSerial TX)

     •	RX   → Pin 10 on Arduino (SoftwareSerial RX)

2.   Serial Communication:
   
     Connect the Arduino to the computer via USB to monitor the incoming data from the HC 12 using the Serial Monitor.


