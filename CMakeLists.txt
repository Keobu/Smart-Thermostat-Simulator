# CMakeList.txt: progetto CMake per Smart Thermostat Simulator. Includere l'origine e definire
# qui la logica specifica del progetto.
#

# Aggiungere l'origine all'eseguibile di questo progetto.
add_executable (CMakeTarget "src/main.cpp" "Smart Thermostat Simulator.h" "src/Thermostat.cpp" "src/TemperatureSensor.cpp" "src/Logger.cpp" "include/Thermostat.hpp" "include/TemperatureSensor.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
