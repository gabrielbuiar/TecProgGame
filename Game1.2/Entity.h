#pragma once
#include"SFML/Graphics.hpp"

class Entity
{
public:
	Entity(const char * textureFile = NULL);
	~Entity();
	void InitializeEnt(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void Draw(sf::RenderWindow* window);
	virtual void setTexture(const char* textureFile);
	virtual void Update(float deltaTime) {}

protected:
	sf::RectangleShape base;
	sf::Texture texture;

};