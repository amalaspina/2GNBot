#include "Motor.h"

// Variables Globales

// Contructor de la clase Motor
Motor::Motor(int pin)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
	this->AttachedPin = _pin;
	this->CurrentThrottle = 0;
	this->MaximumThrottle = 254;
	this->MinimumThrottle = 110;
	this->IsMotorRunning = false;
}

Motor::~Motor()
{
}

void Motor::Iniciar()
{
}


void Motor::Acelera(int v)//0 a 100%
{
	_throttle_motor(v);
}

void Motor::_throttle_motor(int speedPercent)//0 a 100%
{
	int gap=this->MaximunThrottle-this->MinimunThrottle;
	this->CurrentThrottle=(gap*(speedPercent/100))+this->MinimunThrottle;
	analogWrite(this->AttachedPin, this->CurrentThrottle);
}

void Motor::_init_motor_spinning()
{
	bool _exit_loop = false;
	int i = 0;
	analogWrite(this->AttachedPin, this->MaximumThrottle);;
	delay(100);
	do
	{
		for (i = this->MinimumThrottle; i <= 200; i++)
		{
			analogWrite(this->AttachedPin, i);
			this->CurrentThrottle = i;
		}
		_exit_loop = true;
		this->IsMotorRunning = true;
	} while (_exit_loop == false);
}



