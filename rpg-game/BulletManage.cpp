#include "BulletManage.h"
#include <algorithm>


BulletManage::BulletManage(sf::RenderWindow& window, float bulletSpeed, float fireInterval) 
    : mBulletSpeed(bulletSpeed), mFireInterval(fireInterval)
{
    windowSize = window.getSize();
}

void BulletManage::setFireInterval(float fireInterval)
{
    mFireInterval = fireInterval;
}

void BulletManage::setBulletSpeed(float bulletSpeed)
{
    mBulletSpeed = bulletSpeed;
}

void BulletManage::Update(Player& player, Skeleton& skeleton)
{

        // Spawn bullets
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || 
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) &&
            shootTimer.getElapsedTime().asSeconds() > mFireInterval)
        {
            //Reset the timer immediately so we can't shoot again yet
            shootTimer.restart();

			sf::RectangleShape bulletShape(sf::Vector2f(20, 15));
			bulletShape.setPosition(player.getPosition());
			bulletShape.setOrigin(bulletShape.getSize() / 2.f);
			sf::Vector2f direction = skeleton.getPosition() - bulletShape.getPosition();

            if (direction != sf::Vector2f(0.f, 0.f))
            {
                float angleDegree = std::atan2f(direction.y, direction.x) * RADIAN_TO_DEGREE;
                bulletShape.setRotation(sf::degrees(angleDegree));

                Bullet bullet{ bulletShape, direction.normalized() };
				mBullets.push_back(bullet);
            }
        }

        // MOVEMENT LOOP (Must use auto&)
        for (auto& bullet : mBullets) {
			//bullet.shape.setPosition(bullet.shape.getPosition() + bullet.direction * bulletSpeed);
            bullet.shape.move(bullet.direction * mBulletSpeed);
        }

        // CLEANUP bullets when they are outside window
        std::erase_if(mBullets, [&](const Bullet& b) {
				sf::Vector2f pos = b.shape.getPosition();
                return (pos.x < 0 || pos.y < 0 || pos.x > windowSize.x || pos.y > windowSize.y);
		});
}

void BulletManage::Draw(sf::RenderWindow& window)
{
    for (const auto& bullet : mBullets)
        window.draw(bullet.shape);

}
