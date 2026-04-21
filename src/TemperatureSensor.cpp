
#include "TemperatureSensor.h"
#include <cstdlib> //rand, RAND_MAX

TemperatureSensor::TemperatureSensor() {
	temperature = 16.0f; //initial temperature
}

float TemperatureSensor::readSensorData() {
	//simulate temperature changes
	temperature = 15.0f + static_cast<float>(rand()) / (RAND_MAX / 10.0f);
	return temperature;
}

float TemperatureSensor::readTemperature() {
	return readSensorData();
}