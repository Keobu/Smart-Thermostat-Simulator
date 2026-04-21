#include "Thermostat.h"
#include <iostream>
#include <string>
#include "Logger.h"


void Thermostat::turnOn() {
	powerOn = true;
	Logger::log("Thermostat turned on");
}
void Thermostat::turnOff() {
	powerOn = false;
	Logger::log("Thermostat turned off");
}

void Thermostat::setTemperatureTarget(float target) {
	temperatureTarget = target;
	Logger::log("Temperature target set to " + std::to_string(target) + "°C");
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
            if (currentTemperature > temperatureTarget) {
                currentTemperature = temperatureTarget;
            }
        }
        else if (currentTemperature > temperatureTarget) {
            currentTemperature -= 0.5f;
            if (currentTemperature < temperatureTarget) {
                currentTemperature = temperatureTarget;
            }
        }

        if (currentTemperature == temperatureTarget) {
            Logger::log("Temperature target reached: " + std::to_string(currentTemperature) + "°C");
            turnOff();
        }
    }
    else {
        if (currentTemperature > 16.0f) {
            currentTemperature -= 0.5f;
            if (currentTemperature < 16.0f) {
                currentTemperature = 16.0f;
            }
        }
        else if (currentTemperature < 16.0f) {
            currentTemperature += 0.5f;
            if (currentTemperature > 16.0f) {
                currentTemperature = 16.0f;
            }
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
	