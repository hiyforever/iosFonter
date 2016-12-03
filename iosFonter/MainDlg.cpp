#include "stdafx.h"
#include "windowsx.h"
#include "resource.h"
#include "MainDlg.h"
#include "commdlg.h"
#include "shellapi.h"
#include "stdio.h"
#include "shlwapi.h"

TCHAR sFile[_MAX_PATH]={0};
int sys=-1;
int sta=0;
char Ascender[10]={0};
char Descender[10]={0};
char TypoAscender[10]={0};
char TypoDescender[10]={0};
char WinAscender[10]={0};
char WinDescender[10]={0};
char AverageCharWidth[10]={0};
char Codepage1[10]={0};
char Codepage2[10]={0};
char Ascendern[10]={0};
char Descendern[10]={0};
char TypoAscendern[10]={0};
char TypoDescendern[10]={0};
char WinAscendern[10]={0};
char WinDescendern[10]={0};
char AverageCharWidthn[10]={0};
char Codepagen1[10]={0};
char Codepagen2[10]={0};
bool Font(HWND hwnd,TCHAR name[30],int n);

BOOL WINAPI Main_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
		HANDLE_MSG(hWnd,WM_INITDIALOG,Main_OnInitDialog);
		HANDLE_MSG(hWnd,WM_CTLCOLORSTATIC,Main_OnCtlColorStatic);
		HANDLE_MSG(hWnd,WM_COMMAND,Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE,Main_OnClose);
	}
	return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd,HWND hwndFocus,LPARAM lParam)
{
	SendMessage(hwnd,WM_SETICON,(WPARAM)TRUE,(LPARAM)LoadIcon(GetModuleHandle(NULL),(LPCTSTR)1));
	if(sta==-1)
	{
		SetDlgItemText(hwnd,IDE1,Ascender);
		SetDlgItemText(hwnd,IDE2,Descender);
		SetDlgItemText(hwnd,IDE3,TypoAscender);
		SetDlgItemText(hwnd,IDE4,TypoDescender);
		SetDlgItemText(hwnd,IDE5,WinAscender);
		SetDlgItemText(hwnd,IDE6,WinDescender);
		SetDlgItemText(hwnd,IDE7,Codepage1);
		SetDlgItemText(hwnd,IDE8,Codepage2);
		SetDlgItemText(hwnd,IDE9,AverageCharWidth);
	}
	else if(sta==1)
	{
		if(!PathFileExists("Fonts\\STHeiti-Light.ttc"))EnableWindow(GetDlgItem(hwnd,IDC1),false);
		if(!PathFileExists("Fonts\\STHeiti-Medium.ttc"))EnableWindow(GetDlgItem(hwnd,IDC2),false);
		if(!PathFileExists("Fonts\\STHeiti-Thin.ttc"))EnableWindow(GetDlgItem(hwnd,IDC3),false);
		if(!PathFileExists("Fonts\\STHeiti-UltraLight.ttc"))EnableWindow(GetDlgItem(hwnd,IDC4),false);
		if(!PathFileExists("Fonts\\_H_Helvetica.ttc"))EnableWindow(GetDlgItem(hwnd,IDC5),false);
		if(!PathFileExists("Fonts\\_H_HelveticaNeue.ttc"))EnableWindow(GetDlgItem(hwnd,IDC6),false);
		if(!PathFileExists("Fonts\\_H_HelveticaNeueExtras.ttc"))EnableWindow(GetDlgItem(hwnd,IDC7),false);
		if(!PathFileExists("Fonts\\_H_HelveticaNeueInterface.ttc"))EnableWindow(GetDlgItem(hwnd,IDC8),false);
		if(!PathFileExists("Fonts\\_H_HelveticaNeueLights.ttc"))EnableWindow(GetDlgItem(hwnd,IDC9),false);
		if(!PathFileExists("Fonts\\Keycaps.ttc"))EnableWindow(GetDlgItem(hwnd,IDC10),false);
	}
	sta=0;
	return TRUE;
}

HBRUSH Main_OnCtlColorStatic(HWND hwnd,HDC hdc,HWND hwndFocus,UINT nCtlColor)
{
	HBRUSH BRUSH=CreateSolidBrush(RGB(255,255,255));
	return (HBRUSH)BRUSH;
}

