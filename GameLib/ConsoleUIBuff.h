#pragma once

class ConsoleUIBuff

{
private:
	ConsoleUIBuff(){}
public:
	const static int  c_nDefaultDrawIntervaltickets = 20;  //Ĭ�϶���ticket����һ�λ���
	const static int  c_nDefaultCallBackIntervaltickets = 1; //��ʱ�ص��೤ʱ�����һ��

public:
	static ConsoleUIBuff* GetInstance();
	static void Destory();
	bool SetWindowBuff(const char* pszTitle, int nWidth, int nHeight, int nDrawIntervaltickets);
	void SetDrawIntervalTickets(int nDrawIntervaltickets);
	void DrawImme(int nX, int nY, char* pszText, unsigned short usColor);  //ֱ�ӻ���Ч�ʱȽϵ�
	void DrawDelay(int nX, int nY, char *pszText, unsigned short usColor);  //��ʱ�����������ػ�䶯�Ĳ���
	void CleanBuff(); //��ջ�����
	void CleanBuff(int nX, int nY, int nLen);
private:
	void SetWindowsBaseInfo(const char* pszTitle, int nWidth, int nHeight);
	void DoDrawDelay();
	void WriteChar(int nX, int nY, const char* pszBuff, unsigned short usColor);

public:
	static void UIDrawCallBack();
	static void SetCursorUnVisable();

private:
	typedef struct
	{
		unsigned short usColor;
		char *pszBuff;
	}UIBuffData, *PUIBuffData;
private:
	PUIBuffData m_pUIBuff;
	PUIBuffData m_pOldUIBuff;
	char *pszUIBuffBegin;
	char *pszOldUIBuffBegin;
	int m_nPerBuffLen; //���ͨ����̬�������
	int m_nWidth;
	int m_nHeight;
	int  m_nDrawIntervalTickets;
	unsigned __int64 m_u64NextDrawTicket;
	unsigned __int64 m_u64Tickets;
	static ConsoleUIBuff *s_pConsoleUIBuff;
};