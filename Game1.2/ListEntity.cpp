#include "ListEntity.h"



ListEntity::ListEntity()
{
}


ListEntity::~ListEntity()
{
}

void ListEntity::Draw(sf::RenderWindow* window)
{
	ListT<Entity>::Element <Entity>* pAux;
	pAux = Entities.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->Draw(window);
		pAux = pAux->getNext();
		std::cout << "DRAWW" << std::endl;
	}
}

void ListEntity::Update(const float daltaTime)
{
	ListT<Entity>::Element <Entity>* pAux;
	pAux = Entities.getpFirst();

	/*do
	{
		pAux->getInf()->Update(daltaTime);
		pAux = pAux->getNext();
	} /*while (pAux != Entities.getpCurr()); while (pAux != NULL);*/

	while (pAux != NULL)
	{
		pAux->getInf()->Update(daltaTime);
		pAux = pAux->getNext();
	}
}