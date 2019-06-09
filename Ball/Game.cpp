#include "Game.h"
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define BACKGROUND_FILE_G "game_img.png"

void Game::Update()
{
	if (paused == false)
	{
		//-----------Обновление траектории полета снарядов первого игрока----------------

		Bullets_p_1_.resize(3);
		for (Bullets_p_1::iterator i = Bullets_p_1_.begin(); i != Bullets_p_1_.end(); ++i)
		{
			i->trajectory();
			i->collision();
			if (i->collised == true)
				g_player_2->damage(&i->collised, &i->mass);
		}

		//-----------Обновление траектории полета снарядов второго игрока----------------

		Bullets_p_2_.resize(3);
		for (Bullets_p_2::iterator i = Bullets_p_2_.begin(); i != Bullets_p_2_.end(); ++i)
		{
			i->trajectory();
			i->collision();
			if (i->collised == true)
				g_player_1->damage(&i->collised, &i->mass);
		}

		g_player_1->Trajectory();
		g_player_2->Trajectory();

		g_player_1->recoil();
		g_player_2->recoil();
	}
}	

//------Функция отрисовки-------

void Game::draw()
{
	background = al_load_bitmap(BACKGROUND_FILE_G);

	al_draw_bitmap(background, 0, 0, 0);

	//---------Отрисовка пушек-----------

	g_player_1->draw(true);//Пушка слева
	g_player_2->draw(false);//Пушка справа

	al_draw_filled_rectangle(0, 500, 800, 600, al_map_rgb(0, 0, 0));
	al_draw_rectangle(0, 500, 800, 600, al_map_rgb(50, 200, 50), 10);

	al_draw_line(
		150 - g_player_1->health,
		550,
		150,
		550,
		al_map_rgb(200, 50, 50), 10);

	al_draw_line(
		750,
		550,
		750 - g_player_2->health,
		550,
		al_map_rgb(200, 50, 50), 10);

	//--------------------------------------Отрисовка снарядов-----------------------------------------------------------

	for (Bullets_p_1::iterator i = Bullets_p_1_.begin(); i != Bullets_p_1_.end(); ++i)//Отрисовка снарядов первого игрока
	{
		i->draw(true);
	}

	for (Bullets_p_2::iterator i = Bullets_p_2_.begin(); i != Bullets_p_2_.end(); ++i)//Отрисовка снарядов второго игрока
	{
		i->draw(false);
	}

	for (Buttons::iterator i = Buttons_.begin(); i != Buttons_.end(); ++i)
	{
		i->draw();
	}

	al_flip_display();
	al_rest(fps);
}

//---------Функция работы с кнопками (стоит ее куда-то в другое место вставить)---------

bool Game::button_handle(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMEOUT timeout)
{
		//-------------------------------Кнопки первого игрока------------------------------

		al_wait_for_event_until(event_queue, &ev, &timeout);

		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			return false;
		}

		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			if (g_player_1->g_angle < 1.2)
				g_player_1->g_angle += 0.01;
			break;

		case ALLEGRO_KEY_DOWN:
			if (g_player_1->g_angle > 0.3)
				g_player_1->g_angle -= 0.01;
			break;
	
		case ALLEGRO_KEY_RIGHT:
			if (g_player_1->g_force < 100)
				g_player_1->g_force += 0.5;
			break;

		case ALLEGRO_KEY_LEFT:
			if (g_player_1->g_force > 50)
				g_player_1->g_force -= 0.5;
			break;
		}

		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_1:
			g_player_1->g_mass = 10;
			break;

		case ALLEGRO_KEY_2:
			g_player_1->g_mass = 15;
			break;

		case ALLEGRO_KEY_3:
			g_player_1->g_mass = 20;
			break;
		}

		if ((ev.type == ALLEGRO_EVENT_KEY_DOWN) && (ev.keyboard.keycode == ALLEGRO_KEY_ENTER))
		{
			for (Bullets_p_1::iterator i = Bullets_p_1_.begin(); i != Bullets_p_1_.end(); ++i)
			{
				if (i->shot_state == false)
				{
					if (g_player_1->recoiling == false)
					{
						i->shot_state = true;
						i->start_angle = g_player_1->g_angle;
						i->start_force = g_player_1->g_force;
						i->mass = g_player_1->g_mass;
						i->trajectory();
						g_player_1->recoiling = true;
					}
					break;
				}
			}
		}

		ev.keyboard.keycode = 0;

		//-------------------------------Кнопки второго игрока----------------------------------

		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_W:
			if (g_player_2->g_angle < 1.2)
				g_player_2->g_angle += 0.01;
			break;

		case ALLEGRO_KEY_S:
			if (g_player_2->g_angle > 0.3)
				g_player_2->g_angle -= 0.01;
			break;

		case ALLEGRO_KEY_D:
			if (g_player_2->g_force < 100)
				g_player_2->g_force += 0.5;
			break;

		case ALLEGRO_KEY_A:
			if (g_player_2->g_force > 50)
				g_player_2->g_force -= 0.5;
			break;
		}

		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_B:
			g_player_1->g_mass = 10;
			button_mass_B.selected = true;
			break;

		case ALLEGRO_KEY_N:
			g_player_1->g_mass = 15;
			break;

		case ALLEGRO_KEY_M:
				g_player_1->g_mass = 20;
				break;
		}

		if ((ev.type == ALLEGRO_EVENT_KEY_DOWN) && (ev.keyboard.keycode == ALLEGRO_KEY_E))
		{
			for (Bullets_p_2::iterator i = Bullets_p_2_.begin(); i != Bullets_p_2_.end(); ++i)
			{
				if (i->shot_state == false)
				{
					if (g_player_2->recoiling == false)
					{
						i->shot_state = true;
						i->start_angle = g_player_2->g_angle;
						i->start_force = g_player_2->g_force;
						i->trajectory();
						g_player_2->recoiling = true;
					}
					break;
				}
			}
		}

		ev.keyboard.keycode = 0;

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(45);
		return true;
}


Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
}

