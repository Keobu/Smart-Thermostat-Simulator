#include "Thermostat.h"
#include "Logger.h"
#include <string>
#include <iostream>

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
    currentTemperature = 16.0f;
    temperatureTarget = currentTemperature;
    currentMode = Mode::Comfort;
}
float Thermostat::getCurrentTemperature() {
    return currentTemperature;
}

float Thermostat::getTemperatureTarget() {
    return temperatureTarget;
}

void Thermostat::updateTemperature() {
    currentTemperature = readTemperatureFromSensor();
    Logger::log("Current temperature updated: " + std::to_string(currentTemperature) + " C");

    float effectiveTarget = temperatureTarget;
    float tolerance = 0.5f;

    switch (currentMode) {
    case Mode::Eco:
        effectiveTarget -= 1.0f;
        break;
    case Mode::Boost:
        effectiveTarget += 1.0f;
        break;
    case Mode::Comfort:
    default:
        break;
    }

    if (powerOn) {
        if (currentTemperature < (effectiveTarget - tolerance)) {
            Logger::log("Heating ON");
        }
        else if (currentTemperature >= effectiveTarget) {
            currentTemperature = effectiveTarget;
            Logger::log("Temperature target reached");
            turnOff();
        }
        else {
            Logger::log("Within tolerance range");
        }
    }
void Thermostat::showStatus() {
    if (powerOn) {
        std::cout << "Thermostat is ON\n";
    }
    else {
        std::cout << "Thermostat is OFF\n";
    }

    std::cout << "Current temperature: " << currentTemperature << "°C\n";
    std::cout << "Temperature target: " << temperatureTarget << "°C\n";

    std::cout << "Mode: ";

    switch (currentMode) {
    case Mode::Eco:
        std::cout << "Eco\n";
        break;
    case Mode::Comfort:
        std::cout << "Comfort\n";
        break;
    case Mode::Boost:
        std::cout << "Boost\n";
        break;
    }
}

float Thermostat::readTemperatureFromSensor() {
    return sensor.readTemperature();
}
void Thermostat::setMode(Mode mode) {
    currentMode = mode;
    
    switch(mode) {
        case Mode::Eco:
            Logger::log("Mode set to Eco");
			break;
        case Mode::Comfort:
			Logger::log("Mode set to Comfort");
            break;
		case Mode::Boost:
            Logger::log("Mode set to Boost");
			break;
    }
}

Mode Thermostat::getMode() {
    return currentMode;
}