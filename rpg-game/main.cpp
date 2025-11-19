#include <SFML/Graphics.hpp>

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

    sf::CircleShape shape(50.0f, 8);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f{400.0f, 10.0f});
    shape.setOutlineThickness(5.f);
    shape.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setPosition(sf::Vector2f(100.f, 300.f));
    //rectangle.setFillColor(sf::Color::Blue);
    sf::Texture wood("texture/Wood_259S.jpg");
    rectangle.setTexture(&wood);
    rectangle.setOrigin(rectangle.getSize() / 2.0f);
    rectangle.setRotation(sf::degrees(45));


    sf::RectangleShape rectangleBack(sf::Vector2f(100.f, 1.f));
    rectangleBack.setPosition(sf::Vector2f(100.f, 300.f));
    rectangleBack.setFillColor(sf::Color::Magenta);
    //rectangleBack.setOutlineColor(sf::Color::Red);
    rectangleBack.setOrigin(rectangleBack.getSize() / 2.0f);
    rectangleBack.setOutlineThickness(2.0f);

    //// triangle
    //sf::CircleShape triangle(80.f, 3);
    //triangle.setFillColor(sf::Color::Black);

    //// diamond
    //sf::CircleShape triangle(80.f, 4);

    // ------------------------- INITIALIZE ------------------------------

    while (window.isOpen())
    {
		// ------------------------- UPDATE ------------------------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

		// ------------------------- DRAW ------------------------------
        window.clear(sf::Color::White);
        window.draw(shape);
        window.draw(rectangleBack);
        window.draw(rectangle);
        window.display();
    }
}
