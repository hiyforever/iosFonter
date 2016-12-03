#include "stdafx.h"
#include "resource.h"
#include "MainDlg.h"

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	HANDLE hMutex=CreateMutex(NULL,FALSE,"iosFonter");
	if(GetLastError()==ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hMutex);
		hMutex=NULL;
		HWND hWnd=FindWindow(NULL,"iosFonter");
		SwitchToThisWindow(hWnd,TRUE);
		hWnd=FindWindow(NULL,"iosFonter «Î…‘µ»°£°£°£");
		SwitchToThisWindow(hWnd,TRUE);
		hWnd=NULL;
		return 0;
	}
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_MAIN),NULL,Main_Proc);
	Del();
	TCHAR tmp[_MAX_PATH]={0};
	WIN32_FIND_DATA TTD={0};
	HANDLE TTH=FindFirstFile("Data\\System\\Library\\Fonts\\Cache\\*",&TTD);
	if(TTH!=INVALID_HANDLE_VALUE)
	{
		wsprintf(tmp,"Data\\System\\Library\\Fonts\\Cache\\%s",TEXT(TTD.cFileName));
		DeleteFile(TEXT(tmp));
		while(FindNextFile(TTH,&TTD))
		{
			wsprintf(tmp,"Data\\System\\Library\\Fonts\\Cache\\%s",TEXT(TTD.cFileName));
			DeleteFile(TEXT(tmp));
		}
	}
	FindClose(TTH);
	TTH=NULL;
	DeleteFile("Data\\data.tar.gz");
	DeleteFile("Data\\Font.tmp");
	CloseHandle(hMutex);
	hMutex=NULL;
	PostQuitMessage(0);
	return 0;
}
