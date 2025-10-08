//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_APPLICATION_H
#define CMAKESFMLPROJECT_APPLICATION_H

#include <list>
#include <string>

#include "EnemySpawner.h"
#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../GUI/DeathScreen.h"
#include "../GUI/FPSCounter.h"
#include "../GUI/GameTimer.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
	Player *player;
	FPSCounter *FPS_counter;
	GameTimer *Timer;
	DeathScreen *death_screen;
	EnemySpawner enemy_spawner;
	sf::RenderWindow *window;
	sf::Time delta_time;
	sf::View HUD_view;
	sf::View world_view;
	std::list<Enemy*> enemies;
	static Application *instance;
	void Start();
	void Update();
	void Render(sf::RenderTarget &target);
	void EvaluateEvent(std::optional<sf::Event>);
public:
	bool is_game_over = false;

	Application(unsigned int width, unsigned int height, std::string window_name);
	~Application() {
		delete window;
	}
	Player *GetPlayer() {
		return player;
	}
	sf::Time *GetDeltaT() {
		return &delta_time;
	}
	sf::Vector2u GetWindowSize() {
		return window->getSize();
	}
	void AddEnemy(Enemy *entity) {
		enemies.push_front(entity);
	}
	static Application* GetInstance() {
		return instance;
	}
	unsigned int getTotSec() {
		return static_cast<unsigned int>(Timer->GetTotSec());
	}

	std::list<Enemy *> GetAllEnemies();

	void GameOver();
};


#endif //CMAKESFMLPROJECT_APPLICATION_H