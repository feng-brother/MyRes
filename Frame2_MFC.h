#pragma once
#include<iostream>
using namespace std;
#define BOOL int 
#define TRUE 1
#define FALSE 0
class CObject
{
public:
	CObject() { cout << "CObject Construct!\n"; };
	~CObject() { cout << "CObject Destructtor!\n"; };
};
class CCmdTarGet:public CObject
{
public:
	CCmdTarGet() { cout << "CCmdTarGet Construct!\n"; };
	~CCmdTarGet() { cout << "CCmdTarGet Destructtor!\n"; };
};
class CWinThread:public CCmdTarGet
{
public:
	CWinThread() { cout << "CWinThread Construct!\n"; };
	~CWinThread() { cout << "CWinThread Destructtor!\n"; };
	virtual BOOL InitInstance()
	{
		cout << "CWinThread::InitTnstance!\n";
		return TRUE;
	}
	virtual BOOL Run()
	{
		cout << "CWinThrad::Run!\n";
		return TRUE;
	}
};

class CWnd;

class CWinApp:public CWinThread
{
public:
	CWinApp() 
	{
		m_pCurrentWinapp = this;
		cout << "CWinApp Construct!\n"; 
	};
	~CWinApp() { cout << "CWinApp Destructtor!\n"; };

	virtual BOOL InitApplication()
	{
		cout << "CWinApp::InitApplication!\n";
	}
	virtual BOOL InitInstance()
	{
		cout << "CWinApp::InitInstance!\n";
	}
	virtual BOOL Run()
	{
		cout << "CWinApp::Run!\n";
		return CWinThread::Run();
	}
public:
	CWinApp* m_pCurrentWinapp;
	CWnd* m_pMainWnd;
};

class CWnd :public CCmdTarGet
{
public:
	CWnd() { cout << "CWnd Construct!\n"; };
	~CWnd() { cout << "CWnd Destructtor!\n"; };

	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
};

class CDocument :public CCmdTarGet
{
public:
	CDocument() { cout << "CDocument construct!\n"; };
	~CDocument() { cout << "CDocument Destructtor!\n"; };
};

class CView :public CWnd
{
public:
	CView() { cout << "CView Construct!\n"; };
	~CView() { cout << "CView Destructtor!\n"; };
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd() { cout << "CFrameWnd Construct!\n"; };
	~CFrameWnd() { cout << "CFrameWnd Destructtor!\n"; };
	BOOL Create();
	virtual BOOL PreCreateWindow();
};

CWinApp* AfxGetApp();














