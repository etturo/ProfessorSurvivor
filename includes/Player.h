//
// Created by Ettore Turini on 01/10/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include "Entity.h"
#include "SFML/System/Time.hpp"


class Player : public Entity {
public:
	Player(std::string graphics_path) : Entity(graphics_path) {
	}
	void Update() override;
};



#endif //PLAYER_H
