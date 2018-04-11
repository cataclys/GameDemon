#include "AStar.h"
#include "ConsoleUIBuff.h"
#include "ColorDefine.h"

AStar* AStar::s_pAStart = nullptr;
AStar::AStar(){}
AStar::~AStar(){}

bool AStar::FindPath()
{
	//�������ͬ�㲻��Ѱ·
	if (m_startPos.m_gamePos.nX== m_targetPos.m_gamePos.nX && m_startPos.m_gamePos.nY == m_targetPos.m_gamePos.nY)
	{
		return false;
	}
	//����ʼ����
	AstartNode nodeInfo;
	nodeInfo.curPos = m_startPos;
	nodeInfo.g = 0;
	nodeInfo.SetH_F(m_startPos, m_targetPos);
	//�������ӵ�open��
	m_vecOpen.push_back(nodeInfo);
	//
	m_setOpen.insert(nodeInfo);
	//ConsoleUIBuff::GetInstance()->DrawImme(nodeInfo.curPos.m_gamePos.nX, nodeInfo.curPos.m_gamePos.nY, "��", F_GREEN);
	int nCount = 0;
	//��ʼѰ·
	while (true)
	{
		++nCount;
		//���open����û�д����ĵ�˵��û�ҵ�
		if (m_vecOpen.empty())
		{
			return false;
		}
		if (nCount >= c_nMaxAstarStep)
		{
			return false;
		}
		//��open�����ҵ�fֵ��С��
		int nIndex = 0;
		for (size_t i = 1; i < m_vecOpen.size(); i++)
		{
			if (m_vecOpen[nIndex].f > m_vecOpen[i].f)
			{
				nIndex = i;
			}
		}
		//
		AstartNode newNode[4];
		//��
		newNode[0].curPos.m_gamePos.nX = m_vecOpen[nIndex].curPos.m_gamePos.nX;
		newNode[0].curPos.m_gamePos.nY = m_vecOpen[nIndex].curPos.m_gamePos.nY - 1;
		//��
		newNode[1].curPos.m_gamePos.nX = m_vecOpen[nIndex].curPos.m_gamePos.nX;
		newNode[1].curPos.m_gamePos.nY = m_vecOpen[nIndex].curPos.m_gamePos.nY + 1;
		//��
		newNode[2].curPos.m_gamePos.nX = m_vecOpen[nIndex].curPos.m_gamePos.nX - 1;
		newNode[2].curPos.m_gamePos.nY = m_vecOpen[nIndex].curPos.m_gamePos.nY;
		//��
		newNode[3].curPos.m_gamePos.nX = m_vecOpen[nIndex].curPos.m_gamePos.nX + 1;
		newNode[3].curPos.m_gamePos.nY = m_vecOpen[nIndex].curPos.m_gamePos.nY;

		//�ѷ�Դ��ŵ�close����
		AstartNode beginNode = m_vecOpen[nIndex];
		m_vecClose.push_back(beginNode);
		//ConsoleUIBuff::GetInstance()->DrawImme(beginNode.curPos.m_gamePos.nX, beginNode.curPos.m_gamePos.nY, "��", F_RED);
		//
		m_setClose.insert(beginNode);
		//���������Ը�ֵ
		for (int i = 0; i < 4; i++)
		{
			newNode[i].nParentIndex = (int)m_vecClose.size() -1;   //���ø�������close���ϵ�����
			newNode[i].g = m_vecOpen[nIndex].g + 1;                              //�ƶ�һ����1
			newNode[i].SetH_F(newNode[i].curPos, m_targetPos); //����h��f��ֵ
		}

		//�ѷ�Դ���open����ɾ��
		m_vecOpen.erase(m_vecOpen.begin() + nIndex);
		//
		m_setOpen.erase(beginNode);

		//�����ɢ���ĵ��Ƿ�ϸ�
		for (int i = 0; i < 4; i++)
		{
			//������յ㣬��ӵ�close���к�������
			if (newNode[i].curPos == m_targetPos)
			{
				m_vecClose.push_back(newNode[i]);
				return true;
			}

			//����ļ��
			bool bSpiritCheck = m_pCheckObj->AStartCheck(m_uTargetID, m_vecClose[newNode[i].nParentIndex].curPos.m_gamePos, newNode[i].curPos.m_gamePos);
			if (!bSpiritCheck)
			{
				continue;
			}

			//�����open������close���в�Ҫ
			if (m_setOpen.end() != m_setOpen.find(newNode[i]))
				goto End;

			if (m_setClose.end() != m_setClose.find(newNode[i]))
				goto End;

			//���û�б���ת��ӵ�open����
			//ConsoleUIBuff::GetInstance()->DrawImme(newNode[i].curPos.m_gamePos.nX, newNode[i].curPos.m_gamePos.nY, "��", F_GREEN);
			m_vecOpen.push_back(newNode[i]);
			m_setOpen.insert(newNode[i]);
		End:;
		}
	}
	return false;
}

