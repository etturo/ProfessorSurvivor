//
// Created by Ettore Turini on 01/10/25.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Entity : public sf::Drawable, public sf::Transformable {
private:
	sf::Sprite *graphics;
	sf::Texture *texture;
public:
	Entity(std::string graphics_path);
	~Entity() {
		delete graphics;
		delete texture;
	}
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};



#endif //ENTITY_H
