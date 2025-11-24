#include "Player.h"

Player::Player(float speed) : mSpeed(speed)
{
}


void Player::Load()
{
    mTexture.loadFromFile("Assets/Player/Textures/male_spritesheet.png");
    mSprite.setTexture(mTexture);
    // IntRect: {X, Y}, {width, height}
	XIndex = 0; // textture index for animation
	YIndex = 2;
    mSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
    sf::FloatRect bound = mSprite.getLocalBounds();
    mSprite.setOrigin(bound.size / 2.f);

    mSprite.scale(sf::Vector2f(2, 2));
    mSprite.setPosition(sf::Vector2f(1650, 800));
}

void Player::Update() 
{
	
	sf::Vector2f movement(0.0f, 0.0f);
	bool isMoving = false;
	// Move player by WSAD
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		movement.y -= mSpeed; // Move UP
		isMoving = true;
		YIndex = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		movement.y += mSpeed; // Move Down
		isMoving = true;
		YIndex = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		movement.x += mSpeed;
		YIndex = 3;
		isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{
		movement.x -= mSpeed;
		YIndex = 1;
		isMoving = true;
	}

	// mSprite.move() is generally faster than getPosition() + setPosition()
	mSprite.move(movement);

	// Walking Animation
	if (isMoving)
	{
		mAnimationCounter++;
		if (mAnimationCounter >= ANIMATION_DELAY)
		{
			mAnimationCounter = 0;
			// Advance the frame only when the counter resets
			// Use 1 to 8 for walking frames, skipping 0 which is idle.
			XIndex = (XIndex < 8) ? XIndex + 1: 1; 
			// Apply the new frame
			mSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
		} 
	}
	else // Not moving
	{
		XIndex = 0;
		mAnimationCounter = 0; // Reset AnimationCounter
		mSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
}


sf::Vector2f Player::getPosition() const
{
	return mSprite.getPosition();
}

