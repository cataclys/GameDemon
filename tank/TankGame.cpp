#include "TankGame.h"
#include "Director.h"
#include "TimeWheel.h"
#include "ConsoleUIBuff.h"
#include "Common.h"
#include "LogoScence.h"
#include <time.h>
#include <windows.h>
#pragma  comment(lib, "winmm.lib")


TankGame * TankGame::s_pTankGame = nullptr;

TankGame::TankGame()
{
	m_heroNum = E_LEFT_HERO;
}

TankGame* TankGame::GetGameInstance()
{
	if (nullptr == s_pTankGame)
	{
		s_pTankGame = new TankGame;
	}
	return s_pTankGame;
}

void TankGame::DestoryGameInstance()
{
	if (nullptr != s_pTankGame)
	{
		delete s_pTankGame;
		s_pTankGame = nullptr;
	}
}

void TankGame::DoBeforGameStart()
{
	//���������
	srand((unsigned int)time(0));

	//��ʼ��UI������(û�м��ɵ�GameApp������ΪUI������������ǿ���̨���Ժ������windows�����)
	ConsoleUIBuff *pUIBuff =  ConsoleUIBuff::GetInstance();
	pUIBuff->SetWindowBuff(GAME_NAME, WINDOWS_WIDTH, WINDOWS_HEIGHT, ConsoleUIBuff::c_nDefaultDrawIntervaltickets);
	//��UIbuff��ʱ����ע��
	TimeWheel::RegRunFunc(ConsoleUIBuff::UIDrawCallBack, ConsoleUIBuff::c_nDefaultCallBackIntervaltickets);
	//��������

	std::string strFullPath = TankGame::GetGameInstance()->GetGameExeDir() + "sound/MainSound.wav";
	//��������
	PlaySoundA(strFullPath.c_str(), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
}

void TankGame::StartGame()
{
	//��ȡ������
	Director *pDirector = Director::GetInstance();
	//��һ������
	LogoScence *pLogoScence = new LogoScence();
	//������������̨��ʼ
	pDirector->FistRunScence(pLogoScence);
	//��ʼ��Ϸѭ��
	GameApp::GameLoop(pDirector);
}

void TankGame::OnGameStop()
{
	//����Ϸ����ʱ������UI������
	ConsoleUIBuff::Destory();
	//�����������ռ�õ���Դ
	Director::Destory();
}

void TankGame::SetHeroNum(EHeroNum eHeroNum)
{
	m_heroNum = eHeroNum;
}

EHeroNum TankGame::GetHeroNum()
{
	return m_heroNum;
}

