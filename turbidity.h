# include "constants.h"

void setup_turbidity_sensor(){
  
  pinMode(TURBIDITY_SENSOR_INPUT_PIN, INPUT);
    
  }

float get_turbidity_value(){
  return float(random(15, 70));
  }   
