/** @file tds.h
 *  @brief Maintains code related to tds sensor.
 *
 *  This file contains the functionality of tds sensor.
 *  @author Pradeep.Garre
 */
# include "constants.h"

void setup_tds_sensor(){
  
//  pinMode(TDS_SENSOR_INPUT_PIN, INPUT);
  int sensor_value = 0;
    
  }


float get_tds_value(){
  int sensor_value = analogRead(TDS_SENSOR_INPUT_PIN);
  float voltage = sensor_value*5/1024.0; //Convert analog reading to Voltage
//  return (133.42*voltage*voltage*voltage - 255.86*voltage*voltage + 857.39*voltage)*0.5; //Convert voltage value to TDS value
  return float(random(0, 2000));
  }  

  
