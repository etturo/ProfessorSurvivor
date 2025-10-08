//
// Created by Ettore Turini on 08/10/25.
//

#include "../../includes/GUI/DeathScreen.h"

#include <iostream>

#include "../../INcludes/Core/Application.h"
#include "SFML/Graphics/RenderTarget.hpp"


DeathScreen::DeathScreen() : death_text(font, "FINE.", 780){
	if (!font.openFromFile("../../fonts/fps_font.otf"))
		std::cout << "Error loading font.";
	death_text.setFillColor({255,0,0});
	death_text.setOrigin(sf::Vector2f{death_text.getGlobalBounds().size.x/2.0f, death_text.getGlobalBounds().size.y});
	death_text.setPosition(sf::Vector2f{Application::GetInstance()->GetWindowSize().x/2.f,
										Application::GetInstance()->GetWindowSize().y/2.f});
}

void DeathScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(death_text);
}
