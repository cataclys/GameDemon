#pragma once
#include <vector>

#include "IKeyboardNotify.h"

class Keyboard
{
private:
	Keyboard()
	{
		memset(pNotifyArry, 0, sizeof(pNotifyArry));
	}
public:
	const static int  c_nDefaultCallBackIntervalTickets = 20;  //Ĭ�ϵ������ص�Ms
public:
	static Keyboard* GetInstance();
	static void Destory();
	static void KeyboardCallBack();

	void RegKeyboardMonitor(IKeyboardNotify* pNotify);
	void UnRegKeyboardMonitor(IKeyboardNotify* pNotify);
	void DispatchEnterKey(char chKey);

private:
	static Keyboard* s_pKeyboard;
	const static int c_nMaxNotifyNum = 1024;  
	IKeyboardNotify* pNotifyArry[c_nMaxNotifyNum];  //���֧��1024�����飬���Ի���̬����ʵ��
};

