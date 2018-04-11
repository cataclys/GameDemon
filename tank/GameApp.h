#pragma once
#pragma  once
#include <string>
#include "Director.h"
#include "Scence.h"

class GameApp
{
public:
	GameApp();
	~GameApp(){};

public:
	virtual void DoBeforGameStart() = 0; //��Ϸ��ʼ֮ǰ���ĳ�ʼ������
	virtual void StartGame() = 0; //��ʼ��Ϸ

	virtual void OnGameStop() = 0;  //������Ϸʱ�������ƺ���

	std::string GetGameExeDir();  //��ȡexeִ�е�Ŀ¼

	void StopGame(); //���ú������Ϸ����StartGame�����н��
	void GameLoop(Director *pDirector);
	void GamePause(); //��ͣ��Ϸ
	void GameResume(); //��Ϸ����ִ��


private:
	std::string m_strGameDir; //��Ϸexe���ڵ�Ŀ¼
	bool m_bPause;
	Director *m_pDirector;
};

