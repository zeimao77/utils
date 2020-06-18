#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "keyboard.h"
#include "keymouse.h"
#include "fileio.h"

int main(int argc, char *argv[]) {
	for(int i = 0;i<argc;i++) {
		printf("param[%d]=%s\n",i,argv[i]);
	}
	char *filepath = NULL;
	if(argc >= 2) {
		filepath = argv[1];
		printf("read filepath=%s\n",filepath);
	} else {
		return 0;
	}
	struct KeyBoardActionList *actionList = (struct KeyBoardActionList *)malloc(sizeof(struct KeyBoardActionList)*1);
	actionList -> size = 0;
	actionList -> actions = (struct KeyBoardAction *)malloc(sizeof(struct KeyBoardAction) * 2048);
	readfile(filepath,actionList);
	struct KeyBoardAction *p = actionList -> actions;
	printf("read file success !!! size=%d;\n",actionList -> size);
	for(int i=0;i<actionList -> size;i++) {
		printf("action%d:%s(%s,%s,%s)\n",i + 1,(p + i) -> actionName,(p+i)->arg1,(p+i)->arg2,(p+i)->arg3);
		if(strcmp("reset",(p + i) -> actionName) == 0 ) {
			int p1 = atoi((p+i)->arg1);
			//如果arg2>0将重定义指针到指定位置，否则跳过CALL指令
			int p2 = atoi((p+i)->arg2);
			if(p2 > 0) {
				p2--;
				sprintf((p+i)->arg2, "%d", p2);
				i = p1 - 2;
			}
			continue;
		}
		doaction((p + i));
	}
	free(actionList -> actions);
	free(actionList);
	actionList=NULL;
	return 0;
}

