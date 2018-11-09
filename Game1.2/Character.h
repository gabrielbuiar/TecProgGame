#pragma once
#include "Entity.h"
#include "Animator.h"
#include <iostream>

class Character :
	public Entity
{
public:
	Character(const char* textureFile = NULL, const float deltaTime = 0, const float speed = 0, const float jumpHeight = 0);
	~Character();
	void InitializeChar(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, const float speed, const float jumpHeight);
	//void setTexture(const char* textureFile);
	void Update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void calcMovement(const float deltaTime);
	void setTexture();

protected:
	Animator animator;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	unsigned int row;
	const char* textureFile;
	float switchTime;
	float deltaTime;

};