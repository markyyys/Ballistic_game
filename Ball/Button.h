#pragma once
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>

using namespace std;

class Button
{
	ALLEGRO_FONT* font = al_load_font("arial.ttf", 24, 0);;

public:
	int x_left_top;
	int y_left_top;

	int x_right_bottom;
	int y_right_bottom;

	string name;

	bool pressed = false;
	bool selected = false;

	void draw();   
	
	Button(int x_left_top, int y_left_top, int x_right_bottom, int y_right_bottom) :
		x_left_top(x_left_top), y_left_top(y_left_top), x_right_bottom(x_right_bottom), y_right_bottom(y_right_bottom){}
	~Button();
};

