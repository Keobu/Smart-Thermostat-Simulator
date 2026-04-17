#include "Thermostat.h"
#include <iostream>
#include <string>

void Thermostat::turnOn() {
	powerOn = true;
};
void Thermostat::turnOff() {
	powerOn = false;
};

void Thermostat::setTemperatureTarget(float target) {
	temperatureTarget = target;
};

bool Thermostat::isPowerOn() {
	return powerOn;
};

Thermostat::Thermostat() {
	powerOn = false;
};
