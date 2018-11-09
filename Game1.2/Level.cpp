#include "Level.h"

Level::Level() :
	///window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "GAME", sf::Style::Default)
		view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(static_cast<float>(WINDOW_WIDHT), static_cast<float>(WINDOW_HEIGHT)))
		///backgroundSprite()

	{

	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "GAME", sf::Style::Default);
		///Player texture and sprite
		///playerText.loadFromFile(PLAYER_TEXTURE_FILE);
		///playerSprite.setTexture(playerText);
		///playerSprite.setScale(2.0f, 1.0f);
		///player->setSprite(&playerSprite);
		///player->setPosition(sf::Vector2f(float(playerText.getSize().x / 2.0f), float(WINDOW_HEIGHT /*//* 2.0f/* - playerText.getSize().y / 2.0f)));*/

		//Player texture and sprite
		

		//Background texture and sprite
	if (!backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILE))
		std::cout << "ERROR" << std::endl;
		//backgroundTexture.setRepeated(true);
		backgroundSprite.setTexture(backgroundTexture);
		//backgroundSprite.setTextureRect(sf::IntRect(0, 0, 3000, 1080));
		sf::Vector2f backgroundScale;
		backgroundScale.x = float(WINDOW_WIDHT / backgroundTexture.getSize().x);
		backgroundScale.y = float(WINDOW_HEIGHT / backgroundTexture.getSize().y) + 0.75f;
		backgroundSprite.setScale(backgroundScale);
		//backgroundSprite.setOrigin(0.0f, 0.0f);
		backgroundSprite.setPosition(0.0f, 0.0f);

		//Background layer 1 texture and sprite
		///backgroundL1Text.loadFromFile(BACKGROUND_LAYER_1);
		///backgroundLayer1.setTexture(backgroundL1Text);
		///backgroundLayer1.setScale(3.0f, 2.0f);

		//Platforms
		///platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, -100.0f), sf::Color::White));
		///platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(800.0f, -100.0f), sf::Color::Red));
		///platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(float(playerText.getSize().x / 2.0f), float(WINDOW_HEIGHT / 2.0f - playerText.getSize().y / 2.0f)), sf::Color::Blue));
		///platforms.push_back(Platform(nullptr, sf::Vector2f(WINDOW_WIDHT, 5.0f), sf::Vector2f(WINDOW_WIDHT / 2.0f, WINDOW_HEIGHT), sf::Color::Magenta));
		///platforms.push_back(Platform(nullptr, sf::Vector2f(1.0f, WINDOW_HEIGHT), sf::Vector2f(0.0f, WINDOW_HEIGHT / 2.0f), sf::Color::Green));
		///platforms.push_back(Platform(nullptr, sf::Vector2f(0.05f, WINDOW_HEIGHT * 2), sf::Vector2f(-0.025f, WINDOW_HEIGHT / 2.0f), sf::Color(0, 0, 0, 0)));

		///ResizeView();
		///view.setCenter(WINDOW_WIDHT / 2.0f, WINDOW_HEIGHT - playerText.getSize().y / 1.5f);*/
	}


Level::~Level()
{
}

void Level::ResizeView()
{
	float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void Level::InitializePlayers()
{
	Player* pAux;
	pAux = new Player();
	pAux->InitializePlayer(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100.0f, 150.0f), PLAYER_TEXTURE_FILE, sf::Vector2u(6, 1), 200.0f, 200.0f);
	Entities.include(*pAux);
}

void Level::InitializePlatforms()
{
	Platform* pAux;
	pAux = new Platform();
	pAux->InitializePlatform(sf::Vector2f(0.0f, 50.0f), sf::Vector2f(150.0f, 20.0f), PLAYER_TEXTURE_FILE);
	Entities.include(*pAux);
}

void Level::Execute()
{
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;

		while (window->pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				//Closes window
				window->close();
				break;

			case sf::Event::Resized:
				//Resize window and view
				//ResizeView();
				break;

			default:
				break;
			}
		}
		//Move the player and the view so that the player keeps at a little less than the half of the screen
		view.setCenter(sf::Vector2f(WINDOW_WIDHT / 2.0f, WINDOW_HEIGHT / 2.0f));
		///player->Update(deltaTime)
		///*if (player1->getPosition().x >= ((WINDOW_WIDHT / 2.0f) - (WINDOW_WIDHT * PLAYERXPOSSCALE)))
		///{
		///	view.setCenter(player->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE), WINDOW_HEIGHT - playerText.getSize().y / 1.5f);
		///	backgroundSprite.setPosition(sf::Vector2f(player->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.0f), 0.0f));
		///}*/
		///std::cout << "ViewX: " << view.getCenter().x << " ViewY: " << view.getCenter().y << " PlayerX: " << player->getPosition().x << " PlayerY: " << player->getPosition().y << "PlayerText: "<< playerText.getSize().y << std::endl;
		///std::cout << "PlayerX: " << player->getPosition().x << " PlayerY: " << player->getPosition().y << " BackX: " << backgroundSprite.getPosition().x << " BackY: " << backgroundSprite.getPosition().y << std::endl;

		///*sf::Vector2f direction;

		///Check if the player is colliding with any platform
		///for (Platform& platform : platforms)*/
		///	/*if (platform.getCollision().checkCollision(player->getCollision(), direction, 1.0f))
		///		player->onCollision(direction);*/

		Entities.Update(deltaTime);

		//Clear the window and draw the player and the platforms*/
		window->clear();
		window->setView(view);
		window->draw(backgroundSprite);
		Entities.Draw(window);
		///window.draw(backgroundLayer1);
		///player->Draw(window);
		///for (Platform& platform : platforms)
		///	platform.Draw(window);

		window->display();

	}
}
