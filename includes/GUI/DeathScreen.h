//
// Created by Ettore Turini on 08/10/25.
//

#ifndef CMAKESFMLPROJECT_DEATHSCREEN_H
#define CMAKESFMLPROJECT_DEATHSCREEN_H

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class DeathScreen : public sf::Drawable{
private:
	sf::Text death_text;
	sf::Font font;
public:
	DeathScreen();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CMAKESFMLPROJECT_DEATHSCREEN_H