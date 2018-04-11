#pragma once
#include "GameApp.h"
#include "Common.h"
class TankGame:public GameApp
{
private:
	TankGame();
public:
	static TankGame* GetGameInstance();
	static void DestoryGameInstance();

	virtual void DoBeforGameStart(); //��Ϸ��ʼ֮ǰ���ĳ�ʼ������
	virtual void StartGame(); //��ʼ��Ϸ
	virtual void OnGameStop();  //����Ϸ����ʱ�������ƺ���
	void SetHeroNum(EHeroNum eHeroNum);
	EHeroNum GetHeroNum();

private:
	static TankGame* s_pTankGame;
	EHeroNum m_heroNum; //˫��ģʽ���ǵ���ģʽ

};

