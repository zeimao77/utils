#include "keyboard.h"

void boardkey(char key,int wait) {
	keybd_event(key, 0, 0, 0); //按下
	Sleep(10);
	keybd_event(key, 0, KEYEVENTF_KEYUP, 0); //松开
	Sleep(wait);
}

int secondBoardkey(char * cas,char key,int wait) {
	int ctrl = 0,alt = 0,shift = 0,window = 0;
	ctrl = haveChar(cas,'C');
	alt = haveChar(cas,'A');
	shift = haveChar(cas,'S');
	window = haveChar(cas,'W');
	if(window) {
		keybd_event(91, 0, 0, 0);
	}
	if(ctrl) {
		keybd_event(17, 0, 0, 0);
	}
	if(shift) {
		keybd_event(16, 0, 0, 0);
	}
	if(alt) {
		keybd_event(18, 0, 0, 0);
	}
	keybd_event(key, 0, 0, 0); 
	Sleep(10);
	keybd_event(key, 0, KEYEVENTF_KEYUP, 0); 
	if(alt) {
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
	}
	if(shift) {
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
	}
	if(ctrl) {
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
	}
	if(window) {
		keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
	}
	Sleep(wait);
}

int boardkeyName(char* keyName) {
	boardkey(getkey(keyName),0);
}

int boardkeyNames(char* keys) {
	for(int i=0;i<strlen(keys);i++) {
		boardkey(keys[i],0);
	}
}

int doaction(struct KeyBoardAction *action) {
	char *a1 = action -> arg1;
	char *a2 = action -> arg2;
	char *a3 = action -> arg3;
	if(strcmp("boardkey",action -> actionName) == 0) {
		int p1 = atoi(a1);
		int p2 = atoi(a2);
		boardkey(p1,p2);
		return 1;
	}
	if(strcmp("secondBoardkey",action -> actionName) == 0) {
		int p2 = atoi(a2);
		int p3 = atoi(a3);
		secondBoardkey(a1,p2,p3);
		return 1;
	}
	if(strcmp("boardkeyName",action -> actionName) == 0) {
		boardkeyName(a1);
		return 1;
	}
	if(strcmp("boardkeyNames",action -> actionName) == 0) {
		boardkeyNames(a1);
		return 1;
	}
	if(strcmp("wait",action -> actionName) == 0) {
		int p1 = atoi(a1);
		Sleep(p1);
		return 1;
	}
	return 0;
}

char getkey(char* keyName) {
	if(strcmp(".",keyName) == 0) {
		return 0xBE;
	}
	if(strcmp(",",keyName) == 0) {
		return 0xBC;
	}
	if(strcmp("BACK",keyName) == 0) {
		return 0x08;
	}
	if(strcmp("ENTER",keyName) == 0) {
		return 0x0D;
	}
	if(strcmp("TAB",keyName) == 0) {
		return 0x09;
	}
	if(strcmp("CAPSLOCK",keyName) == 0) {
		return 0x14;
	}
	if(strcmp("ESC",keyName) == 0) {
		return 0x1B;
	}
	if(strcmp("SPACE",keyName) == 0) {
		return 0x20;
	}
	if(strcmp("PGUP",keyName) == 0) {
		return 0x21;
	}
	if(strcmp("PGWN",keyName) == 0) {
		return 0x22;
	}
	if(strcmp("UP",keyName) == 0) {
		return 0x26;
	}
	if(strcmp("LEFT",keyName) == 0) {
		return 0x25;
	}
	if(strcmp("DOWN",keyName) == 0) {
		return 0x28;
	}
	if(strcmp("RIGHT",keyName) == 0) {
		return 0x27;
	}
	if(strcmp("-",keyName) == 0) {
		return 0xBD;
	}
	if(strcmp("=",keyName) == 0) {
		return 0xBB;
	}
	if(strcmp(";",keyName) == 0) {
		return 0xBA;
	}
	if(strcmp("/",keyName) == 0) {
		return 0x6F;
	}
	if(strcmp("`",keyName) == 0) {
		return 0xC0;
	}
	if(strcmp("\\",keyName) == 0) {
		return 0xDC;
	}
	if(strcmp("F1",keyName) == 0) {
		return 0x70;
	}
	if(strcmp("F2",keyName) == 0) {
		return 0x71;
	}
	if(strcmp("F3",keyName) == 0) {
		return 0x72;
	}
	if(strcmp("F4",keyName) == 0) {
		return 0x73;
	}
	if(strcmp("F5",keyName) == 0) {
		return 0x74;
	}
	if(strcmp("F6",keyName) == 0) {
		return 0x75;
	}
	if(strcmp("F7",keyName) == 0) {
		return 0x76;
	}
	if(strcmp("F8",keyName) == 0) {
		return 0x77;
	}
	if(strcmp("F9",keyName) == 0) {
		return 0x78;
	}
	if(strcmp("F10",keyName) == 0) {
		return 0x79;
	}
	if(strcmp("F11",keyName) == 0) {
		return 0x7A;
	}
	if(strcmp("F12",keyName) == 0) {
		return 0x7B;
	}
	if(strcmp("WIN",keyName) == 0) {
		return 0x5B;
	}
	if(strcmp("END",keyName) == 0) {
		return 0x23;
	}
	if(strcmp("HOME",keyName) == 0) {
		return 0x24;
	}
	if(strcmp("Ins",keyName) == 0) {
		return 0x2D;
	}
	if(strcmp("Del",keyName) == 0) {
		return 0x2E;
	}
	if(strcmp("MOUSE",keyName) == 0) {
		return 0x5D;
	}
	if(strcmp("'",keyName) == 0) {
		return 0xDE;
	}
}
