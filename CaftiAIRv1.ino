#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "CaftiAIR";       
const char* password = "caftiairpcsi2223"; 
ESP8266WebServer server(80);

//shit
bool power = LOW;
bool small = LOW;
bool medium = LOW;
bool large = LOW;
bool HasPower = LOW;

//Pin layout
const char pinpower = D1;
const char pinsmall = D3;
const char pinmedium = D2;
const char pinlarge = D4;

void setup() {

  //Serial Init

  //NPN MODE
  pinMode(pinpower, OUTPUT); //power
  pinMode(pinsmall, OUTPUT); //small
  pinMode(pinmedium, OUTPUT); //medium
  pinMode(pinlarge, OUTPUT); //large
  pinreset();
  


  //webserver 
  WiFi.softAP(ssid, password);
  server.on("/", handle_OnConnect);
  server.on("/power", handle_power);
  server.on("/small", handle_coffee_s);
  server.on("/medium", handle_coffee_m);
  server.on("/large", handle_coffee_l);


  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP Server Started");

}

void loop() {
  //werbserver
  server.handleClient();
}

void handle_OnConnect() {
  pinreset();
  server.send(200, "text/html", mainpage(HasPower)); 
}

void handle_power() {
  if (HasPower)
  HasPower = LOW;
  else
  HasPower = HIGH;
  server.send(200, "text/html", mainpage(HasPower)); 

  digitalWrite(pinpower, HIGH);
  delay(500);
  digitalWrite(pinpower, LOW);
}
void handle_coffee_s (){
  server.send(200, "text/html", mainpage(HasPower)); 
  digitalWrite(pinsmall, HIGH);
  delay(500);
  digitalWrite(pinsmall, LOW);
}
void handle_coffee_m (){
  server.send(200, "text/html", mainpage(HasPower)); 
  digitalWrite(pinmedium, HIGH);
  delay(500);
  digitalWrite(pinmedium, LOW);
}
void handle_coffee_l (){
  server.send(200, "text/html", mainpage(HasPower)); 
  digitalWrite(pinlarge, HIGH);
  delay(500);
  digitalWrite(pinlarge, LOW);
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String mainpage(uint8_t HasPower){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>CaftiAIR</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #3498db;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>CaftiAIR</h1>\n";

  if (HasPower){
    ptr +="<p>Power: ON</p><a class=\"button button-on\" href=\"/power\">Alim: ON</a>\n";
  } else{
    ptr +="<p>Power: OFF</p><a class=\"button button-off\" href=\"/power\">Alim: OFF</a>\n";
  }
  ptr +="<a class=\"button button-on\" href=\"/small\">Petit</a>\n";
  ptr +="<a class=\"button button-on\" href=\"/medium\">Moyen</a>\n";
  ptr +="<a class=\"button button-on\" href=\"/large\">Grand</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr ;
}


void pinreset(){
  digitalWrite(pinpower, LOW);
  digitalWrite(pinsmall, LOW);
  digitalWrite(pinmedium, LOW);
  digitalWrite(pinlarge, LOW);
}