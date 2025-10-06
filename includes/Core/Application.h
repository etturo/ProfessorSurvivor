//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_APPLICATION_H
#define CMAKESFMLPROJECT_APPLICATION_H

#include <string>

#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../GUI/FPSCounter.h"
#include "../GUI/GameTimer.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
	Player *player;
	Enemy *enemy;
	FPSCounter *FPS_counter;
	GameTimer *Timer;
	sf::RenderWindow *window;
	sf::Time delta_time;
	static Application *instance;
	void Start();
	void Update();
	void Render(sf::RenderTarget &target);
	void EvaluateEvent(std::optional<sf::Event>);

public:
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

	static Application* GetInstance() {
		return instance;
	}
};


#endif //CMAKESFMLPROJECT_APPLICATION_H