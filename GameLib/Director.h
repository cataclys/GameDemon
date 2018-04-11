#pragma  once
#include "Scence.h"


class  Director
{
private:
	Director();

public:
	const static int  c_nDefaultCallBackIntervalTickets = 20;  //Ĭ�ϵ������ص�Ms
public:
	static Director* GetInstance();
	static void Destory();
	virtual void FistRunScence(Scence* pScence);
	virtual void ChangeScence(Scence* pScence);
	void ScencePasue();
	void ScenceResume();

	Scence* GetRuningScence();  //��ȡ��ǰ���ڽ��е�scence
	static void DirectorCallBack();

private:
	Scence* m_pCurrentScence;
	Scence* m_pNextScence;
	bool m_bScencePase;
	//
	static Director* s_pDirector;
};
