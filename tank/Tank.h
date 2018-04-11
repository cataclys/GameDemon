#pragma  once
#include "Common.h"
#include "Map.h"
#include "MainScence.h"
#include <vector>
#include "IAStartCheck.h"


class Tank :public IAstartCheck
{
public:
	typedef struct
	{
		unsigned int  uID; //ΨһID
		int nCenterX; //����x����
		int nCenterY; //����y����
		EWallType eWalltype; //��������
		EDir eDir; //̹�˵ķ���
		char szPic[PIC_LEN]; //ͼƬ����
		int nColor; //��ɫ
		EFightCamp eCamp; //��Ӫ
		int nHP; //Ѫֵ
		int nSpeed;//�ٶ�
		WalkPath walkPath;
		int nAstarNiceValue;

	}TankData;
	const static int c_nTankHeight = 3; //̹�˵ĸ߶� 
	const static int c_nTankWidth = 3;  //̹�˵Ŀ��
	const static int c_nTankNiceValue = 1000; //Ĭ�ϵ�niceֵ
	const static int c_nArryTankShape[E_DIR_MAX][c_nTankHeight][c_nTankWidth];
public:
	Tank(MainScence *pScence, int nCenterX, int nCenterY, EWallType eWallType, EDir eDir, const char *pszPic, int nColor, EFightCamp eCamp, int nHp, int nSpeed);
	~Tank();
	virtual bool AStartCheck(unsigned int uTargetID, GamePos &preGamePos, GamePos &nowGamePos); //A*Ѱ·��⵱ǰ��
	void ReduceAstarNiceValue(); //��ΪA*ʧ�ܼ���niceֵ
	void ResetAstarFailTimes();//����A*Ѱ·ʧ�ܴ���
	void SetAstarPath(std::vector<GamePos> &vecPath);
	void MoveDir(EDir eDir); //��ָ�������ƶ�
	void ShowTank();//�ڳ�����չʾ�Լ�
	void EraseTank();//�ڳ�����ɾ���Լ�
	bool BeShot(GamePos &gamePos, EFightCamp eBulletCamp, EHeroNum eFromHero);  //����
	TankData GetTankData(); //��ȡ̹������
	static void BodayPos2RealPos(TankData &tankData, std::vector<GamePos> &vecPos); //��ȡ̹����������������Ӧ��ʵ������
	static void BodayPos2RealPos(GamePos &centerPos, EDir eDir, std::vector<GamePos> &vecPos); //��ȡ̹����������������Ӧ��ʵ������
	static inline void BodayPos2RealPos(GamePos &centerPos, GamePos bodayPos, GamePos &realPos); //��������תʵ������
	void Fire(EHeroNum eHeroNum);   //����
	void Action();  //��Ϊ
	void Walk(); //����



private:
	bool IsTankCanStep(TankData &tankData);//�жϵ�ǰ̹���Ƿ�Ῠ��ǽ����
	bool IsTankCanStep(TankData &tankData, unsigned int uIgnoreID); //����ĳ��ID
	void UpdateTankDataByDir(TankData &tankData);
	bool IsBeShot(GamePos &gamePos, EFightCamp eBulletCamp); //�ж��Ƿ񱻴���
	void  RunPath(); //����·������
	void RunPathJustChangeDir(EDir edir);  //������Ҫת��
	void RunPathImee(); //ֱ����
	void  RandomMove(); //����ƶ�
	void  RandomFire(); //�������
	EDir GetDirByPosOffset(int nTargetX, int nTargetY, int nSrcX, int nSrcY);

private:
	TankData m_tankData;
	MainScence *m_pMainScence;
	//
	unsigned __int64 m_u64Tickets;
	unsigned __int64 m_u64NextTicket;
};


