//
// Created by Ettore Turini on 06/10/25.
//

#include "../includes/Application.h"

#include <iostream>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

void fps_draw(sf::RenderTarget& target, sf::Time delta_time);

void Application::Start() {
	player = new Player("../../assets/stef.png");
	enemy = new Enemy("../../assets/ciccio.jpg");
}

void Application::Update() {
	player->Update();
	enemy->Update();
}

void Application::Render(sf::RenderTarget &target) {
	target.draw(*enemy);
	target.draw(*player);
	fps_draw(target, delta_time);
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

void fps_draw(sf::RenderTarget& target, sf::Time delta_time) {
	sf::Font font;
	if (!font.openFromFile("../../fonts/fps_font.otf"))
		std::cout << "Error loading font.";

	static float timeSinceLastUpdate = 0.f;
	static int frame_count = 0;

	timeSinceLastUpdate += delta_time.asSeconds();
	++frame_count;

	static sf::Text fpsText(font, "FPS: 0", 24);
	fpsText.setFillColor(sf::Color::White);
	fpsText.setPosition({10,10});

	if (timeSinceLastUpdate >= 1.f){
		fpsText.setString("FPS: " + std::to_string(frame_count));
		timeSinceLastUpdate = 0.f;
		frame_count = 0;
	}

	target.draw(fpsText);
}

Application* Application::instance = nullptr;