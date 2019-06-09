#include "Gun.h"

void Gun::draw(bool p_1)
{
	double i = 3;

		al_draw_line(
			(p_1) ? (0) : 800,
			500,
			(p_1) ? (cos(g_angle) * 70) : 800 - cos(g_angle) * 70,
			500 - (sin(g_angle) * 70),
			al_map_rgb(50, 200, 50), 10);

		al_draw_line(
			(p_1) ? (0) : 800,
			500,
			(p_1) ? (cos(g_angle) * 60) : 800 - cos(g_angle) * 60,
			500 - (sin(g_angle) * 60),
			al_map_rgb(50, 200, 50), 20);

		al_draw_filled_circle(
			(p_1) ? (0) : 800,
			500,
			50,
			al_map_rgb(50, 200, 50));

		for (int t = 0; t < 10; t += 2)
			al_draw_filled_circle(
			(p_1) ? trj_coords[t] : 800 - trj_coords[t],
			500 - trj_coords[t + 1],
			i -= 0.4,
			al_map_rgb(50, 150, 50));
}

void Gun::Trajectory()
{
	double dist = 0;
	for (int t = 0; t < 10; t += 2)
	{
		dist += 0.7;
		trj_coords[t] = (cos(g_angle) * 70) + g_force * dist * cos(g_angle);
		trj_coords[t + 1] = (sin(g_angle) * 70) + ((g_force * sin(g_angle)) * dist) - ((9.8 * pow(dist, 2)) / 2);
	}
}

void Gun::recoil()
{
	if (((recoil_time == 500) || (recoil_time > 0)) && (recoiling == true))
	{
		recoiling = true;
		recoil_time -= 1;

		if(g_angle < 1.2)
			g_angle += 0.0001;

		if(g_force > 50)
			g_force -= 0.2;

		if (recoil_time == 0)
		{
			recoiling = false;
			recoil_time = 500;
		}
	}
}

void Gun::damage(bool *damaged, double *bullet_mass)
{
	if (*damaged == true)
	{
		if (health > 0)
			health -= *bullet_mass;
		else
			defeat = true;
	}
}

Gun::Gun()
{
	std::cout << g_angle << " " << g_force << std::endl;
}


Gun::~Gun()
{
}
