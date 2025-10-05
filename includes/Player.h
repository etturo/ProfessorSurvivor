//
// Created by Ettore Turini on 01/10/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include "Entity.h"
#include "SFML/System/Time.hpp"


class Player : public Entity {
private:
	int		hp;
	int		max_hp = 100;
	float	move_speed = 250;
public:
	Player(std::string graphics_path) : Entity(graphics_path) {
		hp = max_hp;
	}
	void Move(sf::Vector2f delta);
	void Update(sf::Time delta_time);
};



#endif //PLAYER_H
