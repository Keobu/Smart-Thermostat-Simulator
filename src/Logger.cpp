#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Logger.h"

void Logger::log(std::string message) {
	std::ofstream logfile("thermostat.log", std::ios_base::app);

	if (logfile.is_open()) {
		std::time_t now = std::time(nullptr);
		std::tm localTime;
		localtime_s(&localTime, &now);

		std::ostringstream timestamp;
		timestamp <<"[" << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "]";
		
		logfile << timestamp.str() << message << std::endl;
		logfile.close();
	}
}