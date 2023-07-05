#include "Header.h"

void Player::Input_poll() {
	while (!stop) {
		if (GetAsyncKeyState(VK_RIGHT)) {
			this-> x += 2;
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			(this-> x <= 0)? this-> x = 0 : this-> x -= 2;
		}
		// ----------------------------------------------------------
		if (GetAsyncKeyState(VK_DOWN)) {
			this-> y += 1;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			(this-> y <= 0)? this-> y = 0 : this-> y -= 1;
		}
		if (GetAsyncKeyState(VK_LSHIFT | VK_RSHIFT)) {
			std::this_thread::sleep_for(std::chrono::milliseconds((this->movement_delay / 4) * 3));
			continue;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(this->movement_delay));
	}
}

void Entity::Set_Coords(unsigned int to_x, unsigned int to_y) {
	this->x = to_x;
	this->y = to_y;
}

void Goal_block::Goal_reached(Player *Player_inst) {
	if (this->x == Player_inst->x && this->y == Player_inst->y) {
		
	}
}
void Set_flag(Flags here) {
	Game_flag = here;
}

/*void printer(unsigned int& x, unsigned int& y, std::string sprite) {
	while (!stop) {
		std::cout << "\033[" + std::to_string(y + 1) + ';' + std::to_string(x + 1) + 'H';
		std::cout << sprite;
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		std::cout << "\033[2K";
	}
}*/

void Entity::display_self() {
	std::cout << "\033[" + std::to_string(this->y) + ';' + std::to_string(this->x) + 'H';
	std::cout << this->sprite;
}
