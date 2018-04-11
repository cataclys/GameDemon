#include "Map.h"
#include "ColorDefine.h"

char* g_WallPic[] =
{
	"  ",   // =>E_EMPTY
	"��",   // =>E_BORDER
	"��",   // =>E_TANK
	"��",  // =>E_WATER
	"��",  // =>E_GRASS
	"��",   // =>E_SOIL
	"��",   // =>E_IRON
	"��"    // =>E_WEAPON
};

RandomTank g_randomTank[] = 
{
	{F_WHITE, 1, "��", 5},   // => E_TANK_TYPE1  
	{F_H_BLUE, 2, "��", 5},  // => E_TANK_TYPE2 
	{F_GREEN, 3, "��", 4},   // => E_TANK_TYPE3
	{ F_H_PURPLE, 4, "��", 4},  // => E_TANK_TYPE4
	{ F_H_YELLOW, 5, "��", 3},  // => E_TANK_TYPE5
};