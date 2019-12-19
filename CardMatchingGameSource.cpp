#include "CardMatchingGameHeader.h"

int map[23][41]{
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,1 },
{ 1,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,2,2,2,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

//GameManager is preferably created as singletons.
GameManager* GameManager::GetManagerInstance()
{
	if (!GameManager::isGenerate)
	{
		isGenerate = true;
		return new GameManager();
	}
	else
	{
		return NULL;
	}
}
bool GameManager::isGenerate = false;

//class Alphabet Function
//Get Set Alphabet object's Alphabet
char Alphabet::GetAlphabet()const { return _alphabet; }
void Alphabet::SetAlphabet(char alphabet) { this->_alphabet = alphabet; }
//Get Set Alphabet object's Used state
bool Alphabet::GetUsed()const { return _used; }
void Alphabet::SetUsed(bool what) { this->_used = what; }
//Constructor
Alphabet::Alphabet() : _alphabet(NULL), _used(false) {}

//class Card Function
bool Card::operator==(const Card& ref)
{
	if (!(this->GetXPos() == ref.GetXPos() && this->GetYPos() == ref.GetYPos()))
	{
		return false;
	}
	return true;
}
//Get Set Alphabet
void Card::SetAlphabet(char a) { this->_alphabet.SetAlphabet(a); }
Alphabet Card::GetAlphabet()const { return _alphabet; }
//Get Set CardState
CARDSTATE Card::GetState()const { return _state; }
void Card::SetState(CARDSTATE state) { this->_state = state; }
//Get Set Card's XPosition
int Card::GetXPos()const { return _posx; }
void Card::SetXPos(int x) { this->_posx = x; }
//Get Set Card's YPosition
int Card::GetYPos()const { return _posy; }
void Card::SetYPos(int y) { this->_posy = y; }
//Get Set Used;
bool Card::GetUsed()const { return _used; }
void Card::SetUsed(bool isUsed) { this->_used = isUsed; }
//Set Card State
void Card::OpenCard() { SetState(CARDSTATE::OPEN_CASE); }
void Card::CloseCard() { SetState(CARDSTATE::CLOSE_CASE); }

//class GameManager Function
//Helper Function
//Get Set current XPosition (cursor's Position)
int GameManager::GetXPos()const { return curXPos; }
void GameManager::SetXPos(int x) { this->curXPos = x; }
//Get Set current YPosition (cursor's Position)
int GameManager::GetYPos()const { return curYPos; }
void GameManager::SetYPos(int y) { this->curYPos = y; }
//Get Set GameManager's status / not Card State
GAMESTATE GameManager::GetStatus()const { return _status; }
void GameManager::SetStatus(GAMESTATE state) { this->_status = state; }

//Get GameManager's Card[idx]
Card& GameManager::GetCurrentCard(int idx) { return _card_list[idx]; }
//Check two cards are same
bool GameManager::IsSame(Card** ref)
{
	char alphabet1 = (*ref[0]).GetAlphabet().GetAlphabet();
	char alphabet2 = (*ref[1]).GetAlphabet().GetAlphabet();
	if (ref[0] == ref[1])
	{
		return false;
	}
	if (alphabet1 == alphabet2)
	{
		return true;
	}
	return false;
}
void GameManager::Check(Card& ref)
{
	_check_list[_checkCount] = &ref;
	if (_check_list[_checkCount] == _check_list[_checkCount - 1])
	{
		_check_list[_checkCount]->CloseCard();
		Render();
		_checkCount = 0;
		return;
	}
	else if (ref.GetState() == CARDSTATE::OPEN_CASE) return;
	_check_list[_checkCount]->OpenCard();
	_checkCount++;
	if (_checkCount >= 2)
	{
		if (!IsSame(_check_list))
		{
			Render();
			Sleep(1500);
			_check_list[0]->CloseCard();
			_check_list[1]->CloseCard();
		}
		else
			point++;
		_checkCount = 0;
	}

	return;
}

void GameManager::HowToPlay()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl;
	cout << "       #####################################" << endl;
	cout << "       #                                   #" << endl;
	cout << "       #       상하좌우 : wsad key         #" << endl;
	cout << "       #       카드 뒤집기 : f key         #" << endl;
	cout << "       #                                   #" << endl;
	cout << "       #####################################" << endl;
	Sleep(4000);
	system("cls");
}
//Called every frame and display map
void GameManager::Render()
{
	COORD coord{ 0,0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
	int x[30], y[30];
	int idx = 0;
	for (idx = 0; idx < 30; idx++)
	{
		x[idx] = GetCurrentCard(idx).GetXPos();
		y[idx] = GetCurrentCard(idx).GetYPos();
		map[y[idx]][x[idx]] = GetCurrentCard(idx).GetAlphabet().GetAlphabet();
	}
	idx = 0;
	for (int i = 0; i < 23; i++)
	{
		cout << "     ";
		for (int j = 0; j < 41; j++)
		{
			if (map[i][j] == 0)
				cout << ' ';
			else if (map[i][j] == 1)
				cout << '#';
			else if (map[i][j] == 2)
				cout << ':';
			else if (map[i][j] == 3)
				cout << '^';
			else
			{
				if (GetCurrentCard(idx).GetState() == CARDSTATE::OPEN_CASE)
					cout << (char)map[i][j];
				else
					cout << ' ';
				idx++;
			}
		}
		cout << endl;
	}
	cout << "남은 시간 : " << leftTime << " " << endl;
}

//Called by Main()
//Responsible for the overall reset of the game. + Init GameManager's Member
void GameManager::InitGame()
{
	system("mode con cols=78 lines=17 | title 카 드 매 칭 게 임");
	point = 0;
	leftTime = 0;
	int CardIndex, AlphaIndex;
	for (int i = 0; i < 26; i++)
	{
		_alphabet_list[i].SetUsed(false);
		_alphabet_list[i].SetAlphabet('A' + i);
	}
	for (int i = 0; i < 30; i++)
		_card_list[i].SetUsed(false);

	srand((u_int)time(NULL));
	for (int i = 0; i < 15; i++)
	{
		while (true)
		{
			AlphaIndex = rand() % 26;
			if (!_alphabet_list[AlphaIndex].GetUsed())
			{
				_alphabet_list[AlphaIndex].SetUsed(true);
				break;
			}
		}

		for (int j = 0; j < 2; j++)
		{
			Sleep(10);
			while (true)
			{
				CardIndex = rand() % 30;
				if (!_card_list[CardIndex].GetUsed())
				{
					_card_list[CardIndex].SetUsed(true);
					_card_list[CardIndex].SetAlphabet(_alphabet_list[AlphaIndex].GetAlphabet());
					break;
				}
			}
		}
	}
	for (int i = 0; i < 30; i++)
	{
		_card_list[i].SetXPos((i % 6) * 6 + 5);
		_card_list[i].SetYPos((i / 6) * 4 + 3);
		_card_list[i].SetState(CARDSTATE::CLOSE_CASE);
	}
	_status = GAMESTATE::READY;
}
//Just the main menu.
void GameManager::MainMenu()
{
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{ 26,10 };
	int key;
	MENU;
	SetConsoleCursorPosition(handle, pos);
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(handle, &info);
	while (true)
	{

		if (_kbhit())
		{
			system("cls");
			MENU;
			key = _getch();
			switch (key)
			{
			case 's': case 'S':
				pos.Y = 11;
				break;
			case 'w': case 'W':
				pos.Y = 10;
				break;
			case 'f': case 'F':
				if (pos.Y == 10)
				{
					_status = GAMESTATE::LEVELSELECTION;
					return;
				}
				else
				{
					_status = GAMESTATE::CLOSEGAME;
					return;
				}
			default:
				break;
			}
		}
		SetConsoleCursorPosition(handle, pos);
		cout << ">";
	}

}

//Shows and covers all cards for 5 seconds.
void GameManager::OpenCard()
{
	HowToPlay();
	for (int i = 0; i < 30; i++)
	{
		GetCurrentCard(i).OpenCard();
	}
	Render();
	Sleep(5000);
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		GetCurrentCard(i).CloseCard();
	}
	Render();
	_status = GAMESTATE::RUNNING;
	firstTime = clock();
}
//Can choose the level.
void GameManager::LevelSelection()
{
	system("cls");
	system("mode con cols=53 lines=25 | title 카 드 매 칭 게 임");
	int key;
	COORD coord{ 14,6 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	LEVEL;
	SetConsoleCursorPosition(handle, coord);
	while (true)
	{
		if (_kbhit())
		{
			system("cls");
			LEVEL;
			key = _getch();
			key = toupper(key);

			switch (key)
			{
			case 'S':
				coord.Y += 3;
				break;
			case 'W':
				coord.Y -= 3;
				break;
			case 'F':
				if (coord.Y == 6)
				{
					_level = LEVELSTATE::LEVEL1;
					_status = GAMESTATE::OPENCARD;
					return;
				}
				else if (coord.Y == 9)
				{
					_level = LEVELSTATE::LEVEL2;
					_status = GAMESTATE::OPENCARD;
					return;
				}
				else if (coord.Y == 12)
				{
					_level = LEVELSTATE::LEVEL3;
					_status = GAMESTATE::OPENCARD;
					return;
				}
			}
			if (coord.Y <= 6)
				coord.Y = 6;
			else if (coord.Y >= 12)
				coord.Y = 12;
		}
		SetConsoleCursorPosition(handle, coord);
		cout << ">";
	}
}

//The most important function.
//Responsible for playing games, checking cards, and checking scores.
void GameManager::PlayGame()
{
	curXPos = 5;
	curYPos = 5;

	int after;
	int time = clock();
	int key;
	int firstRender = 0;
	while (true)
	{
		after = clock();
		switch (_level)
		{
		case LEVELSTATE::LEVEL1:
			leftTime = 200 - (after / 1000 - firstTime / 1000);
			break;
		case LEVELSTATE::LEVEL2:
			leftTime = 150 - (after / 1000 - firstTime / 1000);
			break;
		case LEVELSTATE::LEVEL3:
			leftTime = 100 - ((after / 1000 - firstTime / 1000));
			break;
		}
		if (this->point >= 15)
		{
			this->_status = GAMESTATE::SUCCESS;
			map[curYPos][curXPos] = 0;
			break;
		}
		else if (this->leftTime <= 0)
		{
			this->_status = GAMESTATE::FAIL;
			map[curYPos][curXPos] = 0;
			break;
		}
		else if (_kbhit())
		{
			key = _getch();
			key = toupper(key);
			switch (key)
			{
			case 'S':
				map[curYPos][curXPos] = 0;
				curYPos += 4;
				CHECK(curXPos, curYPos);
				map[curYPos][curXPos] = 3;
				Render();
				break;
			case 'A':
				map[curYPos][curXPos] = 0;
				curXPos -= 6;
				CHECK(curXPos, curYPos);
				map[curYPos][curXPos] = 3;
				Render();
				break;
			case 'D':
				map[curYPos][curXPos] = 0;
				curXPos += 6;
				CHECK(curXPos, curYPos);
				map[curYPos][curXPos] = 3;
				Render();
				break;
			case 'W':
				map[curYPos][curXPos] = 0;
				curYPos -= 4;
				CHECK(curXPos, curYPos);
				map[curYPos][curXPos] = 3;
				Render();
				break;
			case 'F':
				for (int i = 0; i < 30; i++)
				{
					int x = GetCurrentCard(i).GetXPos();
					int y = GetCurrentCard(i).GetYPos();
					if (x == curXPos && y == curYPos - 2)
					{
						Check(GetCurrentCard(i));
					}
				}
				Render();
				break;
			default:
				break;
			}
		}

		if (firstRender <= 1)
		{
			firstRender++;
			Render();
		}
		if (after - time >= 1000)
		{
			Render();
			time = clock();
		}
	}
}
//Determine the success of the game.
void GameManager::GameSuccess()
{
	system("cls");
	system("mode con cols=70 lines=20");
	_SUCCESS;
	Sleep(3000);
	_status = GAMESTATE::RESULT;
}
void GameManager::GameOver()
{
	system("cls");
	system("mode con cols=70 lines=20");
	_FAIL;
	Sleep(3000);
	_status = GAMESTATE::RESULT;
}
//Report scores to result table
void GameManager::Result()
{
	cout << endl << endl << endl;
	cout << "             Your Point :  " << point << endl;
	cout << "             남 은 시 간 : " << leftTime << endl;
	cout << "          아무 버튼이나 누르면 재시작         " << endl << endl;
	int a = _getch();
	_status = GAMESTATE::GAMEINIT;
	return;
}
void GameManager::DefaultException()
{
	cout << "잘못된 접근" << endl;
	cout << "아무 버튼이나 누르면 게임이 다시 시작됩니다." << endl;
	_status = GAMESTATE::GAMEINIT;
	int a = _getch();
}
//The game ends when the user wants to exit.
void GameManager::EndGame()
{
	int endTimer = 3;
	system("cls");
	while (endTimer > 0)
	{
		cout << "게임이 종료됩니다......" << endTimer-- << endl;
		Sleep(1000);
	}
}
void GameManager::CardGame()
{
	while (true)
	{
		switch (_status)
		{
		case GAMESTATE::GAMEINIT:
			this->InitGame();
			break;
		case GAMESTATE::READY:
			this->MainMenu();
			break;
		case GAMESTATE::LEVELSELECTION:
			this->LevelSelection();
			break;
		case GAMESTATE::OPENCARD:
			this->OpenCard();
			break;
		case GAMESTATE::RUNNING:
			this->PlayGame();
			break;
		case GAMESTATE::SUCCESS:
			this->GameSuccess();
			break;
		case GAMESTATE::FAIL:
			this->GameOver();
			break;
		case GAMESTATE::RESULT:
			this->Result();
			break;
		case GAMESTATE::CLOSEGAME:
			this->EndGame();
			return;
		default:
			this->DefaultException();
			break;
		}
	}
}