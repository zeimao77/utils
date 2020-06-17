#include "keymouse.h"

void click(int x,int y,int wait) {
	//该函数把光标移到屏幕的指定位置
	SetCursorPos(x,y);
	//鼠标单击
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0,0); //左键按下
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);  //左键松开
	Sleep(wait);
}
