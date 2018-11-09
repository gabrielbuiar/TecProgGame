#include "Character.h"



Character::Character(const char* textureFile, const float deltaTime, const float speed, const float jumpHeight)
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

	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
}


Character::~Character()
{
}

void Character::InitializeChar(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, const float speed, const float jumpHeight)
{
	InitializeEnt(position, size, textureFile);
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->textureFile = textureFile;
	switchTime = 1.0f / float(imgCount.x);
	faceRight = true;
	this->deltaTime = deltaTime;
	animator.InitializeAnim(imgCount, switchTime);
	animator.setTexture(textureFile);
}

/*void Character::setTexture(const char * textureFile)
{
	//base.setTextureRect(animator.UpdateAnimator(textureFile, faceRight, deltaTime));
	if (!texture.loadFromFile(textureFile))
		std::cout << "PROBLEM!!!!!" << std::endl;
	base.setTexture(&texture);
}*/

void Character::Update(float deltaTime)
{
	calcMovement(deltaTime);
	base.setTextureRect(animator.UpdateAnimator(textureFile, faceRight, deltaTime));
	base.move(velocity * deltaTime);
}

void Character::draw(sf::RenderWindow& window)
{
	window.draw(base);
}

void Character::calcMovement(const float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0)
	{
		row = 0;
		if (velocity.y < -1.0f)
			row = 2;
	}
	else
	{
		row = 1;

		if (velocity.y < -1.0f)
			row = 2;

		if (velocity.x > 0)
			faceRight = true;
		else
			faceRight = false;
	}
}

void Character::setTexture()
{
	animator.setTexture(textureFile);
}
