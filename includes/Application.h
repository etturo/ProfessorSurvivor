//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_APPLICATION_H
#define CMAKESFMLPROJECT_APPLICATION_H

#include <string>

#include "Enemy.h"
#include "Player.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
	Player *player;
	Enemy *enemy;
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

	static Application* GetInstance() {
		return instance;
	}
};


#endif //CMAKESFMLPROJECT_APPLICATION_H