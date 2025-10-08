//
// Created by Ettore Turini on 08/10/25.
//

#ifndef CMAKESFMLPROJECT_HPBAR_H
#define CMAKESFMLPROJECT_HPBAR_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class HPBar : public sf::Drawable, public sf::Transformable{
private:
	sf::RectangleShape BackBar;
	sf::RectangleShape FillBar;
	int &hp_ref;
	int &max_hp_ref;
public:
	HPBar(int &hp_ref, int &max_hp_ref) : hp_ref(hp_ref), max_hp_ref(max_hp_ref) {
		BackBar.setSize({50,5});
		BackBar.setFillColor({125, 0,0});
		FillBar.setSize({50,5});
		FillBar.setFillColor({255, 0,0});
		FillBar.setOrigin(BackBar.getPosition() + BackBar.getLocalBounds().size/2.0f);
		BackBar.setOrigin(BackBar.getLocalBounds().getCenter());
		BackBar.setOutlineThickness(1.f);
		BackBar.setOutlineColor({0,0,0});
	}
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void Update();
};

#endif //CMAKESFMLPROJECT_HPBAR _H
