#pragma once
#include "Vector2.h"

class Force : public Vector2
{
public:
	Force(long double xP, long double yP, bool push);
	bool getIsPush() override;
private:
	bool isPush = false;
};