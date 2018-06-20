//#include <RunningMedian.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
const int LED = D1;

IPAddress ip;

// defines variables
unsigned long duration;
int distance;
const char* ssid = "CNN";
const char* password = "***********";
const char* mqtt_server = "192.168.1.101";



void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode (LED, OUTPUT);  //LED Pin
Serial.begin(9600); // Starts the serial communication
WiFi.begin(ssid,password);
while (WiFi.status() != WL_CONNECTED)
  { delay(500);
     Serial.print(".");
  }
ip = WiFi.localIP();
Serial.println("");
Serial.print("WiFi Connected - IP: ");
Serial.print(ip);
Serial.println("");

}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

//turn on LED if distance greater than 100

if (distance < 100)
  { digitalWrite(LED, HIGH);
  }
else 
  { digitalWrite(LED,LOW);
  }
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}

