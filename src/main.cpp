#include <SFML/Graphics.hpp>
#include "../includes/Entity.h"
#include "../includes/Player.h"
#include <iostream>

void fps_draw(sf::RenderTarget& target, sf::Time delta_time);

Player *player;

void GameStart() {
    player = new Player("../../assets/stef.png");
}

void GameUpdate(sf::Time delta_time) {
    player->Update(delta_time);
}

void GameRender(sf::RenderTarget& target, sf::Time delta_time) {
    target.draw(*player);
    fps_draw(target, delta_time);
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800, 600}), "ProfessorSurvivor");
    window.setFramerateLimit(60);

    sf::Clock clock;

    GameStart();
    while (window.isOpen())
    {
        sf::Time delta_time = clock.restart();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        GameUpdate(delta_time);

        window.clear();
        GameRender(window, delta_time);
        window.display();
    }
}

void fps_draw(sf::RenderTarget& target, sf::Time delta_time) {
    sf::Font font;
    if (!font.openFromFile("../../fonts/fps_font.otf"))
    {
        std::cout << "Error loading font.";
    }

    static float timeSinceLastUpdate = 0.f;
    static int frame_count = 0;

    timeSinceLastUpdate += delta_time.asSeconds();
    ++frame_count;

    static sf::Text fpsText(font, "FPS: 0", 24);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition({10,10});

    if (timeSinceLastUpdate >= 1.f){
        fpsText.setString("FPS: " + std::to_string(frame_count));
        timeSinceLastUpdate = 0.f;
        frame_count = 0;
    }

    target.draw(fpsText);
}
