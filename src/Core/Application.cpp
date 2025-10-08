//
// Created by Ettore Turini on 06/10/25.
//

#include "../../includes/Core/Application.h"

#include "../../includes/GUI/DeathScreen.h"
#include "../../includes/GUI/FPSCounter.h"
#include "../../includes/GUI/GameTimer.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

void Application::Start() {
	player = new Player("../../assets/stef.png");
	FPS_counter = new FPSCounter();
	Timer = new GameTimer();
	player->SetSpeed(250);
}

void Application::Update() {
	for (Entity *obj: enemies){
		obj->Update();
}
	player->Update();
	enemy_spawner.Update();
	world_view.setCenter(player->getPosition());
	window->setView(world_view);
	Timer->Update();
	FPS_counter->ComputeFPS();
}

void Application::Render(sf::RenderTarget &target) {

	for (Entity *entity : enemies) {
		target.draw(*entity);
	}
	target.draw(*player);

	window->setView(HUD_view);
	target.draw(*FPS_counter);
	target.draw(*Timer);
	if (is_game_over == true) {
		target.draw(*death_screen);
	}
}

void Application::EvaluateEvent(std::optional<sf::Event> event) {
	if (event->is<sf::Event::Closed>())
	{
		window->close();
	}
}

Application::Application(unsigned int width, unsigned int height, std::string window_name) {
	std::srand(std::time(nullptr));
	window = new sf::RenderWindow(sf::VideoMode({width, height}), window_name);
	window->setFramerateLimit(60);
	HUD_view = sf::View(sf::FloatRect{{0,0},{static_cast<float>(width), static_cast<float>(height)}});
	world_view = sf::View(sf::FloatRect{{0,0},{static_cast<float>(width), static_cast<float>(height)}});

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

std::list<Enemy *> Application::GetAllEnemies() {
	return enemies;
}

void Application::GameOver() {
	death_screen = new DeathScreen();
	is_game_over = true;
}

Application* Application::instance = nullptr;
