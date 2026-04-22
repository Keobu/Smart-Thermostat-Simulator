#pragma once
#include <iostream>
#include "TemperatureSensor.h"
#include "Logger.h"

enum class Mode {
    Eco,
	Comfort,
    Boost
};

class Thermostat {
private:
    bool powerOn;
    float currentTemperature;
    float temperatureTarget;
    TemperatureSensor sensor;
    Mode currentMode;

    float readTemperatureFromSensor();

public:
    Thermostat();

    void turnOn();
    void turnOff();
    void setTemperatureTarget(float target);
    bool isPowerOn();

    float getCurrentTemperature();
    float getTemperatureTarget();

    void updateTemperature();
    void showStatus();

	void setMode(Mode mode);
    Mode getMode();
};