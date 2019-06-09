#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::draw(bool p_1)
{
	if (shot_state)
		al_draw_filled_circle((p_1) ? (x_coord) : 800 - x_coord,
			500 - y_coord,
			5,
			al_map_rgb(50, 255, 50));
}

void Bullet::trajectory()
{
	if (shot_state == true)
	{
		flight_time += 0.01;
		x_coord = (cos(start_angle) * 70) + start_force * flight_time * cos(start_angle);
		y_coord = (sin(start_angle) * 70) + ((start_force * sin(start_angle)) * flight_time) - ((9.8 * pow(flight_time, 2)) / 2);

		if ((x_coord > 800) || (500 - y_coord > 500))
		{
 			shot_state = false;
			flight_time = 0.0;
		}
		else
			shot_state = true;
	}
	else
	{
		flight_time = 0.0;
	}
}

void Bullet::collision()
{
	if ((collised == false) && (shot_state == true))
	{
		if (((500 - y_coord < 500) && (500 - y_coord > 470)) && ((x_coord < 30) || (x_coord > 770)))
		{
			collised = true;
  			shot_state = false;
		}
	}
	else
		collised = false;
}
