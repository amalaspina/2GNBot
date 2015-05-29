#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor
{
public:
	Motor(int pin);
	virtual ~Motor();
	void Iniciar();
	void Detener();
	void Acelera(int valor);
	int AttachedPin;
	int CurrentThrottle;
	bool IsMotorRunning;
	int MinimumThrottle;
	int MaximumThrottle;


private:
	int _pin;
	void _get_motor_running();
	void _init_motor_spinning();
	void _throttle_motor(int v);
};

#endif