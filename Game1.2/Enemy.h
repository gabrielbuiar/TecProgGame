#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Enemy();
	void InitializeEnemy(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
};

