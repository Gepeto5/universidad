#include "Solido.h"
void Solido::update(double dt) {
	Vector3D gravedad(0, -0.98, 0);
	//pos = pos+vel * dt;
	pos = pos + vel * dt;
	vel = vel + gravedad * dt;
	if (pos.getX() > 2 || pos.getX() < -2) {
		double d = vel.getX()*-0.9;
		vel.setX(d);
	}
	if (pos.getZ() > 2 || pos.getZ() < -2) {
		double d = vel.getZ()*-0.9;
		vel.setZ(d);
	}
	if (pos.getY() < 0) {
		double d = vel.getY()*-0.9;
		vel.setY(d);
		pos.setY(0);
	}
}