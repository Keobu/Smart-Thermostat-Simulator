
class Thermostat {

	private:
		bool powerOn;
		float currentTemperature;
		float temperatureTarget;

	public: 
		
		Thermostat();

		//action
		void turnOn();
		void turnOff();

		//modify
		void setTemperatureTarget(float target);

		//lecture
		bool isPowerOn();

};

