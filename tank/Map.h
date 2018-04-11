#pragma  once
#include "LibCommon.h"
#include "Common.h"
#include <vector>


typedef enum
{
	E_EMPTY, //�յ�
	E_BORDER,   //�߿�
	E_TANK, //̹��
	E_WATER, //ˮ
	E_GRASS, //�ݵ�
	E_SOIL, //��ǽ
	E_IRON,// ��
	E_WEAPON, //�ӵ�
	E_WALL_TYPE_MAX  //������Чֵ
}EWallType;

extern char* g_WallPic[];


//ͼƬ����
#define  PIC_LEN 5

//������Ԫ��Ϣ
typedef struct
{
	unsigned int uID;
	char szPic[PIC_LEN];
	int nColor;
	EWallType eWalltype;
	EFightCamp eCamp;
}ScenceActor;

//�̶�����ID
typedef enum
{
	E_ID_EMPTY,
	E_ID_SOIL,
	E_ID_WATER,
	E_ID_GRASS,
	E_ID_IRON,
	E_ID_BORDER,
	E_ID_OTHER,  //�������͵�ID�����￪ʼ
	E_ID_INVALID = 0xFFFFFFFF
}E_FIX_ACTOR_ID;


//���̹�˽ṹ
typedef enum
{
	E_TANK_TYPE1,
	E_TANK_TYPE2,
	E_TANK_TYPE3,
	E_TANK_TYPE4,
	E_TANK_TYPE5,
	E_TANK_MAX
}ERandomTanktype;
typedef struct  
{
	int nColor;
	int nHP;
	char szPic[PIC_LEN];
	int nSpeed;
}RandomTank;
extern RandomTank g_randomTank[];

//·��
#define  RUN_PATH_WAIT_TIMES 10  //���������������Ҫ�ȴ����
typedef struct
{
	int nStep;  //�ڼ�����
	int nWaitTimes; //�ڵ�ǰ��ȴ����Σ�������ڱ��̹�˻����ӵ������ˣ�
	std::vector<GamePos> vecWalkPath;
}WalkPath;