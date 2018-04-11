#include "GameOverScence.h"
#include "ConsoleUIBuff.h"
#include "KeyboardValue.h"
#include "Director.h"
#include "MenuScence.h"
#include "TankGame.h"
#include "ColorDefine.h"
#include "LogoScence.h"
#include "MainScence.h"
#include <iostream>
#include <fstream>


GameOverScence::GameOverScence(){}
GameOverScence::~GameOverScence(){}

void GameOverScence::InitScence()
{
	//�����ע��֪ͨ
	RegKeyBoardNotify();
}

void GameOverScence::DestoryScence()
{
	ConsoleUIBuff::GetInstance()->CleanBuff();
	//�ü��̲���֪ͨ
	UnRegKeyBoardNotify();
	//���ø���ͨ��������
	__super::DestoryScence();
}

void GameOverScence::BeforEnterScence()
{
	std::string strLogoFile = TankGame::GetGameInstance()->GetGameExeDir() + "scence/game_over.txt";
	std::ifstream readFile(strLogoFile.c_str(), std::ios::in);
	if (readFile.is_open())
	{
		int nBaseY = 4;
		int nBaseX = 8;
		while (!readFile.eof())  //�ж��Ƿ�ﵽstream�Ľ�β
		{
			char szReadIn[1024] = { 0 };
			readFile.getline(szReadIn, sizeof(szReadIn), '\n');
			ConsoleUIBuff::GetInstance()->DrawImme(nBaseX, nBaseY, szReadIn, F_H_YELLOW);
			++nBaseY;
		}
		readFile.close();
	}
}

void GameOverScence::RcvKeyBoardNotify(char chKey)
{
	if (chKey == (char)E_KEY_ESC)  //����enter��������Ϸ������
	{
		//��ȡ������
		Director *pDirector = Director::GetInstance();
		//������Ϸ�˵�
		MenuScence *pMenu = new MenuScence();
		pDirector->ChangeScence(pMenu);
	}
	else if (chKey == (char)E_KEY_ENTER)
	{
		//��ȡ������
		Director *pDirector = Director::GetInstance();
		//������Ϸ�˵�
		MainScence *pMainScence = new MainScence();
		pDirector->ChangeScence(pMainScence);
	}
}
