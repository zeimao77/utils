#include "fileio.h"

void readfile(char* filepath, struct KeyBoardActionList* actionList) {
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	struct KeyBoardAction *actionArr;
	actionArr = actionList -> actions;
	int i = 0;
	char *p = NULL;
	char buffer[1024];
	while(i<2048) {
		if(feof(fp)) break;
		fgets(buffer, 1024, (FILE*)fp);
		if(buffer[0] == '#') {
			continue;
		}
		printf("line:%d=%s", i,buffer);
		char *str = rtrim(buffer);
		char *p = strtok(str," ");
		if(p == NULL) {continue;}
		strcpy((actionArr + i)->actionName,p);
		i++;
		(actionList -> size)++;
		p = strtok(NULL," ");
		if(p == NULL) {continue;}
		strcpy((actionArr + i -1)->arg1,p);
		p = strtok(NULL," ");
		if(p == NULL) continue;
		strcpy((actionArr + i -1)->arg2,p);
		p = strtok(NULL," ");
		if(p == NULL) continue;
		strcpy((actionArr + i -1)->arg3,p);
	}
	fclose(fp);
}