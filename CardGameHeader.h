#pragma once
#ifndef _CARD_MATCHING_HEADER_
#define _CARD_MATCHING_HEADER_
#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum CARDSTATE { OPEN_CASE = 1, CLOSE_CASE, SELECT_CASE }; // 카드의 상태의 표현을 가독성을 높이기 위해 열거를사용.
enum GAMESTATE { INIT, READY, OPENCARD, RUNNING, STOP, SUCCES, FAIL, RESULT }; // 게임의 상태의 이하동문

class Alphabet
{
	char _alphabet;
	bool _used;
public:
	Alphabet();
	void SetUsed(bool what);
	bool GetUsed()const;
	void SetAlphabet(char alphabet);
	char GetAlphabet()const;
};

class Card
{
	CARDSTATE _state;
	int _posx, _posy;
	Alphabet _alphabet;
	bool _used;
public:
	void SetAlphabet(char);
	CARDSTATE GetState()const;
	void SetState(CARDSTATE);
	int GetXPos()const;
	void SetXPos(int);
	int GetYPos()const;
	void SetYPos(int);
	bool GetUsed()const;
	void SetUsed(bool);
	Alphabet GetAlphabet()const;
	void OpenCard(int, int, char);
	void MatchCard(int, int, char);
	void CloseCard(int, int);
	void Print2Screen(int, int, const char*);
	void Render();
};

class GameManager
{
	Card _card_list[30]; //카드 30장의 리스트
	Alphabet _alphabet_list[26]; //알파벳 26개의 리스트
	int point;
	int curXPos;
	int curYPos;
public:
	int GetXPos()const;
	Card& GetCurrentCard(int);
	int GetYPos()const;
	void SetXPos(int);
	void SetYPos(int);
	void ShowData()
	{
		for (int i = 0; i < 30; i++)
		{
			cout << _card_list[i].GetAlphabet().GetAlphabet() << "  ";
		}
		cout << endl;
		for (int i = 0; i < 26; i++)
		{
			cout << _alphabet_list[i].GetAlphabet() << "  ";
		}

	}
	void InitGame();
	void MovePosition(int,int);
};

#endif // !_CARD_MATCHING_HEADER_
