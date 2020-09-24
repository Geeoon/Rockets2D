#include "Force.h"

Force::Force(long double xP, long double yP, bool push) : Vector2(xP, xP) {
	isPush = push;
}

bool Force::getIsPush() const {
	return isPush;
}