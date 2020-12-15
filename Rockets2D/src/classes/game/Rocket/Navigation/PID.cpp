#include "PID.h"

PID::PID(long double sp, long double p, long double i, long double d, long double maxE) {
	setPoint = sp;
	kP = p;
	kI = i;
	kD = d;
	output = 0;
	errorOverTime = 0;
	maxErrorOverTime = maxE;
	clock = sf::Clock();
}

long double PID::update(long double processVar) {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	output = calcP(processVar) + calcI(processVar) + calcD(processVar);
	return output;
}

long double* PID::getOutputPTR() {
	return &output;
}

long double PID::calcP(long double processVar) {
	return (setPoint - processVar) * kP;
}

long double PID::calcI(long double processVar) {
	errorOverTime += (setPoint - processVar) / (long double)elapsedTime.asSeconds();
	if (errorOverTime > maxErrorOverTime) {
		errorOverTime = maxErrorOverTime;
	} else if (errorOverTime < -maxErrorOverTime) {
		errorOverTime = -maxErrorOverTime;
	}
	return errorOverTime * kI;
}

long double PID::calcD(long double processVar) {
	return (setPoint - processVar) / (long double)elapsedTime.asSeconds() * kD;
}