#pragma once
#include<iostream>
#include"Frame2_MFC.h"
class CMyWinApp :public CWinApp
{
public:
	CMyWinApp() { cout << "CMyWinApp Construct!"; };
	~CMyWinApp() { cout << "CMyWinApp Destruct!"; };
	virtual BOOL InitInstance() {};
};
class CMyFrameWnd :public CFrameWnd
{
public:
	CMyFrameWnd() { cout << "CMyFrameWnd Construct!"; };
	~CMyFrameWnd() { cout << "CMyFrameWnd Destruct!"; };
};


