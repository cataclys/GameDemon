#pragma once
#include "Scence.h"
class GameOverScence :
	public Scence
{
public:
	GameOverScence();
	~GameOverScence();

	virtual void InitScence();
	virtual void DestoryScence();
	virtual void BeforEnterScence();

	//���ռ��̻ص�
	virtual void RcvKeyBoardNotify(char chKey);
};

