#pragma once
#include "Spirit.h"
#include <vector>
#include <map>
#include <string>



class Scence :  public IKeyboardNotify
{
public:
	Scence(){ m_isRunscenceDetach = true; } //Ĭ�϶�ʱ���ͳ����Ƿ����
	~Scence(){}
	virtual void InitScence();    //���������ݳ�ʼ����ע��ɵĳ�����δ�л���������
	virtual void DestoryScence();
	virtual void BeforEnterScence();  //�ڽ��뵱ǰ����֮ǰ���ɵĳ�����δ�л�ע�⣡�������жκ���������ص���������������ģ�����
	virtual void  RunScence();  //�Ѿ����뵱ǰ�ĳ�����,��ʱ�ص�RunScence
	virtual void  ShowScence(); //��UI��չʾ����
	void  DetachRunScence(); //�Ѿ����뵱ǰ�ĳ�����,��Ҫ��ʱ�ص�RunScence
	void AttachRunScence(); //�Ѿ����뵱ǰ�ĳ�����, ��ʱ�ص�RunScence
	void AddSpirit(Spirit* pSpirit);
	void DeleteSpirit(Spirit* pSpirit);
	//scence �ṩ���ַ���
	void MapSpirit(std::string strSpiritName, Spirit *pSpirit);
	void UnMapSpirit(std::string strSpiritName);
	Spirit* FindMap(std::string strSpiritName);

	virtual void BeforSpiritDisplay(); //����Ա����֮ǰ
	virtual void AfterSpiritDisplay(); //����Ա����֮��

	//���̵�ע�ᡢ��ע��ͽ���
	virtual void RcvKeyBoardNotify(char chKey);
	void RegKeyBoardNotify();
	void UnRegKeyBoardNotify();

	//���õ�ǰ����״̬
	void SetIsEnd(bool bFlag);



private:
	std::vector<Spirit*> m_arrySpirit;
	bool m_isRunscenceDetach;  //�Ƿ�Ͷ�ʱ�ص�����
	bool m_bIsEnd; //��ǰ�����Ƿ��Ѿ�����
	std::map<std::string, Spirit*> m_spiritNameMap; //���������ַ���
};

