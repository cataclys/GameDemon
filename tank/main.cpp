#include "TankGame.h"
#include "Map.h"

int main(int argc, char* argv[])
{
	TankGame* pTankGame = TankGame::GetGameInstance();    //��ȡ��ϷΨһʵ��

	pTankGame->DoBeforGameStart();  //��Ϸ��ʼ֮ǰ��ȫ�ֳ�ʼ��
	pTankGame->StartGame();  //��Ϸ��ʼ
	pTankGame->OnGameStop();  //����Ϸ����ʱ�������ƺ���

	TankGame::DestoryGameInstance(); //���ٵ���Ϸʵ��

	return 0;
}