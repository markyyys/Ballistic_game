#pragma once
#include <allegro5/allegro_primitives.h>
#include <math.h>
class Bullet
{
public:
	double x_coord = 0;
	double y_coord = 0;
	double flight_time = 0;

	double start_angle = 1;
	double start_force = 100;
	double mass = 10;

	bool collised = false;
	bool shot_state = false;

	virtual void draw(bool p_1);
	virtual void trajectory();
	virtual void collision();

	Bullet();
	~Bullet();
};

