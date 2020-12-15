#pragma once
#include <SFML/Graphics.hpp>

class PID
{
public:
	PID(long double sp, long double p, long double i, long double d, long double maxE);
	long double update(long double processVar);
	long double* getOutputPTR();

private:
	sf::Clock clock;
	sf::Time elapsedTime;
	long double kP;
	long double kI;
	long double kD;
	long double setPoint;
	long double errorOverTime;
	long double maxErrorOverTime;
	long double output;
	long double calcP(long double processVar);
	long double calcI(long double processVar);
	long double calcD(long double processVar);
};