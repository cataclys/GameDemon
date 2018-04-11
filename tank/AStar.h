#pragma once
#include "LibCommon.h"
#include <vector>
#include <set>
#include "IAStartCheck.h"
#include "Common.h"

class AStar
{
private:
	const static int c_nMaxAstarStep = 10000; //��ಽ��
	const static int c_nHeightArea = 3;
	const static int c_nWidthArea = 3;
	typedef struct AStartPos
	{
		bool operator==(const AStartPos& astarPos)
		{
			return astarPos.m_gamePos.nX == m_gamePos.nX && astarPos.m_gamePos.nY == m_gamePos.nY;
		}
		void operator=(const AStartPos& astarPos)
		{
			m_gamePos.nX = astarPos.m_gamePos.nX;
			m_gamePos.nY = astarPos.m_gamePos.nY;
		}
		GamePos m_gamePos;
	};
	//
	typedef struct AstartNode
	{
		AstartNode() :g(0), h(0), f(0){}
		int g; //�ƶ���ģ�ÿһ��һ���ͼ�1��
		int h; //���յ����̾���
		int f; //g + h
		void SetH_F(const AStartPos& startPos, const AStartPos& targetPos)
		{
			h = abs(startPos.m_gamePos.nX - targetPos.m_gamePos.nX) + abs(startPos.m_gamePos.nY - targetPos.m_gamePos.nY);
			f = g + h;
		}
		bool operator < (const AstartNode &a) const // ���ء�<�����������Զ����������  
		{
			return (curPos.m_gamePos.nX + curPos.m_gamePos.nY * GAME_AREA_WIDTH) < (a.curPos.m_gamePos.nX + a.curPos.m_gamePos.nY * GAME_AREA_WIDTH);
		}
		//
		AStartPos curPos;
		int nParentIndex; //���ڵ���close���ϵ�����
	};

private:
	AStar(); //���ɵ���ģʽ������Ƶ���Ĵ������µ�����
	~AStar();
public:
	static AStar* GetInstance(unsigned int uTargetID, GamePos &startPos, GamePos &targetPos, IAstartCheck *pCheckObj);
	static void DestoryInstance();
	bool FindPath();
	void GetPath(std::vector<GamePos> &vecPath);

private:
	void Init(unsigned int uTargetID, GamePos &startPos, GamePos &targetPos, IAstartCheck *pCheckObj);
	bool IsBoday(int nX, int nY);

private:
	AStartPos m_startPos;
	AStartPos m_targetPos;
	std::vector<AstartNode> m_vecOpen;  //�洢����ɢ�ĵ㣨����������
	std::vector<AstartNode> m_vecClose; //�洢��ɢ���ĵ�(��������)
	std::vector<GamePos> m_Path; //���·������
	IAstartCheck *m_pCheckObj;
	std::set<AstartNode> m_setOpen; //(��������)
	std::set<AstartNode> m_setClose; //(��������)
	int m_uTargetID;
	//
	static AStar* s_pAStart;



};

