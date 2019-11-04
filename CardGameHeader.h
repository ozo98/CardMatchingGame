#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;
#define CHECK(i,j) 	if (i<= 5){i= 5;}if (j<= 5){j= 5;} if (i>=35) { i = 35;}  if (j>=21) { j=21;}
#define MENU	cout << endl << endl << endl;\
cout << "     ######     #     ####  ###     ######      #     #   #   # ######" << endl;\
cout << "     #         # #    #  ## #  #    #          # #    ## # # ## #     " << endl;\
cout << "     #        #####   ####  #  #    #   ###   #####   # #   # # ######" << endl;\
cout << "     #       #     #  # #   #  #    #    #   #     #  #       # #     " << endl;\
cout << "     ###### #       # #  ## ###     ######  #       # #       # ######" << endl;\
cout << endl << endl;\
cout << "                                 게 임 시 작" << endl;\
cout << "                                 종       료" << endl;\
cout << endl <<endl;
enum CARDSTATE { OPEN_CASE = 1, CLOSE_CASE };
enum GAMESTATE { INIT, READY, OPENCARD, RUNNING, STOP, SUCCES, FAIL, RESULT }; 

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
	Card() : _state(CLOSE_CASE),_posx(0),_posy(0){}
	void SetAlphabet(char);
	CARDSTATE GetState()const;
	Alphabet GetAlphabet()const;

	void SetState(CARDSTATE);
	int GetXPos()const;
	void SetXPos(int);
	int GetYPos()const;
	void SetYPos(int);
	bool GetUsed()const;
	void SetUsed(bool);
	void OpenCard();
	void MatchCard();
	void CloseCard();
};

class GameManager
{
	GAMESTATE _status;
	int _checkCount;
	Card _check_list[2];
	Card _card_list[30]; //카드 30장의 리스트
	CARDSTATE _state_list[30];
	Alphabet _alphabet_list[26]; //알파벳 26개의 리스트
	int point, curXPos, curYPos;
public:
	GameManager() : _checkCount(0),_status(INIT),curXPos(1),curYPos(1),point(0){}
	int GetXPos()const;
	bool IsSame(Card*);
	GAMESTATE GetStatus()const;
	void OpenCard();
	Card& GetCurrentCard(int);
	int GetYPos()const;
	void SetXPos(int);
	void SetYPos(int);
	void MainMenu();
	void InitGame();
	void PlayGame();
	void Render();
	void Check(Card&);
};
