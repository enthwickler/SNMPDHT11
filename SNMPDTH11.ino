#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Arduino_SNMP.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 0
#define CHECK_LED 1
DHT dht(dht_dpin, DHTTYPE); 

//Please modify your wifi creaditial here
const char* ssid = "Hathway";
const char* password = "passward";

WiFiUDP udp;
SNMPAgent snmp = SNMPAgent("public");  // Starts an SMMPAgent instance with the community string 'public'

// structure to store sensor data
struct sensorData{
  int h; // for humidity
  int t; // for temp
  };

struct sensorData sdata; 


int settableNumber; // for check connection LED will toggle 
int ch =HIGH;

void setup(){
    Serial.begin(115200);
    dht.begin();
    Serial.println("Humidity and temperature\n\n");
    WiFi.begin(ssid, password);
    Serial.println("");
    pinMode(LED_BUILTIN, OUTPUT);
    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    
    // give snmp a pointer to the UDP object
    snmp.setUDP(&udp);
    snmp.begin();
   
    
    // add 'callback' for an OID - pointer to an integer
    snmp.addIntegerHandler(".1.3.6.1.4.1.5.0", &sdata.t); // Getting the temp
    
    snmp.addIntegerHandler(".1.3.6.1.4.1.5.2", &sdata.h); // Getting Humidity


    
    // you can accept SET commands if you send 1 to toggle LED
    snmp.addIntegerHandler(".1.3.6.1.4.1.5.1", &settableNumber,true);
    
    
    
}

void loop(){
    snmp.loop(); // must be called as often as possible

    
    sdata.h = dht.readHumidity();
    sdata.t = dht.readTemperature();     
    
    
    if(snmp.setOccurred){
        Serial.printf("Number has been set to value: %i", settableNumber);
       // pinMode(LED_BUILTIN, OUTPUT);
        if(settableNumber == CHECK_LED)
        {
          digitalWrite(LED_BUILTIN, ch);   // Toggle LED
          delay(50);
          ch=ch^HIGH;
 
          }
        snmp.resetSetOccurred();
    }

    
}
