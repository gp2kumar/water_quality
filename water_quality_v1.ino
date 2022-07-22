#include "water_quality_utils.h"

void setup() {
  
  Serial.begin(9600);
  
  // Setup all the sensors.
  setup_ph_sensor();
  setup_tds_sensor();
  setup_temperature_sensor();
  setup_turbidity_sensor();
}

void loop() {

  Serial.println("Getting the sensor data..");
  
  float ph = get_ph_value();
  float temperature = get_temperature_value();
  float turbidity = get_turbidity_value();
  float tds = get_tds_value();

  // All Sensors data is read. Before proceed, print it to console.
  display_information_on_console(ph, temperature, turbidity, tds);

  // Check if wifi is connected or not. If it is not connected, connect to it.
  if (is_wifi_connected()){
    Serial.println("Wifi connected. Pushing data to cloud.");

    // Push data to cloud.
    send_data_to_cloud(ph, temperature, turbidity, tds);
    
    }
  else{
   connect_to_wifi();
  }

  delay(1000);

}
