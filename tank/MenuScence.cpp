#include "MenuScence.h"
#include "ColorDefine.h"
#include "KeyboardValue.h"
#include "LogoScence.h"
#include "MainScence.h"
#include "ConsoleUIBuff.h"
#include "Director.h"
#include "TankGame.h"
#include "EditScence.h"
#include "LogoScence.h"
#include "SelectMapScence.h"


const char* MenuScence::c_pszExitMenu = "�˳��˵�";
const char* MenuScence::c_pszEditFixWall = "�༭��ͼ";
const char* MenuScence::c_pszStartGame = "��ʼ��Ϸ";
const char* MenuScence::c_pszArrow = "��";
const char* MenuScence::c_pszExitGame = "�˳���Ϸ";
const char* MenuScence::c_pszSelectMap = "ѡ���Լ��༭�ĵ�ͼ";

const char* MenuScence::c_pszEscTip = "��ESC������Logo����";
const char* MenuScence::c_pszEnterTip = "��Enter������Ϸ";


MenuScence::MenuScence(){}
MenuScence::~MenuScence(){}

void MenuScence::InitScence()
{
	m_eSelect = E_MENU_START_GAME;
	m_selPoint[E_MENU_START_GAME] = { c_nReStartX - 2, c_nReStartY };
	m_selPoint[E_MENU_EDIT_FIX_WALL] = { c_nEditWallX - 2, c_nEditWallY };
	m_selPoint[E_MENU_EXIT] = { c_nExitMenuX - 2, c_nExitMenuY };
	m_selPoint[E_MENU_SELECT_EDIT_MAP] = { c_nSelectMapX - 2, c_nSelectMapY };
	m_selPoint[E_GAME_EXIT] = { c_nExitGameX - 2, c_nExitGameY };
	//ע����̼����¼�
	RegKeyBoardNotify();
}

void MenuScence::DestoryScence()
{
	//������Ļ
	ConsoleUIBuff::GetInstance()->CleanBuff();
	//��ע��ע����̼����¼�
	UnRegKeyBoardNotify();
}

void MenuScence::BeforEnterScence()
{

	ConsoleUIBuff::GetInstance()->DrawImme(c_nReStartX, c_nReStartY, (char*)c_pszStartGame, F_H_YELLOW);
	ConsoleUIBuff::GetInstance()->DrawImme(c_nEditWallX, c_nEditWallY, (char*)c_pszEditFixWall, F_H_YELLOW);
	ConsoleUIBuff::GetInstance()->DrawImme(c_nExitMenuX, c_nExitMenuY, (char*)c_pszExitMenu, F_H_YELLOW);
	ConsoleUIBuff::GetInstance()->DrawImme(c_nSelectMapX, c_nSelectMapY, (char*)c_pszSelectMap, F_H_YELLOW);
	ConsoleUIBuff::GetInstance()->DrawImme(c_nExitGameX, c_nExitGameY, (char*)c_pszExitGame, F_H_YELLOW);
	//
	ConsoleUIBuff::GetInstance()->DrawImme(c_nExitGameX, c_nExitGameY, (char*)c_pszExitGame, F_H_YELLOW);
	//������ͷ
	ConsoleUIBuff::GetInstance()->DrawImme(m_selPoint[m_eSelect].nX, m_selPoint[m_eSelect].nY, (char*)c_pszArrow, F_H_YELLOW);
	//
	ConsoleUIBuff::GetInstance()->DrawImme(c_nEnterTipX, c_nEnterTipY, (char*)c_pszEnterTip, F_H_RED);
	ConsoleUIBuff::GetInstance()->DrawImme(c_nEscTipX, c_nEscTipY, (char*)c_pszEscTip, F_H_RED);
}

void MenuScence::RcvKeyBoardNotify(char chKey)
{

	switch (chKey)
	{
	case E_KEY_UP:case E_KEY_W:case E_KEY_w:
	{
					  EraseOldSelct();
					  int nIindex = (int)m_eSelect;
					  nIindex = (nIindex - 1 + E_MENU_MAX) % E_MENU_MAX;
					  m_eSelect = (MenuSelect)nIindex;
					  DrawSelect();
					  break;
	}

	case E_KEY_DOWN:case E_KEY_s:case E_KEY_S:
	{
						EraseOldSelct();
						int nIindex = (int)m_eSelect;
						nIindex = (nIindex + 1) % E_MENU_MAX;
						m_eSelect = (MenuSelect)nIindex;
						DrawSelect();
						break;
	}
	case E_KEY_ENTER:
	{
						//��ȡ������
						Director *pDirector = Director::GetInstance();
						//����ѡ���л�����
						switch (m_eSelect)
						{
						case E_MENU_EDIT_FIX_WALL:
						{
									EditScence *pEditScence = new EditScence();
									pDirector->ChangeScence(pEditScence);
									break;
						}
						case E_MENU_START_GAME:
						{
									MainScence *pMainGameScence = new MainScence();
									pDirector->ChangeScence(pMainGameScence);
									break;
						}
						case E_MENU_EXIT:
						{
									LogoScence *pLogo = new LogoScence();
									pDirector->ChangeScence(pLogo);
									break;
						}

						case E_GAME_EXIT:
						{
									TankGame::GetGameInstance()->StopGame();
									break;
						}
						case 		E_MENU_SELECT_EDIT_MAP:
						{
									SelectMapScence *pSelectMapScence = new SelectMapScence();
									pDirector->ChangeScence(pSelectMapScence);
								    break;
						}
						default:
							break;
						}
						break;
	}
	case E_KEY_ESC:
	{
					  Director *pDirector = Director::GetInstance();
					  LogoScence *pLogoScence = new LogoScence;
					  pDirector->ChangeScence(pLogoScence);
					  break;
	}
	default:
		break;
	}
}

void MenuScence::DrawSelect()
{
	ConsoleUIBuff::GetInstance()->DrawImme(m_selPoint[m_eSelect].nX, m_selPoint[m_eSelect].nY, (char*)c_pszArrow, F_H_YELLOW);
}

void MenuScence::EraseOldSelct()
{
	ConsoleUIBuff::GetInstance()->DrawImme(m_selPoint[m_eSelect].nX, m_selPoint[m_eSelect].nY, "  ", 0);
}

