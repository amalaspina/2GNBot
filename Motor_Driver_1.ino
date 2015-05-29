#include "Motor.h"
#include "Gyro.h"


Motor _motor_1(9);
Motor _motor_2(10);
Motor _motor_3(3);
Motor _motor_4(11);

Gyro _gyro;

int acelera = 0;

void setup() 
{
	_motor_1.Iniciar();
	_motor_2.Iniciar();
	_motor_3.Iniciar();
	_motor_4.Iniciar();
	_gyro.Iniciar();

	Serial.begin(115200);

	Serial.print(_gyro.GetXAngle);
	Serial.print(",");
	Serial.println(_gyro.GetYAngle);


}

void loop() 
  {
	  _gyro.Actualizar();
	  /* Calcula el porcentaje de aceleracion para el motor a partir del joystick
	    map(analogRead(4), 0, 640, -10, 10)
	  */
	  //if (Serial.available())
	  //{
		 // acelera = Serial.parseInt();
	
	  //}

	  _motor_1.Acelera(acelera);
	  _motor_3.Acelera(acelera);
	  _motor_2.Acelera(acelera);
	  _motor_4.Acelera(acelera);


	  Estabilizar(_gyro.GetXAngle, _gyro.GetYAngle);

  }

void Estabilizar(int _GyroX, int _GyroY)
{
	if (_GyroX < 0)
	{
		/* Inclinacion negativa en el Eje X

		Verificamos velocidad actual de los motores en el eje X

		*/
		if ((_motor_3.CurrentThrottle == _motor_3.MaximumThrottle) && (_motor_2.CurrentThrottle == _motor_2.MaximumThrottle))
		{
			// Si (el / los) motores estan en su velocidad maxima, disminuimos velocidad del motor en X + (PWM 3) (Motor 3)
			_motor_3.Acelera(_GyroX);
		}
		else
		{
			// Si (el / los) motores no estan en velocidad maxima, aumentamos velocidad del motor en X - (PWM 10) (Motor 2)
			_motor_2.Acelera(_GyroX * -1);
		}
	}
	else if (_GyroX > 0)
	{
		/* Inclinacion positiva en el Eje X

		Verificamos velocidad actual de los motores en el eje X

		*/
		if ((_motor_3.CurrentThrottle == _motor_3.MaximumThrottle) && (_motor_2.CurrentThrottle == _motor_2.MaximumThrottle))
		{
			// Si (el / los) motores estan en su velocidad maxima, disminuimos velocidad del motor en X + (PWM 10) (Motor 2)
			_motor_2.Acelera(_GyroX * -1);
		}
		else
		{
			// Si (el / los) motores no estan en velocidad maxima, aumentamos velocidad del motor en X - (PWM 3) (Motor 3)
			_motor_3.Acelera(_GyroX);
		}

		//		Serial.print("Ajuste en X: "); Serial.println(_GyroX);
	}


	if (_GyroY < 0)
	{
		/* Inclinacion negativa en el Eje Y

		Verificamos velocidad actual de los motores en el eje Y

		*/
		if ((_motor_4.CurrentThrottle == _motor_4.MaximumThrottle) && (_motor_1.CurrentThrottle == _motor_1.MaximumThrottle))
		{
			// Si (el / los) motores estan en su velocidad maxima, disminuimos velocidad del motor en Y + (PWM 11) (Motor 4)
			_motor_4.Acelera(_GyroY);
		}
		else
		{
			// Si (el / los) motores no estan en velocidad maxima, aumentamos velocidad del motor en Y - (PWM 9) (Motor 1)
			_motor_1.Acelera(_GyroY * -1);
		}
	}
	else if (_GyroY > 0)
	{
		/* Inclinacion positiva en el Eje X

		Verificamos velocidad actual de los motores en el eje X

		*/
		if ((_motor_3.CurrentThrottle == _motor_3.MaximumThrottle) && (_motor_2.CurrentThrottle == _motor_2.MaximumThrottle))
		{
			// Si (el / los) motores estan en su velocidad maxima, disminuimos velocidad del motor en Y - (PWM 9) (Motor 1)
			_motor_1.Acelera(_GyroY * -1);
		}
		else
		{
			// Si (el / los) motores no estan en velocidad maxima, aumentamos velocidad del motor en X - (PWM 11) (Motor 4)
			_motor_4.Acelera(_GyroY);
		}
//		Serial.print("Ajuste en Y: "); Serial.println(_GyroY);
	}

	Serial.print(_motor_1.CurrentThrottle);
	Serial.print(",");
	Serial.print(_motor_2.CurrentThrottle);
	Serial.print(",");
	Serial.print(_motor_3.CurrentThrottle);
	Serial.print(",");
	Serial.print(_motor_4.CurrentThrottle);
	Serial.print(",");
	Serial.print(_GyroY);
	Serial.print(",");	Serial.println(_GyroX);
}