//
// Created by Ettore Turini on 01/10/25.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"

class Entity : public sf::Drawable, public sf::Transformable {
private:
	sf::Sprite *graphics;
	sf::Texture *texture;
protected:
	int		hp;
	int		max_hp;
	int	move_speed;
public:
	Entity(std::string graphics_path);

	~Entity() {
		delete graphics;
		delete texture;
	}
	void SetSpeed(int speed) {
		move_speed = speed;
	}
	void SetHP(int hp) {
		this->hp = hp;
	}
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual void Update() = 0;
};

#endif //ENTITY_H
