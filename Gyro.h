

#ifndef Gyro_h
#define Gyro_h
#endif


class Gyro
{
public:
	Gyro();
	virtual ~Gyro();
	void Iniciar();
	void Actualizar();
	int GetXAngle;
	int GetYAngle;

private:
	void _GetAccelerometerData();
	void _GetGyroscopeData();
	float Acc[2];
	float Gy[2];
	float Angle[2];
	float AcX;
	float AcY;
	float cZ;
	float GyX;
	float GyY;
	float GyZ;
};

