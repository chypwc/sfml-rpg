#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // ------------------------- INITIALIZE ------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // Requests 8x multisample anti-aliasing for smoother edges.

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), 
                            "SFML works!",
                            sf::Style::Default,
                            sf::State::Windowed,
                            settings);

    // ------------------------- LOAD ------------------------------------
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Assets/Player/Textures/male_spritesheet.png");
	sf::Sprite playerSprite(playerTexture);
    // IntRect: {X, Y}, {width, height}
    int XIndex{}, YIndex{};
    playerSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
    playerSprite.scale(sf::Vector2f(2, 2));


    // ------------------------- INITIALIZE ------------------------------

    while (window.isOpen())
    {
		// ------------------------- UPDATE ------------------------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Move player by WSAD
		sf::Vector2f position = playerSprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		// ------------------------- DRAW ------------------------------
        window.clear(sf::Color::White);
        window.draw(playerSprite);
        window.display();
    }
}
