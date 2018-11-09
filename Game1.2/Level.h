#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Platform.h"
#include "ListT.h"
#include "ListEntity.h"


class Level
{
public:
	Level();
	~Level();
	void Execute();
	void ResizeView();

	sf::RenderWindow* window;
	void InitializePlayers();
	void InitializePlatforms();

private:
	//Macros
	const int WINDOW_WIDHT = 1920;
	const int WINDOW_HEIGHT = 1080;
	const float VIEW_HEIGHT = 1000.0f;
	const char* PLAYER_TEXTURE_FILE = "Textures/walking.png";
	const char* BACKGROUND_TEXTURE_FILE = "Textures/Background.png";
	const float PLAYERXPOSSCALE = 1.0f / 9.0f;

	//sf::RenderWindow window;
	sf::View view;
	sf::Texture playerText;
	sf::Sprite playerSprite;

	//Lists of the different Entities
	ListEntity Entities;

	//Bakcground
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundL1Text;
	sf::Sprite backgroundLayer1;
};
