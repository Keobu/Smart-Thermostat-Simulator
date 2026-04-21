#include "Thermostat.h"
#include <iostream>
#include <string>

void Thermostat::turnOn() {
	powerOn = true;
}
void Thermostat::turnOff() {
	powerOn = false;
}

void Thermostat::setTemperatureTarget(float target) {
	temperatureTarget = target;
}

bool Thermostat::isPowerOn() {
	return powerOn;
}

Thermostat::Thermostat() {
	powerOn = false;
	currentTemperature = 16.0;
	temperatureTarget = currentTemperature;
}

float Thermostat::getCurrentTemperature() {
	return currentTemperature;
}

float Thermostat::getTemperatureTarget() {
	return temperatureTarget;
}

void Thermostat::updateTemperature() {
	if (powerOn == true) {
		if (currentTemperature < temperatureTarget) {
			currentTemperature += 0.5;
		}
		else if (currentTemperature > temperatureTarget) {
			currentTemperature -= 0.5;
		}
		else if (currentTemperature == temperatureTarget) {
			std::cout << "Temperature is stable at " << currentTemperature << "°C." << std::endl;
			turnOff()
		}
		else {
			if (currentTemperature > 16.0) {
				currentTemperature -= 0.5;
			}
			else if (currentTemperature < 16.0) {
				currentTemperature += 0.5;
			}

		}
	}
}
	