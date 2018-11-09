#include "Enemy.h"

Enemy::Enemy(const char* textureFile, float speed, float jumpHeight)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	sf::Vector2u imgCount;
	imgCount.x = 0;
	imgCount.y = 0;

	InitializeEnemy(position, size, textureFile, imgCount, speed, jumpHeight);
}

Enemy::~Enemy()
{
}

void Enemy::InitializeEnemy(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
}
