#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Player();
	void InitializePlayer(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);

};