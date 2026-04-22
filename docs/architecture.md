# Architecture Overview

##  System Design

The application follows a modular and object-oriented design:

* **Thermostat** → Core logic controller
* **TemperatureSensor** → Simulates real-world temperature changes
* **Logger** → Handles logging to file
* **Main** → User interaction and control flow

---

##  Data Flow

```
TemperatureSensor → Thermostat → Logger
                        ↓
                     Console UI
```

---

##  Responsibilities

### Thermostat

* Manages power state
* Controls heating logic
* Applies smart rules (modes + hysteresis)
* Reads sensor data

### TemperatureSensor

* Generates realistic temperature changes
* Simulates environment behavior

### Logger

* Writes system events to file
* Adds timestamps

---

##  Smart Features

### Modes

* Eco → lower target
* Comfort → default
* Boost → higher target

### Hysteresis

Prevents rapid ON/OFF switching:

* ON below: target - tolerance
* OFF above: target

---

##  Runtime Loop

1. Read temperature
2. Apply smart logic
3. Update state
4. Log event
5. Display status
6. Wait
