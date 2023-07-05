#include "Header.h"

bool stop = false;
Flags Game_flag;
std::ofstream OutFile;
std::ifstream Infile;

Player player;
Goal_block portal;



int main() {
	//std::cout << "\033[?25l";
	//goalblock
	portal.sprite = "@";
	portal.x = 6;
	portal.y = 4;

	//player
	player.sprite = "P";
	player.movement_delay = 100;
	player.Set_Coords(0, 0);

	//confused?\
	  the thread asks for the function as defined in the class, then it asks for the element to use the function on
	std::thread t1(&Player::Input_poll, &player);
	
	for (int iter = 0; iter < 1000; ++iter) {
		portal.display_self();
		player.display_self();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "\033[1K";
	}

	stop = true;
	t1.join();
	return 0;
}
