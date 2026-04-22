
#include "TemperatureSensor.h"
#include <cstdlib> //rand, RAND_MAX

TemperatureSensor::TemperatureSensor() {
	temperature = 16.0f; //initial temperature
}

float TemperatureSensor::readSensorData() {
	//simulate temperature increase slowly over 0.5 degree per read
	float variation = (static_cast<float>(rand()) / RAND_MAX)- 0.5f;
	temperature += variation * 0.5f; //random variation up to ±0.25 degree

	return temperature;
}

float TemperatureSensor::readTemperature() {
	return readSensorData();
}
