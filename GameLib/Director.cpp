#include "Director.h"


Director* Director::s_pDirector = nullptr;

Director::Director()
{
	m_bScencePase = false;
}

Director* Director::GetInstance()
{
	if (!s_pDirector)
	{
		s_pDirector = new Director();
	}
	return s_pDirector;
}

void Director::Destory()
{
	if (!s_pDirector)
	{
		delete s_pDirector;
		s_pDirector = nullptr;
	}
}


void Director::FistRunScence(Scence* pScence)
{
	//�����ϸ�scence
	m_pNextScence = pScence;
	//����Ϊ��ǰscence
	m_pCurrentScence = pScence;
	//��ʼ������
	m_pCurrentScence->InitScence();
	//���������Դ����������ʾ�м�ĺ�������
	m_pCurrentScence->BeforEnterScence();
	//�Ͷ�ʱ�����
	m_pCurrentScence->AttachRunScence();
}

void Director::DirectorCallBack()
{
	if (s_pDirector->m_pCurrentScence != s_pDirector->m_pNextScence)  //���ֵ�ǰִ�еĳ������´β�һ�����������һ��ִ�е�ǰ����Ҳ���³�����һ��ִ�У��������ݣ�
	{
		//�Ѿɵĳ����Ͷ�ʱ������
		s_pDirector->m_pCurrentScence->DetachRunScence();
		//���õ�ǰ�����Ѿ�����
		s_pDirector->m_pCurrentScence->SetIsEnd(true);
		//�ɵĳ�������destory
		s_pDirector->m_pCurrentScence->DestoryScence();
		delete s_pDirector->m_pCurrentScence;
		s_pDirector->m_pCurrentScence = nullptr;
		//�ѵ�ǰ�ĳ�������Ϊ�´ε�
		s_pDirector->m_pCurrentScence = s_pDirector->m_pNextScence;

		//�µĳ����Ͷ�ʱ���ȷ���
		s_pDirector->m_pCurrentScence->DetachRunScence();
		//�µĳ�����ʼ��
		s_pDirector->m_pCurrentScence->InitScence();
		//���õ�ǰ�����Ѿ�����Ϊfalse
		s_pDirector->m_pCurrentScence->SetIsEnd(false);
		//���������Դ����������ʾ�м�ĺ�������
		s_pDirector->m_pCurrentScence->BeforEnterScence();
		//�Ͷ�ʱ�����
		s_pDirector->m_pCurrentScence->AttachRunScence();
	}
	else
	{
		if (!(s_pDirector->m_bScencePase))
		{
			s_pDirector->m_pCurrentScence->RunScence();
		}
	}
}


Scence* Director::GetRuningScence()
{
	return m_pCurrentScence;
}

void Director::ChangeScence(Scence* pScence)
{
	//���ú��´μ��صĳ���
	m_pNextScence = pScence;
}

void Director::ScencePasue()
{
	m_bScencePase = true;
}

void Director::ScenceResume()
{
	m_bScencePase = false;
}
