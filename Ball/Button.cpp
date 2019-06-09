#include "Button.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

int r_colour;
int g_colour;
int b_colour;

void Button::draw()
{
	if (selected == true)
	{
		r_colour = 0;
		g_colour = 255;
		b_colour = 0;
	}
	else
	{
		r_colour = 0;
		g_colour = 100;
		b_colour = 0;
	}

	//if (!font)
	//{
	//	cout << "Font";
	//		exit(0);
	//}
	//al_draw_text(font, al_map_rgb(r_colour, g_colour, b_colour), x_left_top + 100, y_left_top + 25, ALLEGRO_ALIGN_CENTER, name.c_str());
	al_draw_rectangle(x_left_top, y_left_top, x_right_bottom, y_right_bottom, al_map_rgb(r_colour, g_colour, b_colour), 5);
}

Button::~Button()
{
}
