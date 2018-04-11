#pragma once
#include "Spirit.h"
#include "MainScence.h"
#include "Tank.h"
#include "Weapon.h"

class Hero :
	public Spirit
{
public:
	//Ĭ�ϵ������������
	const static int c_nDefaultLeftX = 15;
	const static int c_nDefaultLeftY = GAME_AREA_HEIGHT - 3;
	const static int c_nDefaultRightX = GAME_AREA_WIDTH - 15;
	const static int c_nDefaultRightY = GAME_AREA_HEIGHT - 3;
	//���ǵ�Ĭ��Ѫֵ
	const static int c_nDefaultHp = 100;
	//�������
	typedef struct 
	{
		Tank *pTank;
		int nScore;
	}HeroData;

public:
	Hero();
	~Hero();

	virtual void InitSpirit(Scence *pScence);
	virtual void BeforDestorySpirit();
	virtual void BeforEnterScence();
	virtual void RcvKeyBoardNotify(char chKey);
	void SetGameMod(EHeroNum eMod);

	bool BeShot(Weapon::Bullet & bullet); //����
	void TankDead(Tank *pTank); //̹������
	void AddScore(EHeroNum eHero, Tank::TankData &tankData); //�ӷ�
	void AddScore(HeroData &heroData, Tank::TankData &tankData);//�ӷ�
	void GetHeroLeftData(HeroData &leftHero, HeroData &rightHero);  //��ȡ������Ϣ

private:
	void Fire(HeroData &heroData, EHeroNum eHero); //����
	void MoveUp(HeroData &heroData);
	void MoveDown(HeroData &heroData);
	void MoveLeft(HeroData &heroData);
	void MoveRight(HeroData &heroData);
	void ShowScore();
	void MissionComplete(); //ͨ��
private:
	HeroData m_leftHero;  //��һ�����
	HeroData m_rightHero;  //�ڶ������
	EHeroNum m_eMod; //��Ϸģʽ
};

