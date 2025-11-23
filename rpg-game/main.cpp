#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr float RADIAN_TO_DEGREE = 180.f / 3.1415926f;

struct Bullet {
    sf::RectangleShape shape;
    sf::Vector2f direction;
};

int main()
{
    // ------------------------- INITIALIZE ------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // Requests 8x multisample anti-aliasing for smoother edges.

    sf::RenderWindow window(sf::VideoMode({ 1980, 1080 }), 
                            "SFML works!",
                            sf::Style::Default,
                            sf::State::Windowed,
                            settings);


    // ------------------------- LOAD ------------------------------------
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Assets/Player/Textures/male_spritesheet.png");
	sf::Sprite playerSprite(playerTexture);
    // IntRect: {X, Y}, {width, height}
    int XIndex{}, YIndex{2};
    playerSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
    sf::FloatRect playerBound = playerSprite.getLocalBounds();
    playerSprite.setOrigin(playerBound.size / 2.f);

    playerSprite.scale(sf::Vector2f(2, 2));
    playerSprite.setPosition(sf::Vector2f(1650, 800));


    sf::Texture skeletonTexture;
    skeletonTexture.loadFromFile("Assets/Skeleton/Textures/skeleton_spritesheet.png");
	sf::Sprite skeletonSprite(skeletonTexture);
    // IntRect: {X, Y}, {width, height}
    XIndex = 0;
    YIndex = 2;
    skeletonSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
    
    sf::FloatRect skeletonBound = skeletonSprite.getLocalBounds();
    skeletonSprite.setOrigin(skeletonBound.size / 2.f);

    skeletonSprite.scale(sf::Vector2f(2, 2));
    skeletonSprite.setPosition(sf::Vector2f(500, 300));


    // ------------------------- Bullets --------------------
    float bulletSpeed = 1.0f;
    std::vector<Bullet> bullets;
    sf::Vector2u windowSize = window.getSize();
    sf::Clock shootTimer;
	float fireInterval = 0.15f; // Wait 0.15 seconds between shots


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

        // Spawn bullets
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || 
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) &&
            shootTimer.getElapsedTime().asSeconds() > fireInterval)
        {
            //Reset the timer immediately so we can't shoot again yet
            shootTimer.restart();

			sf::RectangleShape bulletShape(sf::Vector2f(15, 10));
			bulletShape.setPosition(playerSprite.getPosition());
			bulletShape.setOrigin(bulletShape.getSize() / 2.f);
			sf::Vector2f direction = skeletonSprite.getPosition() - bulletShape.getPosition();

            if (direction != sf::Vector2f(0.f, 0.f))
            {
                float angleDegree = std::atan2f(direction.y, direction.x) * RADIAN_TO_DEGREE;
                bulletShape.setRotation(sf::degrees(angleDegree));

                Bullet bullet{ bulletShape, direction.normalized() };
				bullets.push_back(bullet);
            }
        }

        // MOVEMENT LOOP (Must use auto&)
        for (auto& bullet : bullets) {
			//bullet.shape.setPosition(bullet.shape.getPosition() + bullet.direction * bulletSpeed);
            bullet.shape.move(bullet.direction * bulletSpeed);
        }

        // CLEANUP bullets when they are outside window
        std::erase_if(bullets, [&](const Bullet& b) {
				sf::Vector2f pos = b.shape.getPosition();
                return (pos.x < 0 || pos.y < 0 || pos.x > windowSize.x || pos.y > windowSize.y);
		});

		// ------------------------- DRAW ------------------------------
        window.clear();
        window.draw(skeletonSprite);
        window.draw(playerSprite);
        for (const auto& bullet : bullets)
            window.draw(bullet.shape);

        window.display();
    }
}
