#pragma once
#include "Scence.h"
class MissionCompleteScence :
	public Scence
{
public:
	MissionCompleteScence();
	~MissionCompleteScence();

	virtual void InitScence();
	virtual void DestoryScence();
	virtual void BeforEnterScence();

	//���ռ��̻ص�
	virtual void RcvKeyBoardNotify(char chKey);
};

