#pragma once
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <iostream>

class Gun
{
private:

public:
	int health = 100;
	bool damaged = false;
	bool defeat = false;

	int recoil_time = 500;
	bool recoiling = false;

	double g_angle;
	double g_force;
	double g_mass;

	int trj_coords[10];

	void draw(bool p_1);
	void Trajectory();
	void recoil();
	void damage(bool *damaged, double *bullet_mass);

	Gun(double g_angle, double g_force) : g_angle(g_angle), g_force(g_force)
	{

	}

	Gun();
	~Gun();
};

