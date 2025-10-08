//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_APPLICATION_H
#define CMAKESFMLPROJECT_APPLICATION_H

#include <list>
#include <string>

#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../GUI/FPSCounter.h"
#include "../GUI/GameTimer.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
	Player *player;
	FPSCounter *FPS_counter;
	GameTimer *Timer;
	sf::RenderWindow *window;
	sf::Time delta_time;
	std::list<Entity*> game_objects;
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
	void AddGameObj(Entity *entity) {
		game_objects.push_front(entity);
	}
	static Application* GetInstance() {
		return instance;
	}

	std::list<Entity> 
};


#endif //CMAKESFMLPROJECT_APPLICATION_H