#include "Entity.h"
#include "iostream"



Entity::Entity(const char * textureFile)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	InitializeEnt(position, size, textureFile);
}


Entity::~Entity()
{
}

void Entity::InitializeEnt(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	base.setSize(size);
	base.setPosition(position);
	base.setOrigin(size / 2.0f);
	setTexture(textureFile);
}

void Entity::Draw(sf::RenderWindow* window)
{
	window->draw(base);
}

void Entity::setTexture(const char * textureFile)
{
	if (textureFile != NULL)
	{
		texture.loadFromFile(textureFile);
		base.setTexture(&texture);
	}
}
