#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "Game.h"
#include "Menu.h"

ALLEGRO_DISPLAY* display = nullptr;
ALLEGRO_EVENT ev;
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMEOUT timeout;

bool game_on = true;
bool game_state = false;
bool menu_game_settings_state = false;

int window_set;

Game game;
Menu menu;

void A_init()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_init_image_addon();
	display = al_create_display(800, 600);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_init_timeout(&timeout, 0.001);
}

int main()
{
	A_init();
	game.Init();
	while (game_on == true)
	{
		if (game_state == false)
		{

			menu.draw();
			menu.button_handle(ev, event_queue, timeout);
			
			if (menu.pressed == 1)
			{
				game_state = true;
				menu.pressed = 0;
			}
			if (menu.pressed == 2)
			{
				game_on = false;
				exit(46);
			}
		}

		if (game_state == true)
		{
			game.Update();
			game_state = game.button_handle(ev, event_queue, timeout);
			game.draw();
		}
	}
}

