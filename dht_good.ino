#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>

#define DHTTYPE DHT11

uint8_t DHTPIN = D2; //choose your correct PIN type here.
DHT dht(DHTPIN,DHTTYPE);

float humidityData;
float temperatureData;

const char* ssid = "iPhone"; 
const char* password = "11223344";
//WiFiClient client;
byte server[] = {172, 20, 10, 2};   //eg: This is the IP address of your PC once XAMPP 

WiFiClient client;    

void setup()
{
 Serial.begin(115200);
  delay(100);
  pinMode(DHTPIN, INPUT);

  dht.begin();
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("Got IP: "); Serial.print(WiFi.localIP());
// Start the server
//  server.begin();
//  Serial.println("Server started");
  Serial.println("");
  delay(1000);
  Serial.println("connecting...");
 }
void loop()
{ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature(); 
  Sending_To_phpmyadmindatabase(humidityData, temperatureData); 
  delay(10000); // every 10 secs
 }

   void Sending_To_phpmyadmindatabase(float humidityData, float temperatureData)   //CONNECTING WITH MYSQL, pass the variables here to call the function correctly.
   {
   if (client.connect(server, 80)) {
    Serial.println("connected to local server");
    // Make a HTTP request:
    
    Serial.print("GET /dht11/dht11.php?humidity=");
    client.print("GET /dht11/dht11.php?humidity=");     //YOUR URL

    
    Serial.println(humidityData);
    client.print(humidityData);
    client.print("&temperature=");
    
    Serial.println("&temperature=");
    client.print(temperatureData);
    
    Serial.println(temperatureData);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
 
    client.println("Host: 192.168.43.141"); // Add your server IP address here. If you forgotten, please see XAMPP > Apached-access-logs for issues. If the IP address is not added or incorrectly added, Apache will give error 400 which is malformed HTTP Request
    client.println("Connection: close");
    client.println(); 
    
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
