# include "constants.h"

void setup_temperature_sensor(){
  
  pinMode(TEMP_SENSOR_INPUT_PIN, INPUT);
    
  }

float get_temperature_value(){
  return float(random(0, 30));
  }   
