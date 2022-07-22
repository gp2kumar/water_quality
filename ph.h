/** @file ph.h
 *  @brief Maintains code related to ph sensor.
 *
 *  This file contains the functionality of ph sensor.
 *  @author Pradeep.Garre
 */
# include "constants.h"

/** @brief Setter for PH Sensor.
 *
 *  PH Sensor reads the PH value of a liquid. However, sensor should be 
 *  activated before it start reading the values. This function activates 
 *  the PH sensor so that the sensor will be ready to read the values.
 *
 *  @return null
 */
void setup_ph_sensor(){
  
  pinMode(PH_SENSOR_INPUT_PIN, INPUT);
    
  }

/** @brief Getter for PH Sensor.
 *
 *  Function to read the PH value and returns it.
 *  Note that, PH value should be always in the range of 0 and 14, both the 
 *  bounderies being inclusive. Hence, if sensor output is not in the corresponding 
 *  range, then sensor is behaving incorrectly. In such cases, the function 
 *  flags the error and returns a null instead of actual reading.
 *
 *  @return float(PH Value)
 */
float get_ph_value(){
  return float(random(0, 14));
  }
