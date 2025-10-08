//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_FPSCOUNTER_H
#define CMAKESFMLPROJECT_FPSCOUNTER_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Graphics/Text.hpp"

class FPSCounter : public sf::Drawable{
private:
	sf::Text FPS_text;
	sf::Font font;
public:
	FPSCounter();
	void ComputeFPS();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	void fps_draw(sf::RenderTarget& target, sf::Time delta_time);
};


#endif //CMAKESFMLPROJECT_FPSCOUNTER_H