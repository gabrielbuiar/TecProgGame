#pragma once
#include "ListT.h"
#include "Character.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Platform.h"

class ListEntity
{
public:
	ListEntity();
	~ListEntity();
	void include(Character& character) { 
		
	Entities.include(static_cast<Entity*> (&character)); }
	void include(Enemy& enemy) { Entities.include(static_cast<Entity*> (&enemy)); }
	void include(Obstacle& obstacle) { Entities.include(static_cast<Entity*> (&obstacle)); }
	void include(Platform& platform) { Entities.include(static_cast<Entity*> (&platform)); }
	void Draw(sf::RenderWindow* window);
	void Update(const float daltaTime);

private:
	ListT<Entity> Entities;

};