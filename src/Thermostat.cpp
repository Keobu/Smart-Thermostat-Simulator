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

    if (powerOn) {
        if (currentTemperature < temperatureTarget) {
            Logger::log("Heating ON");
        }
        else {
            currentTemperature = temperatureTarget;
            Logger::log("Temperature target reached");
            turnOff();
        }
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
}

float Thermostat::readTemperatureFromSensor() {
    return sensor.readTemperature();
}