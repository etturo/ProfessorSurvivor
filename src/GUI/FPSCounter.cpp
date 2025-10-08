//
// Created by Ettore Turini on 06/10/25.
//

#include "../../includes/GUI/FPSCounter.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Time.hpp"
#include "../../includes/Core/Application.h"

#include <iostream>


FPSCounter::FPSCounter() : FPS_text(font,"FPS: 0", 24) {
	if (!font.openFromFile("../../fonts/fps_font.otf"))
		std::cout << "Error loading font.";
	FPS_text.setFillColor(sf::Color::White);
	FPS_text.setPosition({10,10});
}

void FPSCounter::ComputeFPS() {
	if (Application::GetInstance()->is_game_over == true)
		return ;
	static unsigned int frame_count = 0;
	static float timeSinceLastUpdate = 0.f;

	timeSinceLastUpdate += Application::GetInstance()->GetDeltaT()->asSeconds();
	++frame_count;

	if (timeSinceLastUpdate >= 1.f){
		FPS_text.setString("FPS: " + std::to_string(frame_count));
		timeSinceLastUpdate = 0.f;
		frame_count = 0;
	}
}

void FPSCounter::draw(sf::RenderTarget &target, sf::RenderStates states) const {

	target.draw(FPS_text);
}
