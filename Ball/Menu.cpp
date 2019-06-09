#include "Menu.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define BACKGROUND_FILE "menu_img.png"

void Menu::button_handle(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMEOUT timeout)
{
	al_wait_for_event_until(event_queue, &ev, &timeout);

	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		exit(45);

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
			if (selection > 1)
			{
				selection--;
			}
			else
				selection = 2;

		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
			if (selection < 2)
			{
				selection++;
			}
			else
				selection = 1;
	}

	if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
		pressed = selection;

}

void Menu::Update()
{

}

void Menu::draw()
{
	background = al_load_bitmap(BACKGROUND_FILE);

	al_draw_bitmap(background, 0, 0, 0);

	if (selection == 1)
	{
		b_start_game.selected = true;
	}
	else
	{
		b_start_game.selected = false;
	}

	if (selection == 2)
	{
		b_exit_game.selected = true;
	}
	else
	{
		b_exit_game.selected = false;
	}

	b_start_game.draw();
	b_exit_game.draw();

	al_flip_display();
	al_rest(0.0006);
}

Menu::Menu()
{
}


Menu::~Menu()
{
}
