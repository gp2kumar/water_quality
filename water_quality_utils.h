# include "temperature.h"
# include "ph.h"
# include "turbidity.h"
# include "tds.h"
# include "WiFi.h"
# include<HTTPClient.h>

void display_information_on_console(float ph_value, float temperature_value, float turbidity_value, float tds_value){
  Serial.print("PH: ");
  Serial.println(ph_value);
  Serial.print("Temperature: ");
  Serial.println(temperature_value);
  Serial.print("Turbidity: ");
  Serial.println(turbidity_value);
  Serial.print("TDS: ");
  Serial.println(tds_value);
  }

bool is_wifi_connected(){
  return (WiFi.status() == WL_CONNECTED);
  }

bool connect_to_wifi(){

  // Try connecting to WIFI.
  WiFi.begin(WIFI_NAME, PASSWORD);

 // Wifi Connection will be established after a moment. Keep polling for connection. 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network.");
  }

void send_data_to_cloud(float ph_value, float temperature_value, float turbidity_value, float tds_value){

// Declaring a HTTP Client Object
HTTPClient http;

// Prepare the URL for sending POST request.
String server="http://" + String() + CLOUD_SERVICE_IP + ":" + String() + CLOUD_SERVICE_PORT + String()+SERVICE_END_POINT;

// Prepare the payload for POST request.
String payload = String() + "{\"pH\":\""+ph_value+"\",\"Tds\":\""+tds_value+"\",\"Turbidity\":\""+turbidity_value+"\",\"Temperature\":\""+temperature_value+"\"}";
Serial.println(server);
Serial.println(payload);
// Start HTTP Request.
http.begin(server);

// Add Headers.   
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("X-Auth-Token", DEVICE_ID);
http.addHeader("Content-Length", "100");

// Send HTTP Request.
int code = http.POST(payload);
http.end();

// return true/false based on the response code.
if (code == 200){
  Serial.println("Uploaded the data to Cloud.");
  }
else{
Serial.println("Unable to send HTTP POST. Response code: " + String() + code);
}

Serial.println("------------------------------------------------------------");
}
