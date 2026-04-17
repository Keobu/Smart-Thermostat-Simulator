#include <iostream>
#include "Thermostat.h"

using namespace std;

int main()
{
	Thermostat thermostat;

	if (thermostat.isPowerOn()) {
		thermostat.turnOff();
		std::cout << "Thermostat turned OFF\n";
	} else {
		thermostat.turnOn();
		std::cout << "Thermostat turned ON\n";
	}

	if (thermostat.isPowerOn()) {
		std::cout << "Now it is ON\n";
	} else {
		std::cout << "Now it is OFF\n";
	}
	return 0;
}
