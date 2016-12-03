#ifndef _MAIN_H
#define _MAIN_H

BOOL WINAPI Main_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
BOOL Main_OnInitDialog(HWND hwnd,HWND hwndFocus,LPARAM lParam);
HBRUSH Main_OnCtlColorStatic(HWND hwnd,HDC hdc,HWND hwndFocus,UINT nCtlColor);
void Main_OnCommand(HWND hwnd,int id,HWND hwndCtl,UINT codeNotify);
void Main_OnClose(HWND hwnd);
void Del(void);

#endif
