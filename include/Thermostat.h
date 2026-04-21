
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
		void updateTemperature();

		//modify
		void setTemperatureTarget(float target);

		//lecture
		bool isPowerOn();
		float getCurrentTemperature();
		float getTemperatureTarget();



};


