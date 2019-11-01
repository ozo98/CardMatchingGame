#include "CardGameHeader.h"
char MAP[22][56];


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
void Card::OpenCard(int x, int y, char alphabet)
{
	char str[2];
	str[0] = alphabet;
	Print2Screen(x, y, "┌─┐");
	Print2Screen(x, y + 1, "│  │");
	Print2Screen(x, y + 2, "└─┘");
	Print2Screen(x + 2, y + 1, str);
}
void Card::MatchCard(int x, int y, char alphabet)
{
	char str[2];
	str[0] = alphabet;
	Print2Screen(x, y, "┌─┐");
	Print2Screen(x, y + 1, "│  │");
	Print2Screen(x, y + 2, "└─┘");
	Print2Screen(x + 2, y + 1, str);
}
void Card::CloseCard(int x, int y)
{
	
	Print2Screen(x, y, "┌─┐");
	Print2Screen(x, y + 1, "│■│");
	Print2Screen(x, y + 2, "└─┘");
}
void Card::Print2Screen(int x, int y,const char* arr)
{
	strcpy_s(MAP[y], arr);
	cout << MAP[y] << endl;
}
void Card::Render()
{
	system("cls");
	cout << MAP[_posy][_posx];
}
void GameManager::MovePosition(int x, int y)
{
		COORD cursorPosition = { x,y };
		int n;
		while (true)
		{
			if (_kbhit())
			{
				n = _getch();
				n = toupper(n);
				switch (n)
				{
				case 'S':
					cout << "S pressed" << endl;
					cursorPosition.Y -= 6;
					curYPos -= 6;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
					break;
				case 'A':
					cout << "A pressed" << endl;
					cursorPosition.X -= 6;
					curXPos -= 6;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
					break;
				case 'D':
					cout << "D pressed" << endl;
					cursorPosition.X += 6;
					curXPos += 6;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
					break;
				case 'W':
					cout << "W pressed" << endl;
					cursorPosition.Y += 6;
					curYPos += 6;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
					break;
				case 'F':
					cout << "F pressed" << endl;

				default:
					break;
				}
				
			}
		}
		

}
int GameManager::GetXPos()const { return curXPos; }
int GameManager::GetYPos()const { return curYPos; }
void GameManager::SetXPos(int x) { curXPos = x; }
void GameManager::SetYPos(int y) { curYPos = y; }
Card& GameManager::GetCurrentCard(int idx1)
{
	return _card_list[idx1];
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
		_card_list[i].SetXPos((i % 6) * 8 + 3);
		_card_list[i].SetYPos((i / 6) * 4 + 1);
		_card_list[i].SetState(CLOSE_CASE);
	}
}
