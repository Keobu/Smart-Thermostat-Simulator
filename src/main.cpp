#include <iostream>
#include <chrono>
#include <thread>
#include "Thermostat.h"


using namespace std;

int main()
{
	Thermostat thermostat;

	if (thermostat.isPowerOn()) {
		thermostat.turnOff();
		std::cout << "Thermostat turned OFF\n";
	}
	else {
		thermostat.turnOn();
		std::cout << "Thermostat turned ON\n";
	}

	if (thermostat.isPowerOn()) {
		std::cout << "Now it is ON\n";
	}
	else {
		std::cout << "Now it is OFF\n";
	}

	std::cout << "Current temperature: " << thermostat.getCurrentTemperature() << "°C\n";
	std::cout << "Temperature target: " << thermostat.getTemperatureTarget() << "°C\n";


	while (true) {
		std::cout << "do you want turn on the Thermostat (y/n)? ";
		char answer;
		std::cin >> answer;
		if (answer == 'y') {
			thermostat.turnOn();
		}
		else {
			thermostat.turnOff();
			break;
		};

		thermostat.updateTemperature();

		//little break
		std::this_thread::sleep_for(std::chrono::seconds(1));
	
		//state the current temperature and the target temperature

		if (thermostat.isPowerOn()) {
			std::cout << "Thermostat is ON\n";
		}
		else {
			std::cout << "Thermostat is OFF\n";
		}

		std::cout << "Current temperature: " << thermostat.getCurrentTemperature() << "°C\n";
		std::cout << "Temperature target: " << thermostat.getTemperatureTarget() << "°C\n";
		
		std::cout << "Do you want to change the temperature target (y/n)? ";
		std::cin >> answer;
		
		if (answer == 'y') {
			std::cout << "Enter the Temperature target: ";
			float target;
			std::cin >> target;
			thermostat.setTemperatureTarget(target);
			std::cout << "Temperature target set to " << thermostat.getTemperatureTarget() << "°C\n";
			//start the thermostat
			thermostat.turnOn();
		}
		else {
			std::cout << "Temperature target remains at " << thermostat.getTemperatureTarget() << "°C\n";
		}
		
		std::cout << "Do you want to continue (y/n)? ";
		std::cin >> answer;
		if (answer != 'y') {
			break;
		}
	}

	return 0;
}
