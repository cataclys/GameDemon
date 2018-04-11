#pragma once

#include "Spirit.h"
#include "MainScence.h"
#include "Common.h"
#include "Tank.h"
#include "Weapon.h"

class FixWall :
	public Spirit
{
private:
	typedef struct  
	{
		int nX;
		int nY;
		ScenceActor actor;
	}FixNode;
public:
	FixWall();
	~FixWall();

	virtual void InitSpirit(Scence *pScence);
	virtual void BeforEnterScence();

	void TankStep(Tank::TankData &preTank, Tank::TankData &nowTank);  //̹��̤�����ϰ���Ĵ��� 
	void TankDead(Tank::TankData &tankData); //̹��������
	void WaterBeShot(Weapon::Bullet &bullet); //ˮ������
	void GrassBeShot(Weapon::Bullet &bullet); //�ݱ�����
	void SoilBeShot(Weapon::Bullet &bullet);  //��ǽ����
	int GetComplex(); //��ȡ���Ӷ�
	//����չʾ����
	void ShowBorder();  //���߿�
	void ShowWater();   //��ˮ
	void ShowGrass();    //���ݵ�
	void ShowSoil();      //����ǽ
	void ShowIron();     //������

	//�жϸ����ĵ���ʲô���͵Ĺ̶��ϰ���(��Ҫʲôʵ��ʲô)
	bool IsWater(GamePos &gamePos);
	bool IsGrass(GamePos &gamePos);
	bool SetWater(GamePos &gamePos);
	bool SetGrass(GamePos &gamePos);



private:
	void ShowFixNode(FixNode &fixNode);
	void ShowFixWall(std::vector<FixNode> vecWall);
	void GetCoveringPos(std::vector<FixNode> &beCheckedPos, std::vector<GamePos> &checkGivePos, std::vector<GamePos> &getPos); //��ȡ���ǵ��б�
	bool IsCoveringPos(std::vector<FixNode> &beCheckedPos, GamePos &gamePos); //�����ĵ��Ƿ񸲸�
	void ChangePosAttr(std::vector<FixNode> &beChangedPos, unsigned int uID, int nX, int nY, EWallType eWallType, char *pszPic, int nColor); //�޸�ǽ��ͼƬ����ɫ
	void ChangeCoveringPosAttr(std::vector<FixNode> &fixPos, Tank::TankData &tankData, unsigned int uID, EWallType eWallType, char *pszPic, int nColor); //�޸��غϵ�����
	void DeleteFixNode(std::vector<FixNode> &fixPos, int nX, int nY);



private:
	std::vector<FixNode> m_vecBorder;  //�߽�
	std::vector<FixNode> m_vecWater;   //ˮ
	std::vector<FixNode> m_vecGrass;    //�ݵ�
	std::vector<FixNode> m_vecSoil;      //��ǽ
	std::vector<FixNode> m_vecIron;     //����
	int m_nComplex;  //���Ӷ�
};

