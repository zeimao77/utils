#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "keyboard.h"
#include "keymouse.h"
#include "fileio.h"

void changeWindows();

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
	changeWindows();
	struct KeyBoardActionList *actionList = (struct KeyBoardActionList *)malloc(sizeof(struct KeyBoardActionList)*1);
	actionList -> size = 0;
	actionList -> actions = (struct KeyBoardAction *)malloc(sizeof(struct KeyBoardAction) * 2048);
	readfile(filepath,actionList);
	struct KeyBoardAction *p = actionList -> actions;
	printf("read file success !!! size=%d;\n",actionList -> size);
	for(int i=0;i<actionList -> size;i++) {
		printf("action%d:%s(%s,%s,%s)\n",i,(p + i) -> actionName,(p+i)->arg1,(p+i)->arg2,(p+i)->arg3);
		doaction((p + i));
	}
	free(actionList -> actions);
	free(actionList);
	actionList=NULL;
	return 0;
}

void changeWindows() {
	secondBoardkey("A",9,1000);
}
