#ifndef _CARD_MATCHING_GAME_HEADER_
#define _CARD_MATCHING_GAME_HEADER_

#include <iostream>
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
cout << endl << endl; \
cout << "                               게 임 시 작" << endl;\
cout << "                               종       료" << endl;\
cout << "메뉴 조작법 : w 위 s 아래 f 누름" << endl; \
cout << endl <<endl;
#define LEVEL 	cout << endl<<"레벨 선택" << endl << endl << endl << endl<<endl;\
cout << "                   Easy : 200초" << endl;\
cout << "                사람이라면 클리어가능" << endl<<endl;\
cout << "                   Normal : 150초" << endl;\
cout << "                보통난이도 할만한정도" << endl<<endl;\
cout << "                   Hard : 100초 " << endl;\
cout << "       100초는 생각보다 짧은 시간이란걸 알게될거야" << endl<<endl<<endl;\
cout << "######### w : 위 #### s : 아래 #### f : 시작 ########"
#define _SUCCESS cout <<endl<<endl<<endl;\
cout << "     ######   #     #     ######   ######   ######   ######   ###### " <<endl;\
cout << "     #        #     #     #        #        #        #        #      " <<endl;\
cout << "     ######   #     #     #        #        ######   ######   ###### " <<endl;\
cout << "          #   #     #     #        #        #             #        # " <<endl;\
cout << "     ######   #######     ######   ######   ######   ######   ###### " <<endl;\
cout << endl<<endl;
#define _FAIL cout << endl<<endl<<endl;\
cout << "     #     #   ###   #     #     ######     #     #####   #      " <<endl;\
cout << "      #   #   #   #  #     #     #         # #      #     #      " <<endl;\
cout << "       ###    #   #  #     #     #####    #####     #     #      " <<endl;\
cout << "        #     #   #  #     #     #       #     #    #     #      " <<endl;\
cout << "        #      ###    #####      #       #     #  #####   ###### " <<endl;\
cout <<endl<<endl;


enum class CARDSTATE { OPEN_CASE = 1, CLOSE_CASE };
enum class GAMESTATE { GAMEINIT, READY, LEVELSELECTION, OPENCARD, RUNNING, STOP, SUCCESS, FAIL, RESULT, CLOSEGAME };
enum class LEVELSTATE { LEVEL1, LEVEL2, LEVEL3 };
class Alphabet
{
	char _alphabet;
	bool _used;
public:
	Alphabet();
	void SetUsed(bool);
	bool GetUsed()const;
	void SetAlphabet(char);
	char GetAlphabet()const;
};

class Card
{
	CARDSTATE _state;
	int _posx, _posy;
	Alphabet _alphabet;
	bool _used;
public:
	Card() : _alphabet(), _used(false), _state(CARDSTATE::CLOSE_CASE), _posx(0), _posy(0) {}
	void SetAlphabet(char);
	Alphabet GetAlphabet()const;
	CARDSTATE GetState()const;
	void SetState(CARDSTATE);
	int GetXPos()const;
	void SetXPos(int);
	int GetYPos()const;
	void SetYPos(int);
	bool GetUsed()const;
	void SetUsed(bool);
	void OpenCard();
	void CloseCard();
	bool operator==(const Card&);
};

class GameManager
{
	//for main() -> switch()
	GAMESTATE _status;
	static bool isGenerate;
	//for deltaTime
	int leftTime;
	int firstTime;
	LEVELSTATE _level;
	//for Check()
	int _checkCount;
	//for IsSame()
	Card* _check_list[2];
	Card _card_list[30];
	Alphabet _alphabet_list[26];
	int point, curXPos, curYPos;
	GameManager() : _alphabet_list(), _card_list(), _check_list(), _level(LEVELSTATE::LEVEL1),
		leftTime(0), firstTime(0), _checkCount(0), _status(GAMESTATE::GAMEINIT), curXPos(1), curYPos(1), point(0) {}
public:
	
	static GameManager* GetManagerInstance();
	void SetXPos(int);
	void SetYPos(int);
	int GetXPos()const;
	int GetYPos()const;
	void SetStatus(GAMESTATE);
	GAMESTATE GetStatus()const;
	Card& GetCurrentCard(int);

	void Check(Card&);
	bool IsSame(Card**);
	void Render();

	void InitGame();
	void MainMenu();
	void LevelSelection();
	void HowToPlay();
	void OpenCard();
	void PlayGame();
	void GameSuccess();
	void GameOver();
	void Result();
	void DefaultException();
	void EndGame();

};



#endif // !_CARDGAME_HEADER_

