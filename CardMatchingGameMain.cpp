#include "CardMatchingGameHeader.h"


int main()
{
	GameManager* manager;
	manager = GameManager::GetManagerInstance();
	manager->CardGame();
	return 0;
}