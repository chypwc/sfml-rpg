#include "Skeleton.h"

Skeleton::Skeleton()
{
}

void Skeleton::Load()
{
    mTexture.loadFromFile("Assets/Skeleton/Textures/skeleton_spritesheet.png");
	mSprite.setTexture(mTexture);
    // IntRect: {X, Y}, {width, height}
    int XIndex = 0;
    int YIndex = 2;
    mSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
    
    sf::FloatRect skeletonBound = mSprite.getLocalBounds();
    mSprite.setOrigin(skeletonBound.size / 2.f);

    mSprite.scale(sf::Vector2f(2, 2));
    mSprite.setPosition(sf::Vector2f(500, 300));


}
void Skeleton::Update()
{

}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

sf::Vector2f Skeleton::getPosition() const
{
	return mSprite.getPosition();
}

