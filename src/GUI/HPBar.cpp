//
// Created by Ettore Turini on 08/10/25.
//

#include "../../includes/GUI/HPBar.h"

#include "SFML/Graphics/RenderTarget.hpp"

void HPBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= this->getTransform();
	target.draw(BackBar, states);
	target.draw(FillBar, states);
}

void HPBar::Update() {
	FillBar.setSize({(BackBar.getSize().x * hp_ref) / max_hp_ref, 5});
}
