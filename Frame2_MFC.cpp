#include"Frame2_MY.h"
extern CMyWinApp theApp;
BOOL CWnd::Create()
{
	cout << "CWnd::Create!\n";
	return TRUE;
}
BOOL CWnd::CreateEx()
{
	cout << "CWnd::CreateEx()!\n";
	PreCreateWindow();
	return TRUE;
}
BOOL CWnd::PreCreateWindow()
{
	cout << "cout<<CWnd::PreCreateWindow!\n";
	return TRUE;
}
BOOL CFrameWnd::Create()
{
	cout << "CframeWnd::Create!\n";
	PreCreateWindow();
	return TRUE;
}
BOOL CFrameWnd::PreCreateWindow()
{
	cout << "CFrameWnd::PreCreateWindow!\n";
	return TRUE;
}

CWinApp* AfxGetApp()
{
	return theApp.m_pCurrentWinapp;
}