#include <ESP8266WiFi.h>
 
const char* ssid = "k27";
const char* password = "987654321";

int motorR[]={D2,D1};
int motorL[]={D3,D4};
int EN1=D5;
int EN2=D6;

int value=0;
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 

  for(int i=0;i<2;i++)
  {
    pinMode(motorR[i],OUTPUT);
    pinMode(motorL[i],OUTPUT);
   }
 
  // Connect to WiFi network
  Serial.println(); 
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());   //Get the IP address
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) 
  {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  
  if (request.indexOf("/F=ON") != -1)  {
     forward(); 
    Serial.println("Your bot is gonna move forward");
    value = 1;
  }
 else if (request.indexOf("/B=ON") != -1)  {
     backward() ;
    Serial.println("Your bot is gonna move backwards");
    value = 2;
  }
 else  if (request.indexOf("/L=ON") != -1)  {
    left();
    Serial.println("Your bot is gonna move left");
    value = 3;
  }
  else if (request.indexOf("/R=ON") != -1)  {
    Serial.println("Your bot is gonna move right");
     right();
    value = 4;
  }

 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Bot is now moving : ");
 
  if(value == 1) {
    client.print("Forward");
  } 
  if ( value==2)
  {
    client.print("Backward");
  }
   if(value == 3) {
    client.print("Left");
  } 
  if(value==4) {
    client.print("Right");
  }
  
  client.println("<br><br>");
  client.println("<a href=\"/F=ON\"\"><button>Move Forward </button></a>");
  client.println("<a href=\"/B=ON\"\"><button>Move Backward </button></a><br />");  
  client.println("<a href=\"/L=ON\"\"><button>Move Left</button></a>");
  client.println("<a href=\"/R=ON\"\"><button>Move Right</button></a><br />");  
  client.println("</html>");
  
 
}


void forward()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);
  
 }


 void backward()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);
  
 }


 void left()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);
  
 }


 void right()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);
  
 }
