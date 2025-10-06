//
// Created by Ettore Turini on 01/10/25.
//

#include "../includes/Entity.h"
#include <string>
#include "SFML/Graphics/RenderTarget.hpp"

Entity::Entity(std::string graphics_path) {
	texture = new sf::Texture(graphics_path);
	graphics = new sf::Sprite(*texture);
	hp = max_hp;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(*graphics, states);
}
