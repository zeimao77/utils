#include "systemutil.h"

int copyToClipboard(char *str) {
	if(!OpenClipboard(NULL)) {   
        return -1;
    }
    if(!EmptyClipboard()) {
        CloseClipboard();
        return -1; 
    }
	HGLOBAL hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(str)+1)*sizeof(TCHAR)));
	if (!hMen)   
    {   
        printf("分配全局内存出错！\n");      
        CloseClipboard();   
        return -1;         
    }  
	LPSTR lpStr = (LPSTR)GlobalLock(hMen);    
    memcpy(lpStr, str, ((strlen(str))*sizeof(TCHAR)));        
    lpStr[strlen(str)] = '\0';      
    GlobalUnlock(hMen);
	SetClipboardData(CF_TEXT, hMen);
	CloseClipboard();
	return 0;
}

void delay(int second) {
    printf("等待中：%d", second);
    for (int i = 1; i <= second; i++){
        Sleep(1000);
        printf("\b%d",second-i);
    }
    printf("\n");
}