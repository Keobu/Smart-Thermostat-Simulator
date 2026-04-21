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
    if (powerOn) {
        if (currentTemperature < temperatureTarget) {
            currentTemperature += 0.5f;
        }
        else if (currentTemperature > temperatureTarget) {
            currentTemperature -= 0.5f;
        }

        if (currentTemperature == temperatureTarget) {
            turnOff();
        }
    }
    else {
        if (currentTemperature > 16.0f) {
            currentTemperature -= 0.5f;
        }
        else if (currentTemperature < 16.0f) {
            currentTemperature += 0.5f;
        }
    }
}
void Thermostat::showStatus() {
	if (powerOn) {
		std::cout << "Thermostat is ON\n";
	}else {
		std::cout << "Thermostat is OFF\n";
	}
	std::cout << "Current temperature: " << currentTemperature << "°C\n";
	std::cout << "Temperature target: " << temperatureTarget << "°C\n";
}
	