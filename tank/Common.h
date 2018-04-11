#pragma  once
#include "LibCommon.h"
#include <vector>

#define  WINDOWS_WIDTH	75  //����Ŀ�
#define  WINDOWS_HEIGHT	 51 //����ĸ�

#define  GAME_AREA_HEIGHT  51 //��Ϸ����ĸ߶�
#define  GAME_AREA_WIDTH   61//��Ϸ����Ŀ��
#define  GAME_NAME "̹�˴�ս"

typedef enum
{
	E_DIR_UP,
	E_DIR_DOWN,
	E_DIR_LEFT,
	E_DIR_RIGHT,
	E_DIR_MAX
}EDir;   //����

//ս��˫��
typedef enum
{
	E_HERO_CAMP,  //�ѷ�
	E_ENEMY_CAMP, //�з�
	E_CAMP_MAX     //������
}EFightCamp;


//��Ϸģʽ
typedef enum
{
	E_LEFT_HERO, 
	E_RIGHT_HERO,  //˫��ģʽ
	E_HERO_MOD_MAX
}EHeroNum;

