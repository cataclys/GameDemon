#pragma once
#include "Spirit.h"
#include "MainScence.h"
#include "Common.h"
#include "Map.h"
#include <vector>

class Tank;

class Weapon :
	public Spirit
{
private:
	static const int c_nWeaponSpeed = 2;
public:
	typedef struct
	{
		unsigned int uID;
		int nX;
		int nY;
		EDir eEir;
		EWallType eWalltype;
		EFightCamp eCamp;
		char szPic[PIC_LEN];
		int nColor;
		EHeroNum eHero;
	}Bullet;

public:
	Weapon();
	~Weapon();

	virtual void InitSpirit(Scence *pScence);
	virtual void Display();
	void DoBulletDisplay();
	void HeroFire(int nX, int nY, EDir eDir, int nColor, EHeroNum eNum); 	//���ǿ�����
	void EnemyFire(int nX, int  nY, char *szPic, EDir eDir, int nColor); //���˿�����
private:
	void MoveBullet(int nIndex, Bullet &bullet);  //�ƶ��ӵ�
	void ShowBullet(Bullet &bullet);  //�ڳ�������ʾ�ӵ�
	void EraseBullet(Bullet &bullet);  //�ڳ�����ɾ���ӵ�
	void ChangeByDir(Bullet &bullet); //���ݷ�����б䶯
	void Dofire(std::vector<Bullet> vecBullets, EFightCamp eCamp, int nX, int  nY, char *szPic, EDir eDir, int nColor, EHeroNum eNum);  //ר�ÿ�����
	bool IsNeedDelete(int nIndex); //�ж��ӵ��Ƿ���Ҫ��ɾ��

private:
	std::vector<Bullet> m_vecBullets;
	std::vector<int> m_vecNeedDelete;
	__int64 m_u64Tickets;
	__int64 m_u64NextTickets;
};

