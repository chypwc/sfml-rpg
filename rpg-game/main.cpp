#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Player.h"
#include "Skeleton.h"
#include "BulletManage.h"

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

    // ------------------------- Bullets --------------------

    Player player(0.5f); // speed 
    player.Load();

    Skeleton skeleton;
    skeleton.Load();

    BulletManage bullets(window, .75f, 0.2f); // bulletSpeed, fireInterval(s)


    while (window.isOpen())
    {
		// ------------------------- UPDATE ------------------------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        player.Update();
        bullets.Update(player, skeleton);


		// ------------------------- DRAW ------------------------------
        window.clear();
        skeleton.Draw(window);
        player.Draw(window);
        bullets.Draw(window);

        window.display();
    }
}