void AStar::GetPath(std::vector<GamePos> &vecPath)
{
	//ȡ������Ϊ��ǰ�ڵ�
	int nCurrentIndex = m_vecClose.size() - 1;
	//�ѵ�ǰ����뼯��
	m_Path.push_back(m_vecClose[nCurrentIndex].curPos.m_gamePos);
	//��ǰ��ĸ��ڵ�
	int nParentIndex = m_vecClose[nCurrentIndex].nParentIndex;
	int nCount = 0;
	while (true)
	{
		++nCount;
		//�����ǰ�ڵ�ĸ��ڵ�Ϊ��ʼ�㣬����·���У�ֱ���˳�
		if (m_vecClose[nParentIndex].curPos == m_startPos || nCount >= c_nMaxAstarStep)
		{
			m_Path.push_back(m_startPos.m_gamePos);
			break;
		}
		else
		{
			//���ڵ���Ϊ�µĵ�ǰ�ڵ�
			nCurrentIndex = nParentIndex;
			int nX = m_vecClose[nCurrentIndex].curPos.m_gamePos.nX;
			int nY = m_vecClose[nCurrentIndex].curPos.m_gamePos.nY;
			m_Path.push_back(m_vecClose[nCurrentIndex].curPos.m_gamePos);
			//�ټ������ǰ�ڵ�ĸ��׽ڵ�
			nParentIndex = m_vecClose[nCurrentIndex].nParentIndex;
		}
	}
	//
	for (int i = m_Path.size() - 1; i >= 0; i--)
	{
		vecPath.push_back(m_Path[i]);
	}
}

void AStar::Init(unsigned int uTargetID, GamePos &startPos, GamePos &targetPos, IAstartCheck *pCheckObj)
{
	//������������ݽṹ
	m_setClose.clear();
	m_setOpen.clear();
	m_vecClose.clear();
	m_vecOpen.clear();
	m_Path.clear();
	m_uTargetID = 0;
	//��ʼ��
	AStartPos astartStart;
	astartStart.m_gamePos = startPos;
	AStartPos astartTarge;
	astartTarge.m_gamePos = targetPos;
	//
	m_startPos = astartStart;
	m_targetPos = astartTarge;
	m_pCheckObj = pCheckObj;
	//
	m_uTargetID = uTargetID;
}

AStar* AStar::GetInstance(unsigned int uTargetID, GamePos &startPos, GamePos &targetPos, IAstartCheck *pCheckObj)
{
	if (nullptr == s_pAStart)
	{
		s_pAStart = new AStar();
	}
	s_pAStart->Init(uTargetID, startPos, targetPos, pCheckObj);
	return s_pAStart;
}

void AStar::DestoryInstance()
{
	if (s_pAStart)
	{
		delete s_pAStart;
		s_pAStart = nullptr;
	}
}


