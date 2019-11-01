#include "CardGameHeader.h"


int main()
{	
	GameManager manager;
	GAMESTATE status = INIT;
	manager.InitGame();
	
	while (true)
	{
		manager.MovePosition(manager.GetXPos(), manager.GetYPos());
	}


	return 0;
	while (true)
	{
		switch (status)
		{
		case INIT:

			status = READY;
			break;
		case READY:
			//메인화면 띄우기 메인 UI에서 특정 버튼을 누르면 status를 OPENCARD로 변경해주면됨.
			break;
		case OPENCARD:
			//시작버튼을 눌렀을때 카드가 모두 오픈되어있는것.(외우는시간이라고 보면됨)
			//카드를 오픈하는 함수 호출후 적정 시간이후 RUNNING으로 넘어가면됨
			status = RUNNING;
			break;
		case RUNNING:
			//카드들이 뒤집어지고 조작을 하면 UI가 업데이트 되는것
			//if 2장의 카드가 선택되었다면 STOP으로 가서 체크 2장 이하면 RUNNING status고정
			break;
		case STOP:
			//2개가 맞는지 확인하는 중. >> 맞다고 판단되면 CARDSTATE를 OPEN_CARD로 고정
			//아니면 CLOSE_CARD로 다시 변경해줘야됨. 판정이 끝나면 다시 RUNNING으로
			break;
		case SUCCES:
			//게임 클리어가 되었는지?
			//게임이 클리어되면 RESULT창으로 이동해서 맞춘 갯수를 표시해주면됨.
			status = RESULT;
			break;
		case FAIL:
			//게임 클리어가 되지 않는다면 FAIL로온 후 점수를 표시.
			status = RESULT;
			break;
		case RESULT:
			//점수와 함께 다시시작하겠냐는 것을 띄움.
			//if 다시한다고 하면 status = READY;
			break;
		default:
			cout << "잘못된 접근" << endl;
			cout << "아무 버튼이나 누르면 게임이 다시 시작됩니다." << endl;
			system("pause");
			status = INIT;
			break;
		}
	}

	system("pause");
	return 0;
}