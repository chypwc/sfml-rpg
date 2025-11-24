#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Skeleton.h"
#include "GameObject.h"

constexpr float RADIAN_TO_DEGREE = 180.f / 3.1415926f;

struct Bullet {
    sf::RectangleShape shape;
    sf::Vector2f direction;
};

class BulletManage : public GameObject
{
private:
    std::vector<Bullet> mBullets;
    float mBulletSpeed = 1.0f;
	float mFireInterval = 0.15f; // Wait 0.15 seconds between shots
    sf::Clock shootTimer;
    sf::Vector2u windowSize;

public:
    BulletManage(sf::RenderWindow& window, float bulletSpeed, float fireInterval);
    void setBulletSpeed(float bulletSpeed);
    void setFireInterval(float fireInterval);
    void Update(Player& player, Skeleton& skeleton);
    void Draw(sf::RenderWindow& window) override;
};

