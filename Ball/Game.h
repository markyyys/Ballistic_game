#include <allegro5/allegro_font.h>
#include "Bullet.h"
#include "Button.h"
#include "Gun.h"
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Game
{
	Button button_mass_1 = { 30,570,50,590 };
	Button button_mass_2 = { 60,570,80,590 };
	Button button_mass_3 = { 90,570,110,590 };

	Button button_mass_B = { 770,570,750,590 };
	Button button_mass_N = { 740,570,720,590 };
	Button button_mass_M = { 710,570,690,590 };

	ALLEGRO_BITMAP* background = NULL;

	typedef vector <Bullet> Bullets_p_1;
	Bullets_p_1 Bullets_p_1_;
	
	typedef vector <Bullet> Bullets_p_2;
	Bullets_p_2 Bullets_p_2_;

	typedef vector <Button> Buttons;
	Buttons Buttons_ = { button_mass_1,button_mass_2,button_mass_3,button_mass_B,button_mass_N,button_mass_M };

	Gun *g_player_1 = new Gun(1, 50);
	Gun *g_player_2 = new Gun(1, 50);

public:
	bool paused = false;
	double fps = 0.001;
	bool pressed_keys[ALLEGRO_KEY_MAX];

	void Init();
	void Update();
	void draw();
	bool button_handle(ALLEGRO_EVENT, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TIMEOUT);

	Game();
	~Game();
};

