//
// Created by Ettore Turini on 08/10/25.
//

#include "../../includes/Core/EnemySpawner.h"

#include <complex>
#include <iostream>

#include "../../includes/Core/Application.h"

float halfVectorLength(const sf::Vector2u& v) {
	return std::sqrt(v.x * v.x + v.y * v.y)/2.0f;
}

void EnemySpawner::Update() {
	static float timer = 0;
	timer += Application::GetInstance()->GetDeltaT()->asSeconds();
	float rand_value = ((std::rand()%6280)/1000.0f);
	if (timer > 1) {
		Enemy *new_enemy = new Enemy("../../assets/ciccio.jpg");
		new_enemy->setPosition(Application::GetInstance()->GetPlayer()->getPosition() + sf::Vector2f{static_cast<float>(std::cos(rand_value)), static_cast<float>(std::sin(rand_value))}*halfVectorLength(Application::GetInstance()->GetWindowSize()));
		Application::GetInstance()->AddEnemy(new_enemy);
		timer = 0;
		std::cout << rand_value << std::endl;
	}
}
