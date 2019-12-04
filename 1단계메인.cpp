#include "1´Ü°è.h"

int main()
{
	GameManager manager;
	while (true)
	{
		switch (manager.GetStatus())
		{
		case GAMESTATE::GAMEINIT:
			manager.InitGame();
			break;
		case GAMESTATE::READY:
			manager.MainMenu();
			break;
		case GAMESTATE::LEVELSELECTION:
			break;
		case GAMESTATE::OPENCARD:
			manager.OpenCard();
			break;
		case GAMESTATE::RUNNING:
			manager.PlayGame();
			break;
		case GAMESTATE::SUCCESS:
			break;
		case GAMESTATE::FAIL:
			break;
		case GAMESTATE::RESULT:
			break;
		case GAMESTATE::CLOSEGAME:
			return 0;
		default:
			manager.DefaultException();
			break;
		}
	}
	return 0;
}