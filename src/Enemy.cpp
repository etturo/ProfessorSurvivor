//
// Created by Ettore Turini on 06/10/25.
//

#include "../includes/Enemy.h"

#include "../includes/Application.h"

void Enemy::Update() {
	sf::Vector2f playerPos = Application::GetInstance()->GetPlayer()->getPosition();
	sf::Vector2f dir = playerPos-this->getPosition();
	if (dir.x != 0 || dir.y != 0)
		move(dir.normalized());
}
