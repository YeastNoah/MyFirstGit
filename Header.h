#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

extern bool stop;

enum Flags {
	Menu,
	Game_running,
	Game_win,
	Game_lost,
	C_YU
};

extern Flags Game_flag;
extern std::ofstream OutFile;
extern std::ifstream Infile;

void Set_flag(Flags here);

class Entity {
public:
	unsigned int x;
	unsigned int y;

	std::string sprite;
	unsigned int movement_delay;
	
	//sets new coords/inits new coords
	void Set_Coords(unsigned int to_x, unsigned int to_y);
	//display sprite
	void display_self();
};

class Player : public Entity {
public:
	//catch commands
	void Input_poll();
	
};

class Goal_block : public Entity {
public:
	bool Scored;
	//doesn't move
	void Goal_reached(Player *Player_inst);
};

class Enemy : public Entity {
	//get dist between player and enemy through pythagorean theorem
	// get dir through comparison eg: px = 1, py = 1, ex = 3, ey = 3; both epos are larger, so go to right-up
};

extern Player player;
extern Goal_block Portal;

