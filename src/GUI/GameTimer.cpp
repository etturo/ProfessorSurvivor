//
// Created by Ettore Turini on 06/10/25.
//

#include "../../includes/GUI/GameTimer.h"
#include "../../includes/Core/Application.h"

#include <iostream>

std::string Format(int elapsed_time) {
	if (elapsed_time<10)
		return "0" + std::to_string(elapsed_time);
	return std::to_string(elapsed_time);
}


GameTimer::GameTimer() : TimerText(TimerFont,"FPS: 0", 24) {
	if (!TimerFont.openFromFile("../../fonts/fps_font.otf"))
		std::cout << "Error loading font.";
	TimerText.setFillColor(sf::Color::White);
	TimerText.setPosition({Application::GetInstance()->GetWindowSize().x/2.0f,10});
	TimerText.setOrigin({TimerText.getLocalBounds().size.x/2.0f, 0});
}

void GameTimer::Update() {
	elapsed_second += Application::GetInstance()->GetDeltaT()->asSeconds();
	TimerText.setString(Format(static_cast<int>(elapsed_second)/60) + " : " + Format(static_cast<int>(elapsed_second)%60));
}

void GameTimer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(TimerText);
}
