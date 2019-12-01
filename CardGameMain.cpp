#include "CardGameHeader.h"

int main()
{	
	GameManager manager;
	//system("mode con cols=80 lines=28 | Title Card Matching Game");
	
	while (true)
	{
		switch (manager.GetStatus())
		{
		case INIT:
			manager.InitGame();
			//���θ޴�, ���۹�ư������ Ready�� �Ѿ�� ���ᴩ���� �����.
			break;
		case READY:
			manager.MainMenu();
			//����ȭ�� ���� ���� UI���� Ư�� ��ư�� ������ status�� OPENCARD�� �������ָ��.
			break;
		case OPENCARD:
			manager.OpenCard();
			//���۹�ư�� �������� ī�尡 ��� ���µǾ��ִ°�.(�ܿ�½ð��̶�� �����)
			//ī�带 �����ϴ� �Լ� ȣ���� ���� �ð����� RUNNING���� �Ѿ���
			//status = RUNNING;
			break;
		case RUNNING:
			manager.PlayGame();
			//ī����� ���������� ������ �ϸ� UI�� ������Ʈ �Ǵ°�
			//if 2���� ī�尡 ���õǾ��ٸ� üũ. 2�� ���ϸ� RUNNING status����
			//2���� �´��� Ȯ���ϴ� ��. >> �´ٰ� �ǴܵǸ� CARDSTATE�� OPEN_CARD�� ����
			//�ƴϸ� CLOSE_CARD�� �ٽ� ��������ߵ�. ������ ������ �ٽ� RUNNING����
			break;
		case SUCCES:
			//���� Ŭ��� �Ǿ�����?
			//������ Ŭ����Ǹ� RESULTâ���� �̵��ؼ� ���� ������ ǥ�����ָ��.
			//status = RESULT;
			break;
		case FAIL:
			//���� Ŭ��� ���� �ʴ´ٸ� FAIL�ο� �� ������ ǥ��.
			Sleep(2000);
			system("pause");
			//status = RESULT;
			break;
		case RESULT:
			//������ �Բ� �ٽý����ϰڳĴ� ���� ���.
			//if �ٽ��Ѵٰ� �ϸ� status = READY;
			break;
		default:
			cout << "�߸��� ����" << endl;
			cout << "�ƹ� ��ư�̳� ������ ������ �ٽ� ���۵˴ϴ�." << endl;
			system("pause");
			//status = INIT;
			break;
		}
	}

	system("pause");
	return 0;
}