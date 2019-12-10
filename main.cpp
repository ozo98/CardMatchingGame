#include "header.h"

int main()
{
    GameManager manager;
    while (true)
    {
        switch (manager.GetStatus())
        {
            case GAMESTATE::INIT:
            manager.InitGame();
            break;
        case GAMESTATE::READY:
            manager.MainMenu();
            break;
        case GAMESTATE::LEVELSELECTION:
            manager.LevelSelcetion();
            break;
        case GAMESTATE::OPENCARD:
            manager.OpenCard();
            break;
        case GAMESTATE::RUNNING:
            manager.PlayGame();
            break;
        case GAMESTATE::SUCCESS:
            manager.GameSuccess();
            break;
        case GAMESTATE::FAIL:
            manager.GameOver();
            break;
        case GAMESTATE::RESULT:
            manager.Result();
            break;
        case GAMESTATE::CLOSEGAME:
            manager.EndGame();
            return 0;
        default:
            manager.DefaultException();
            break;
        }
    }
    return 0;
}
