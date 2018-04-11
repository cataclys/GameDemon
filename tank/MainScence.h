#pragma once
#include "Scence.h"
#include "Map.h"
#include "Common.h"


class MainScence :
	public Scence
{
public:
	MainScence();
	~MainScence();

	virtual void InitScence();
	virtual void BeforEnterScence();
	virtual void DestoryScence();
	virtual void ShowScence();  //�ѵ�ǰ�����ڽ�����չʾ����
	virtual void RcvKeyBoardNotify(char chKey); 	//���ܼ��̻ص�
	void ChangePosAttr(unsigned int uID, EFightCamp eCamp, int nX, int nY, EWallType eWalltype, const char* szPic, int nColor); //�޸ĵ���Ϣ
	void ErasePos(int nX, int nY); //��յ���
	ScenceActor DirtyWallActor(int nX, int nY); //���ȡ
	static unsigned int GetActorID(EWallType eWallType); //����ǽ�����ͻ�ȡID
	void DirtyGetEmptyPos(std::vector<GamePos> &vecEmptyPos); //��ȡ���е�
	void GetTankCanUseEmptyPos(std::vector<GamePos> &vecCanUsePos);  //��ȡ���Է���̹�˵ĵ�
private:
	ScenceActor  m_scenceArryPos[GAME_AREA_HEIGHT][GAME_AREA_WIDTH];
	//������id
	static unsigned int s_nLastID;
};

