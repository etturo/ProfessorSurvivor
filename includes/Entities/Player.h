//
// Created by Ettore Turini on 01/10/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include "../Core/Entity.h"
#include "../GUI/HPBar.h"
#include "SFML/System/Time.hpp"


class Player : public Entity {
private:
	HPBar hp_bar;
public:
	Player(std::string graphics_path) : Entity(graphics_path), hp_bar(hp, max_hp){
		max_hp = 100;
		hp = max_hp;
	}
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void Update() override;
};



#endif //PLAYER_H
