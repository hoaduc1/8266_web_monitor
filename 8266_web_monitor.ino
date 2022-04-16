/*
 * Hello world web server
 * circuits4you.com
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //Our HTML webpage contents

ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String html = INDEX_3; //Read HTML contents
 server.send(200, "text/html", html); //Send web page
}
void handleAngleX() {
 server.send(200, "text/plain", String(random(0, 30)));
}
void handleAngleY() {
 server.send(200, "text/plain", String(random(0, 30)));
}
void handleAngleZ() {
 server.send(200, "text/plain", String(random(0, 30)));
}
void handleGyroX() {
 server.send(200, "text/plain", String(random(0, 30)));
}
void handleGyroY() {
 server.send(200, "text/plain", String(random(0, 30)));
}
void handleGyroZ() {
 server.send(200, "text/plain", String(random(0, 30)));
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(9600);

  
  // WifiAP
  const char* ssid = "abc";
  const char* password = "12345678";
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  // //Connect to your WiFi router  
  // //SSID and Password of your WiFi router
  // const char* ssid = "THPT Nguyen Quang Dieu";
  // const char* password = "0946457113";
  // WiFi.begin(ssid, password);     
  // Serial.println("");
  // // Wait for connection
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // //If connection successful show IP address in serial monitor
  // Serial.println("");
  // Serial.print("Connected to ");
  // Serial.println(ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location
  server.on("/Angle_X", handleAngleX);
  server.on("/Angle_Y", handleAngleY);
  server.on("/Angle_Z", handleAngleZ);
  server.on("/Gyro_X", handleGyroX);
  server.on("/Gyro_Y", handleGyroY);
  server.on("/Gyro_Z", handleGyroZ);
  // server.on("/pressure", handlePressure);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}