void Main_OnCommand(HWND hwnd,int id,HWND hwndCtl,UINT codeNotify)
{
	if(sta!=0)return;
    switch(id)
	{
	case IDCFILE:
		{
			Del();
			DeleteFile("Data\\Font.tmp");
			sFile[0]=0;
			OPENFILENAME file={0};
			file.lStructSize=sizeof(file);
			file.lpstrTitle=TEXT("请选择待修改字体");
			file.lpstrFile=sFile;
			file.nMaxFile=sizeof(sFile);
			file.lpstrFilter=TEXT("TTC、TTF字体文件\0*.ttc;*.ttf\0");
			file.hwndOwner=hwnd;
			file.Flags=OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_NOCHANGEDIR;
			GetOpenFileName(&file);
			SetDlgItemText(hwnd,IDCPATH,TEXT(sFile));
		}
		break;
	case IDCDEB:
		{
			sta=1;
			DialogBox(NULL,MAKEINTRESOURCE(IDD_VAIN),hwnd,Main_Proc);
		}
		break;
	case IDCR1:
		{
			sys=0;
		}
        break;
	case IDCR2:
		{
			sys=1;
		}
        break;
	case IDCR3:
		{
			sys=2;
		}
        break;
	case IDCSTL:
		{
			int tmp=10;
			if(sys==2)tmp=5;
			Font(hwnd,"STHeiti-Light",tmp);
		}
        break;
	case IDCSTM:
		{
			int tmp=10;
			if(sys==2)tmp=5;
			Font(hwnd,"STHeiti-Medium",tmp);
		}
        break;
	case IDCSTT:
		{
			Font(hwnd,"STHeiti-Thin",5);
		}
        break;
	case IDCSTU:
		{
			Font(hwnd,"STHeiti-UltraLight",5);
		}
        break;
	case IDCH:
		{
			Font(hwnd,"_H_Helvetica",8);
		}
        break;
	case IDCHN:
		{
			int tmp=12;
			if(sys==2)tmp=13;
			Font(hwnd,"_H_HelveticaNeue",tmp);
		}
        break;
	case IDCHNE:
		{
			int tmp=2;
			if(sys==2)tmp=3;
			Font(hwnd,"_H_HelveticaNeueExtras",tmp);
		}
        break;
	case IDCHNI:
		{
			int tmp=5;
			if(sys==2)tmp=6;
			else if(sys==1)tmp=7;
			Font(hwnd,"_H_HelveticaNeueInterface",tmp);
		}
        break;
	case IDCHNL:
		{
			int tmp=8;
			if(sys==2)tmp=9;
			Font(hwnd,"_H_HelveticaNeueLights",tmp);
		}
        break;
	case IDCK:
		{
			int tmp=2;
			if(sys==1)tmp=4;
			else if(sys==2)tmp=8;
			Font(hwnd,"Keycaps",tmp);
		}
        break;
	case IDB1:
		{
			sta=1;
			GetDlgItemText(hwnd,IDE1,Ascendern,sizeof(Ascendern));
			GetDlgItemText(hwnd,IDE2,Descendern,sizeof(Descendern));
			GetDlgItemText(hwnd,IDE3,TypoAscendern,sizeof(TypoAscendern));
			GetDlgItemText(hwnd,IDE4,TypoDescendern,sizeof(TypoDescendern));
			GetDlgItemText(hwnd,IDE5,WinAscendern,sizeof(WinAscendern));
			GetDlgItemText(hwnd,IDE6,WinDescendern,sizeof(WinDescendern));
			GetDlgItemText(hwnd,IDE7,Codepagen1,sizeof(Codepagen1));
			GetDlgItemText(hwnd,IDE8,Codepagen2,sizeof(Codepagen2));
			GetDlgItemText(hwnd,IDE9,AverageCharWidthn,sizeof(AverageCharWidthn));
			EndDialog(hwnd,0);
		}
        break;
	case IDB2:
		{
			EndDialog(hwnd,0);
		}
        break;
	case IDB3:
		{
			SetDlgItemText(hwnd,IDE1,Ascender);
			SetDlgItemText(hwnd,IDE2,Descender);
			SetDlgItemText(hwnd,IDE3,TypoAscender);
			SetDlgItemText(hwnd,IDE4,TypoDescender);
			SetDlgItemText(hwnd,IDE5,WinAscender);
			SetDlgItemText(hwnd,IDE6,WinDescender);
			SetDlgItemText(hwnd,IDE7,Codepage1);
			SetDlgItemText(hwnd,IDE8,Codepage2);
			SetDlgItemText(hwnd,IDE9,AverageCharWidth);
		}
        break;
	case IDB4:
		{
			sta=1;
			HWND hWnd=FindWindow(NULL,"iosFonter");
			SetWindowText(hWnd,TEXT("iosFonter 请稍等。。。"));
			TCHAR tmp[_MAX_PATH]={0};
			CreateDirectory("Fonts",NULL);
			if(!CopyFile("Data\\deb.exe","Fonts\\iosfont.deb",FALSE))
			{
				SetWindowText(hWnd,TEXT("iosFonter"));
				MessageBox(hwnd,TEXT("打包失败，请确保文件有写入权限或关闭iosfont.deb"),TEXT("警告"),MB_OK|MB_ICONWARNING);
				sta=0;
				return;
			}
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
			if(IsDlgButtonChecked(hwnd,IDC1))
			{
				CopyFile("Fonts\\STHeiti-Light.ttc","Data\\System\\Library\\Fonts\\Cache\\STHeiti-Light.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC2))
			{
				CopyFile("Fonts\\STHeiti-Medium.ttc","Data\\System\\Library\\Fonts\\Cache\\STHeiti-Medium.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC3))
			{
				CopyFile("Fonts\\STHeiti-Thin.ttc","Data\\System\\Library\\Fonts\\Cache\\STHeiti-Thin.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC4))
			{
				CopyFile("Fonts\\STHeiti-UltraLight.ttc","Data\\System\\Library\\Fonts\\Cache\\STHeiti-UltraLight.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC5))
			{
				CopyFile("Fonts\\_H_Helvetica.ttc","Data\\System\\Library\\Fonts\\Cache\\_H_Helvetica.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC6))
			{
				CopyFile("Fonts\\_H_HelveticaNeue.ttc","Data\\System\\Library\\Fonts\\Cache\\_H_HelveticaNeue.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC7))
			{
				CopyFile("Fonts\\_H_HelveticaNeueExtras.ttc","Data\\System\\Library\\Fonts\\Cache\\_H_HelveticaNeueExtras.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC8))
			{
				CopyFile("Fonts\\_H_HelveticaNeueInterface.ttc","Data\\System\\Library\\Fonts\\Cache\\_H_HelveticaNeueInterface.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC9))
			{
				CopyFile("Fonts\\_H_HelveticaNeueLights.ttc","Data\\System\\Library\\Fonts\\Cache\\_H_HelveticaNeueLights.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(IsDlgButtonChecked(hwnd,IDC10))
			{
				CopyFile("Fonts\\Keycaps.ttc","Data\\System\\Library\\Fonts\\Cache\\Keycaps.ttc",FALSE);
				strcpy_s(tmp,"true");
			}
			if(_stricmp(tmp,"true")!=0)
			{
				DeleteFile("Fonts\\iosfont.deb");
				SetWindowText(hWnd,TEXT("iosFonter"));
				MessageBox(hwnd,TEXT("请选择字体"),TEXT("警告"),MB_OK|MB_ICONWARNING);
				sta=0;
				return;
			}
			EndDialog(hwnd,0);
			SHELLEXECUTEINFO ShExecInfo={0};
			ShExecInfo.cbSize=sizeof(SHELLEXECUTEINFO);
			ShExecInfo.fMask=SEE_MASK_NOCLOSEPROCESS;
			ShExecInfo.hwnd=hwnd;
			ShExecInfo.lpVerb=NULL;
			ShExecInfo.lpFile="tar";
			ShExecInfo.lpParameters="-czf data.tar.gz System";
			ShExecInfo.lpDirectory="Data";
			ShExecInfo.nShow=SW_HIDE;
			ShExecInfo.hInstApp=NULL;
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
			HANDLE handle=CreateFile("Data\\data.tar.gz",GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
			wsprintf(tmp,"%-10d`\x0A",GetFileSize(handle,NULL));
			CloseHandle(handle);
			handle=NULL;
			FILE *fp=NULL;
			fopen_s(&fp,"Fonts\\iosfont.deb","ab");
			fprintf(fp,tmp,sizeof(char),12);
			fclose(fp);
			ShExecInfo.lpFile="cmd";
			ShExecInfo.lpDirectory="Fonts";
			ShExecInfo.lpParameters="/c type ..\\Data\\data.tar.gz>>iosfont.deb";
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
			DeleteFile("Data\\data.tar.gz");
			TTH=FindFirstFile("Data\\System\\Library\\Fonts\\Cache\\*",&TTD);
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
			SetWindowText(hWnd,TEXT("iosFonter"));
			if(MessageBox(hWnd,TEXT("立即查看文件"),TEXT("完成"),MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==6)
			{
				ShellExecute(NULL,"open","Fonts",NULL,NULL,SW_NORMAL);
			}
			sta=0;
		}
        break;
	case IDB5:
		{
			EndDialog(hwnd,0);
		}
        break;
	case IDB6:
		{
			CheckDlgButton(hwnd,IDC1,0);
			CheckDlgButton(hwnd,IDC2,0);
			CheckDlgButton(hwnd,IDC3,0);
			CheckDlgButton(hwnd,IDC4,0);
			CheckDlgButton(hwnd,IDC5,0);
			CheckDlgButton(hwnd,IDC6,0);
			CheckDlgButton(hwnd,IDC7,0);
			CheckDlgButton(hwnd,IDC8,0);
			CheckDlgButton(hwnd,IDC9,0);
			CheckDlgButton(hwnd,IDC10,0);
		}
        break;
	default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
	if(sta==0)EndDialog(hwnd,0);
	else MessageBox(hwnd,TEXT("请稍等。。。"),TEXT("警告"),MB_OK|MB_ICONWARNING);
}

bool Font(HWND hwnd,TCHAR name[30],int n)
{
	if(sys==-1)
	{
		MessageBox(hwnd,TEXT("请选择系统"),TEXT("警告"),MB_OK|MB_ICONWARNING);
		return false;
	}
	TCHAR tmp[_MAX_PATH]={0};
	if(GetDlgItemText(hwnd,IDCPATH,tmp,sizeof(tmp)))
	{
		sta=-1;
		Del();
		int i=0;
		char s[1024]={0};
		FILE *fp=NULL;
		SHELLEXECUTEINFO ShExecInfo={0};
		ShExecInfo.cbSize=sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask=SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd=hwnd;
		ShExecInfo.lpVerb=NULL;
		ShExecInfo.nShow=SW_HIDE;
		ShExecInfo.hInstApp=NULL;
		ShExecInfo.lpDirectory="Data";
		SetWindowText(hwnd,TEXT("iosFonter 请稍等。。。"));
		if(strcmp(TEXT(sFile),"Data\\Font.tmp")!=0)
		{
			CopyFile(TEXT(sFile),"Data\\Font.TTC",FALSE);
			ShExecInfo.lpFile="ttfname.exe";
			ShExecInfo.lpParameters="Font.TTC";
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
			ShExecInfo.lpFile="UniteTTC.exe";
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
			if(CopyFile("Data\\Font001.TTF","Data\\Font.tmp",FALSE)==0)
			{
				CopyFile(TEXT(sFile),"Data\\Font.tmp",FALSE);
			}
			fopen_s(&fp,"Data\\Font.xml","r");
			for(;fgets(s,1024,fp)&&strstr(s,"<Name>")==NULL;)
			{
				s[strlen(s)-1]=0;
				if(strstr(s,"TypoAscender")!=NULL)
				{
					strncpy_s(TypoAscender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					TypoAscender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"TypoDescender")!=NULL)
				{
					strncpy_s(TypoDescender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					TypoDescender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else 
				if(strstr(s,"WinAscender")!=NULL)
				{
					strncpy_s(WinAscender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					WinAscender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"WinDescender")!=NULL)
				{
					strncpy_s(WinDescender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					WinDescender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"Ascender")!=NULL)
				{
					strncpy_s(Ascender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					Ascender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"Descender")!=NULL)
				{
					strncpy_s(Descender,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					Descender[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"AverageCharWidth")!=NULL)
				{
					strncpy_s(AverageCharWidth,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					AverageCharWidth[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"Codepage1")!=NULL)
				{
					strncpy_s(Codepage1,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					Codepage1[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
				else if(strstr(s,"Codepage2")!=NULL)
				{
					strncpy_s(Codepage2,strchr(s,'\"')+1,strrchr(s,'\"')-strchr(s,'\"')-1);
					Codepage2[strrchr(s,'\"')-strchr(s,'\"')-1]=0;
				}
			}
			fclose(fp);
			Del();
			if(strstr(s,"<Name>")==NULL)
			{
				DeleteFile("Data\\Font.tmp");
				SetWindowText(hwnd,"iosFonter");
				if(MessageBox(hwnd,TEXT("无效字体"),TEXT("错误"),MB_RETRYCANCEL|MB_ICONERROR|MB_SYSTEMMODAL)==4)
				{
					Font(hwnd,name,n);
				}
				return false;
			}
		}
		DialogBox(NULL,MAKEINTRESOURCE(IDD_NAIN),hwnd,Main_Proc);
		Del();
		if(sta!=1)
		{
			SetWindowText(hwnd,"iosFonter");
			return false;
		}
		FILE *fr=NULL;
		for(i=1;i<=n;i++)
		{
			wsprintf(tmp,"Data\\%s%03d.xml",name,i);
			fopen_s(&fp,tmp,"wb");
			wsprintf(s,"\xEF\xBB\xBF<?xml version=\"1.0\"?>\r\n<Fonts>\r\n<Font>\r\n  <!-- ****************** Font(0) ****************** -->\r\n\r\n  <Header\r\n    Ascender=\"%s\"\r\n    Descender=\"%s\"\r\n    TypoAscender=\"%s\"\r\n    TypoDescender=\"%s\"\r\n    WinAscender=\"%s\"\r\n    WinDescender=\"%s\"\r\n    AverageCharWidth=\"%s\"\r\n    Codepage1=\"%s\"\r\n    Codepage2=\"%s\" />\r\n\r\n  <Name>\r\n\r\n",Ascendern,Descendern,TypoAscendern,TypoDescendern,WinAscendern,WinDescendern,AverageCharWidthn,Codepagen1,Codepagen2);
			fwrite(s,sizeof(char),strlen(s),fp);
			int systmp=70;
			if(sys==2)systmp=8;
			else if(sys==1)systmp=71;
			wsprintf(tmp,"Data\\IOS%d\\%s\\%s%03d.xml",systmp,name,name,i);
			fopen_s(&fr,tmp,"r");
			for(;fgets(s,1024,fr);)
			{
				s[strlen(s)-1]=0;
				fwrite(s,sizeof(char),strlen(s),fp);
				fwrite("\r\n",sizeof(char),2,fp);
			}
			fclose(fr);
			fclose(fp);
			wsprintf(tmp,"Data\\Font%d.TTF",i);
			CopyFile("Data\\Font.tmp",tmp,FALSE);
			wsprintf(tmp,"Font%d.TTF %s%03d.xml",i,name,i);
			ShExecInfo.lpFile="ttfname.exe";
			ShExecInfo.lpParameters=tmp;
			ShellExecuteEx(&ShExecInfo);
			WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
			wsprintf(tmp,"Data\\Font%d.TTF",i);
			DeleteFile(tmp);
		}
		wsprintf(tmp,"%s001_mod.TTF",name);
		ShExecInfo.lpFile="AllUniteTTC.exe";
		ShExecInfo.lpParameters=tmp;
		ShellExecuteEx(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
		CreateDirectory("Fonts",NULL);
		SetWindowText(hwnd,"iosFonter");
		wsprintf(tmp,"Fonts\\%s.ttc",name);
		if(CopyFile("Data\\Fonts.TTC",tmp,FALSE)==0)
		{
			Del();
			if(MessageBox(hwnd,TEXT("转换失败，请确保字体有效或关闭已打开字体文件"),TEXT("错误"),MB_RETRYCANCEL|MB_ICONERROR|MB_SYSTEMMODAL)==4)
			{
				Font(hwnd,name,n);
			}
		}
		else
		{
			Del();
			strcpy_s(sFile,"Data\\Font.tmp");
			if(MessageBox(hwnd,TEXT("立即查看文件"),TEXT("完成"),MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==6)
			{
				ShellExecute(NULL,"open","Fonts",NULL,NULL,SW_NORMAL);
			}
		}
		sta=0;
	}
	else MessageBox(hwnd,TEXT("请选择文件"),TEXT("警告"),MB_OK|MB_ICONWARNING);
	return true;
}

void Del(void)
{
	TCHAR tmp[_MAX_PATH]={0};
	WIN32_FIND_DATA TTD={0};
	HANDLE TTH=FindFirstFile("Data\\*",&TTD);
	if(TTH!=INVALID_HANDLE_VALUE)
	{
		wsprintf(tmp,"Data\\%s",TEXT(TTD.cFileName));
		if(_stricmp(PathFindExtension(TEXT(tmp)),".xml")==0||_stricmp(PathFindExtension(TEXT(tmp)),".ttc")==0||_stricmp(PathFindExtension(TEXT(tmp)),".ttf")==0)
			DeleteFile(TEXT(tmp));
		while(FindNextFile(TTH,&TTD))
		{
			wsprintf(tmp,"Data\\%s",TEXT(TTD.cFileName));
			if(_stricmp(PathFindExtension(TEXT(tmp)),".xml")==0||_stricmp(PathFindExtension(TEXT(tmp)),".ttc")==0||_stricmp(PathFindExtension(TEXT(tmp)),".ttf")==0)
				DeleteFile(TEXT(tmp));
		}
	}
	FindClose(TTH);
	TTH=NULL;
}
