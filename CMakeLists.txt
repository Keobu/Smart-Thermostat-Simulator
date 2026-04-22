cmake_minimum_required(VERSION 3.12)

project(SmartThermostatSimulator)

add_executable(SmartThermostatSimulator
    src/main.cpp
    src/Thermostat.cpp
    src/TemperatureSensor.cpp
    src/Logger.cpp
)

target_include_directories(SmartThermostatSimulator PRIVATE include)

set_property(TARGET SmartThermostatSimulator PROPERTY CXX_STANDARD 20)