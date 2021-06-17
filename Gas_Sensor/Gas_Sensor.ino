#include <ESP8266WiFi.h>;
#include <ThingSpeak.h>;
 
char ssid[] = "k27"; //Your Network SSID
char password[]= "987654321"; //Your Network Password
int sensor = A0; //GAS Sensor Connected at A0 Pin
unsigned long myChannelNumber = 868392; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "7LO7B1H83O0R5OJQ"; //Your Write API Key

WiFiClient client;

void setup()
{
 
Serial.begin(115200);
 
delay(10); // Connect to WiFi network
 
while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);     
    } 
Serial.println("\nConnected.");

ThingSpeak.begin(client);

pinMode(sensor,INPUT);

}

void loop()
{
 
int val = analogRead(sensor); //Read Analog values and Store in val variable

Serial.println(val); //Print on Serial Monitor
 
delay(1000);
 
int x = ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 
if(x == 200)
{
    Serial.println("Channel update successful.");
}
else
{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
}

 
delay(3000);
 
}
