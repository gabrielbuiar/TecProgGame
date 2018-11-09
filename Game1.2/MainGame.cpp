#include "MainGame.h"



MainGame::MainGame():
	Level1()
{
}


MainGame::~MainGame()
{
}

void MainGame::Execute()
{
	Level1.InitializePlayers();
	Level1.Execute();
}