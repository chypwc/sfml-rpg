#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Skeleton : public GameObject
{
private:
    sf::Texture mTexture;
    sf::Sprite mSprite{mTexture};

public:
    Skeleton();

    void Load();

    void Update();

	void Draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const;
};

