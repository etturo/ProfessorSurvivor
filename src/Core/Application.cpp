//
// Created by Ettore Turini on 06/10/25.
//

#include "../../includes/Core/Application.h"
#include "../../includes/GUI/FPSCounter.h"
#include "../../includes/GUI/GameTimer.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

void Application::Start() {
	player = new Player("../../assets/stef.png");
	AddGameObj(player);
	AddGameObj(new Enemy("../../assets/ciccio.jpg"));
	FPS_counter = new FPSCounter();
	Timer = new GameTimer();
	player->SetSpeed(250);
}

void Application::Update() {
	for (Entity *obj: game_objects) {
		obj->Update();
	}
	FPS_counter->ComputeFPS();
	Timer->Update();
}

void Application::Render(sf::RenderTarget &target) {
	for (Entity *entity: game_objects) {
		target.draw(*entity);
	}
	target.draw(*FPS_counter);
	target.draw(*Timer);
}

void Application::EvaluateEvent(std::optional<sf::Event> event) {
	if (event->is<sf::Event::Closed>())
	{
		window->close();
	}
}

Application::Application(unsigned int width, unsigned int height, std::string window_name) {
	window = new sf::RenderWindow(sf::VideoMode({width, height}), window_name);
	window->setFramerateLimit(60);

	instance = this;

	sf::Clock clock;

	Start();
	while (window->isOpen())
	{
		delta_time = clock.restart();
		while (const std::optional event = window->pollEvent())
		{
			EvaluateEvent(event);
		}

		Update();

		window->clear();
		Render(*window);
		window->display();
	}
}

Application* Application::instance = nullptr;