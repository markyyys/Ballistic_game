#pragma once
#include "Button.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


class Menu
{
	ALLEGRO_BITMAP* background = NULL;

	Button b_start_game = { 200,100,600,150};
	Button b_exit_game = { 200,250,600,300};
	
public:
	int selection = 1;
	int pressed = 0;
	
	void button_handle(ALLEGRO_EVENT, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TIMEOUT);
	void Update();
	void draw();

	Menu();
	~Menu();
};

