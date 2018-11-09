#include "Player.h"



Player::Player(const char* textureFile, float speed, float jumpHeight)
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

//	InitializePlayer(position, size, textureFile, imgCount, speed, jumpHeight);
}


Player::~Player()
{
}

void Player::InitializePlayer(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
}
