//
// Created by Ettore Turini on 01/10/25.
//

#include "../includes/Player.h"

#include "SFML/System/Time.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "../includes/Application.h"

void Player::Update() {
	sf::Vector2f alpha{0,0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		alpha.x -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		alpha.x += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		alpha.y -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		alpha.y += 1.f;
	if (alpha.x != 0 || alpha.y != 0)
		move(alpha.normalized()*Application::GetInstance()->GetDeltaT()->asSeconds()*move_speed);

}
