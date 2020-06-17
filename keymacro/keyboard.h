#ifndef __KEYBOARD_H__

#define __KEYBOARD_H__

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "libstring.h"

struct KeyBoardAction{
	char actionName[32];
	char arg1[32];
	char arg2[16];
	char arg3[16];
};

struct KeyBoardActionList {
	struct KeyBoardAction *actions;
	int size;
};

int secondBoardkey(char * cas,char key,int wait);
void boardkey(char key,int wait);
char getkey(char* keyName);
int press(char* keyName);
int presss(char* keys);
int doaction(struct KeyBoardAction *action);

#endif