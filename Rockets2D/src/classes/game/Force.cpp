#include "Force.h"

Force::Force(long double xP, long double yP, bool push) : Vector2(xP, yP) {
	isPush = push;
}

bool Force::getIsPush() {
	return isPush;
}