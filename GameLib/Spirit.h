#pragma once
#include "IKeyboardNotify.h"
#include "LibCommon.h"
class Scence;

class Spirit :public IKeyboardNotify
{
public:
	Spirit();
	~Spirit();
	virtual void InitSpirit(Scence *pScence);    //���������ݳ�ʼ�����ڸմ�����ʱ����
	virtual void BeforEnterScence();  //�ڽ���������֮ǰ,��׼changescence
	virtual void BeforDestorySpirit();  //�������ڴ�֮ǰ�������飬��׼changescence
	virtual void Display();

	//�������
	virtual void RcvKeyBoardNotify(char chKey);
	void RegKeyBoardNotify();
	void UnRegKeyBoardNotify();
protected:
	Scence *m_pScence;
};

