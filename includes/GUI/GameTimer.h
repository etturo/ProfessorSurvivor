//
// Created by Ettore Turini on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_GAMETIMER_H
#define CMAKESFMLPROJECT_GAMETIMER_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class GameTimer : public sf::Drawable {
private:
	double elapsed_second;
	sf::Text TimerText;
	sf::Font TimerFont;
public:
	GameTimer();
	double GetTotSec() {
		return elapsed_second;
	}
	void Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CMAKESFMLPROJECT_GAMETIMER_H