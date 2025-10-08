//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H
#include "../Core/Entity.h"


class Enemy : public Entity {
public:
	Enemy(std::string graphics_path) : Entity(graphics_path) {
		move_speed = 100;
	}
	void Update() override;
};


#endif //CMAKESFMLPROJECT_ENEMY_H