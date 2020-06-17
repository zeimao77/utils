#include "winlib.h"

int cmd(char *cmd,char *result) {
	char buffer[20480];
	FILE *f = popen(cmd,"r");
	if(!f) {return -1;}
	while(!feof(f)) {
		if(fgets(buffer,4096,f)) {
			strcat(result,buffer);
		}
	}
	pclose(f);
	return 0;
}

void delay(int second) {
    printf("µÈ´ýÖÐ£º%d", second);
    for (int i = 1; i <= second; i++){
        Sleep(1000);
        printf("\b%d",second-i);
    }
    printf("\n");
}