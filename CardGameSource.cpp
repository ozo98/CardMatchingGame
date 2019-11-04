#include "CardGameHeader.h"

char map[23][41]{
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

char Alphabet::GetAlphabet()const { return _alphabet; }
void Alphabet::SetAlphabet(char alphabet) { this->_alphabet = alphabet; }
bool Alphabet::GetUsed()const { return _used; }
void Alphabet::SetUsed(bool what) { this->_used = what; }
Alphabet::Alphabet() : _alphabet(NULL), _used(false) {};



void Card::SetAlphabet(char a) { _alphabet.SetAlphabet(a); }
CARDSTATE Card::GetState()const { return _state; }
void Card::SetState(CARDSTATE a) { _state = a; }
int Card::GetXPos()const { return _posx; }
void Card::SetXPos(int x) { _posx = x; }
int Card::GetYPos()const { return _posy; }
void Card::SetYPos(int y) { _posy = y; }
bool Card::GetUsed()const { return _used; }
void Card::SetUsed(bool isUsed) { _used = isUsed; }
Alphabet Card::GetAlphabet()const { return _alphabet; }
void Card::OpenCard()
{
	this->SetState(OPEN_CASE);
}
void Card::MatchCard()
{

}
void Card::CloseCard()
{
	this->SetState(CLOSE_CASE);
}

void GameManager::PlayGame()
{
	curXPos = 5;
	curYPos = 5;
	int n;
	while (true)
	{

		if (_kbhit())
		{
			n = _getch();
			n = toupper(n);
			system("cls");
			switch (n)
			{
			case 'S':
				//cout << "S pressed" << endl;
				if (curYPos > 0)
				{
					map[curYPos][curXPos] = 0;
					curYPos += 4;
					CHECK(curXPos, curYPos);
					map[curYPos][curXPos] = 3;
				}
				//GetCurrentCard(0).CloseCard(cursorPosition.X,cursorPosition.Y);
				cout << map[curYPos][curXPos] << endl;
				Render();
				break;
			case 'A':
				//cout << "A pressed" << endl;
				if (curXPos > 0)
				{
					map[curYPos][curXPos] = 0;
					curXPos -= 6;
					CHECK(curXPos, curYPos);
					map[curYPos][curXPos] = 3;
				}
				//GetCurrentCard(0).CloseCard(cursorPosition.X, cursorPosition.Y);
				cout << map[curYPos][curXPos] << endl;
				Render();
				break;
			case 'D':
				//cout << "D pressed" << endl;
				if (curXPos > 0)
				{
					map[curYPos][curXPos] = 0;
					curXPos += 6;
					CHECK(curXPos, curYPos);
					map[curYPos][curXPos] = 3;
				}
				//GetCurrentCard(0).CloseCard(cursorPosition.X, cursorPosition.Y);
				cout << map[curYPos][curXPos] << endl;
				Render();
				break;
			case 'W':
				//cout << "W pressed" << endl;
				if (curYPos > 0)
				{
					map[curYPos][curXPos] = 0;
					curYPos -= 4;
					CHECK(curXPos, curYPos);
					map[curYPos][curXPos] = 3;
				}
				//GetCurrentCard(0).CloseCard(cursorPosition.X, cursorPosition.Y);
				cout << map[curYPos][curXPos] << endl;
				Render();
				break;
			case 'F':
				for (int i = 0; i < 30; i++)
				{
					int x = GetCurrentCard(i).GetXPos();
					int y = GetCurrentCard(i).GetYPos();
					if (x == curXPos && y + 2 == curYPos)
					{
						Check(GetCurrentCard(i));
					}
				}
				//이게 답은 아님,, 하지만 이런 방향으로 해보세요
				//이함수에서 가진건 카드 좌표밖에 없으니. 좌표값과 동일한 위치에 있는
				// 실제 데이터가 있는 배열의 index = [x][y-2]
				//카드를 가져와서 OpenCard()해주시면 됩니다. Check라는 함수 원형이랑 대충 틀만들어 놨으니
				//함수안에 구현하시고 여기는 Check(ref) 입력하면 자동으로 실행되게 하시면 됩니다.
				
				break;
			default:
				break;
			}
		}
		
	}
}
void GameManager::Check(Card&ref)
{
	_check_list[_checkCount] = ref;
	_check_list[_checkCount].OpenCard();
	_checkCount++;
	if (_checkCount >= 2)
	{
		if (!IsSame(_check_list))
		{
			_check_list[0].CloseCard();
			_check_list[1].CloseCard();
		}
		_checkCount = 0;
	}
	return;
}
bool GameManager::IsSame(Card* ref)
{
	char alphabet1 = ref[0].GetAlphabet().GetAlphabet();
	char alphabet2 = ref[1].GetAlphabet().GetAlphabet();
	if (alphabet1 == alphabet2)
	{
		return true;
	}
	return false;
}
int GameManager::GetXPos()const { return curXPos; }
int GameManager::GetYPos()const { return curYPos; }
void GameManager::SetXPos(int x) { curXPos = x; }
void GameManager::SetYPos(int y) { curYPos = y; }
GAMESTATE GameManager::GetStatus()const
{
	return _status;
}
Card& GameManager::GetCurrentCard(int idx)
{
	return _card_list[idx];
}
void GameManager::Render()
{
	system("cls");
	int x[30], y[30];
	char alphabet[30];
	int idx = 0;

	for (idx = 0; idx < 30; idx++)
	{
		x[idx] = GetCurrentCard(idx).GetXPos();
		y[idx] = GetCurrentCard(idx).GetYPos();
		map[y[idx]][x[idx]] = GetCurrentCard(idx).GetAlphabet().GetAlphabet();
		alphabet[idx] = GetCurrentCard(idx).GetAlphabet().GetAlphabet();
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
				cout << '.';
			else if (map[i][j] == 3)
			{
				cout << '^';
			}
			else
			{
				if (GetCurrentCard(idx).GetState() == OPEN_CASE)
				{
					map[i][j] = alphabet[idx];
					cout << map[i][j];
				}
				else
				{
					cout << ' ';
				}
				idx++;
			}
		}
		cout << endl;
	}
}
void GameManager::OpenCard()
{
	system("cls");
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
	Sleep(2000);

	_status = RUNNING;
}
void GameManager::MainMenu()
{
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{ 26,10 };
	int key;
	MENU;
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
					_status = OPENCARD;
					return;
				}
				else
				{
					cout << "게임 종료" << endl;
					exit(0);
				}
			default:
				break;
			}
		}

		SetConsoleCursorPosition(handle, pos);
		cout << ">";
	}

}
void GameManager::InitGame()
{

	point = 0;
	int CardIndex, AlphaIndex;
	// Note: 알파벳 문자 배열을 초기화
	for (int i = 0; i < 26; i++)
	{
		_alphabet_list[i].SetUsed(false);
		_alphabet_list[i].SetAlphabet('A' + i);
	}
	for (int i = 0; i < 30; i++)
		_card_list[i].SetUsed(false);

	// Note: 카드 배열을 초기화

	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		while (true)
		{
			// Note: 임의의 알파벳 문자 인덱
			AlphaIndex = rand() % 26;
			if (!_alphabet_list[AlphaIndex].GetUsed())
			{
				_alphabet_list[AlphaIndex].SetUsed(true);
				break;
			}
		}

		// Note: 카드 배열
		for (int j = 0; j < 2; j++)
		{
			Sleep(10);
			while (1)
			{
				// Note: 임의의 카드 인덱스
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
		_card_list[i].SetState(CLOSE_CASE);
		_state_list[i] = GetCurrentCard(i).GetState();
	}
	_status = READY;
}
