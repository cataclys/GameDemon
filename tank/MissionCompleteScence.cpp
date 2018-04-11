#include "MissionCompleteScence.h"
#include "ConsoleUIBuff.h"
#include "TankGame.h"
#include "KeyboardValue.h"
#include "MainScence.h"
#include "ColorDefine.h"
#include "SelectMapScence.h"
#include <iostream>
#include <fstream>


MissionCompleteScence::MissionCompleteScence(){}
MissionCompleteScence::~MissionCompleteScence(){}


void MissionCompleteScence::InitScence()
{
	//�����ע��֪ͨ
	RegKeyBoardNotify();
}


void MissionCompleteScence::DestoryScence()
{
	ConsoleUIBuff::GetInstance()->CleanBuff();
	//�ü��̲���֪ͨ
	UnRegKeyBoardNotify();
	//���ø���ͨ��������
	__super::DestoryScence();
}

void MissionCompleteScence::BeforEnterScence()
{
  	std::string strLogoFile = TankGame::GetGameInstance()->GetGameExeDir() + "scence/mission_complete.txt";
	std::ifstream readFile(strLogoFile.c_str(), std::ios::in);
	if (readFile.is_open())
	{
		int nBaseY = 4;
		int nBaseX = 2;
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

void MissionCompleteScence::RcvKeyBoardNotify(char chKey)
{
	if (chKey == (char)E_KEY_ENTER)
	{
		SelectMapScence::s_strMapName = "AStarTest.map";
		//��ȡ������
		Director *pDirector = Director::GetInstance();
		//������Ϸ�˵�
		MainScence *pMainScence = new MainScence();
		pDirector->ChangeScence(pMainScence);
	}
}


