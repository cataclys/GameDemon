#pragma once
//���̼���¼��ص��Ĵ��麯��


class IKeyboardNotify
{
public:
	virtual void RcvKeyBoardNotify(char chKey) = 0;
	virtual void RegKeyBoardNotify() = 0;
	virtual void UnRegKeyBoardNotify() = 0;
};

