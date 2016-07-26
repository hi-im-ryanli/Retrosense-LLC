#include "QuickStats.h"

#define sonar_0 0
#define sonar_1 1
#define numSensors 2

QuickStats stats; //initialize an instance of this class

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float distance_1 = measureDistance(sonar_0);
  float distance_2 = measureDistance(sonar_1);
  float readings[] = {distance_1, distance_2};
  float err = stats.stderror(readings, numSensors);	//standard diviation of the two readings
  // print out to serial
  Serial.print("Sensor 1 Data: ");
  Serial.println(distance_1);
  Serial.print("Sensor 2 Data: ");
  Serial.println(distance_2);
  Serial.print("Standard Diviation: ");
  Serial.println(err);
  Serial.println(' ');
  delay(1000);
}


// ====================================
// SUPPORTING FUNCTIONS
float measureDistance(int pinNumber){
	float distance = 0;
	float sum = 0;
	for (int i = 0; i < 10; i++){
	    sum = sum + analogRead(pinNumber);	// formatting the output to meters
	    delay(50);	// each measurement takes 500ms           
	}	
	distance = sum * 5 * 0.001 / 10;
	return distance;
}