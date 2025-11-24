#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject
{
private:
    sf::Texture mTexture;
    sf::Sprite mSprite{mTexture};
    float mSpeed = 0.5f;
    int XIndex;
    int YIndex;int mAnimationCounter = 0; 
	const int ANIMATION_DELAY = 40; // e.g., only update the frame every 5 frames

public:
    Player(float speed);

    void Load();

    void Update();

	void Draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const;
};

