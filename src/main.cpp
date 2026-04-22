#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "Thermostat.h"
#include "Logger.h"

void showHeader() {
    std::cout << "=============================\n";
    std::cout << "   Welcome to Thermostat App \n";
    std::cout << "=============================\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Thermostat thermostat;
    char answer;

    showHeader();

    Logger::log("Thermostat started at program launch");

    while (true) {
        thermostat.updateTemperature();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        thermostat.showStatus();

        std::cout << "Do you want to change the temperature target (y/n)? ";
        std::cin >> answer;

        if (answer == 'y') {
            std::cout << "Enter the temperature target: ";
            float target;
            std::cin >> target;

            thermostat.setTemperatureTarget(target);
            thermostat.turnOn();

            std::cout << "Temperature target set to "
                << thermostat.getTemperatureTarget() << " C\n";
        }
        else {
            std::cout << "Temperature target remains at "
                << thermostat.getTemperatureTarget() << " C\n";
        }

        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> answer;

        if (answer != 'y') {
            Logger::log("User chose to exit the program");
            break;
        }
    }

    return 0;
}