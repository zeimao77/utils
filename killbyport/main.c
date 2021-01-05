#include "winlib.h"
#include "set.h"
#include "constant.h"
#include <string.h>

int findPid(char *port,struct Set *set);
int killPid(char *pid);
void str_remove_blank(char *ch);

int main(int argc, char *argv[]){
	struct Set port_set = Set_init();
	if(argc <= 1) {
		char str[32];
		printf("%s\n","请输入端口，多个端口用空格[' ']分隔:");
		scanf("%[^\n]", str);
		if(strlen(str) <= 1) {
			return CONSTANT_RESULT_SUCCESS;
		}
		char *p = strtok(str," ");
		while(p != NULL) {
	    	Set_add(&port_set,p);
	    	p = strtok(NULL," ");
	    }
	} else {
		for(int i=1;i<=argc;i++) {
			Set_add(&port_set,argv[i]);
		}
	}
    Set_print("接收到如下端口需要处理",&port_set);
	struct Set pid_set = Set_init();
	for(int i=0;i<port_set.current_length;i++) {
    	findPid(Set_get(&port_set,i),&pid_set);
	}
    Set_print("查找到PID列表",&pid_set);
    if(pid_set.current_length > 0) {
    	delay(3);
    }
    for(int i=0;i<pid_set.current_length;i++) {
    	killPid(Set_get(&pid_set,i));
	}
	printf("%s\n","RESULT SUCCESS");
    return 0;
}



int findPid(char *port,struct Set *set) {
	char command[32];
	char buffer[10240]="";
	char *cmd_findport = "netstat -aon|findstr ";
	strcpy(command,cmd_findport);
    strcat(command,port);
    if(cmd(command, buffer) == 0){
	char *p = strtok(buffer,"\n");
	while(p != NULL) {
		char pid[8] ={};
		char flag = -1;
		for(int i=0;i<strlen(p);i++) {
			if(p[i] == 'G') {
				flag = 0;
			}
			if(flag >= 0 && p[i] != 'G' && p[i] != ' ') {
				pid[flag] = p[i];
				flag++;
			}
			pid[flag] = '\0';
		}
		str_remove_blank(pid);
		Set_add(set,pid);
		p = strtok(NULL,"\n");
	}
    }
    return CONSTANT_RESULT_SUCCESS;
}

int killPid(char *pid) {
	char *cmd_killpid = "taskkill -F -PID ";
	char command[50];
    strcpy(command,cmd_killpid);
    strcat(command,pid);
    system(command);
}

void str_remove_blank(char *ch) {
	char *c;
	while (*ch != 0x20) {
		if (*ch == '\0')
		{
			return;
		}
		ch++;
	}
	c = ch + 1;
	while (*c == 0x20) {
		c++;
	}
	while (*c != '\0') {
		if (*c != 0x20)
		{
			*ch = *c;
			*c = 0x20;
			ch++;
		}
		c++;
	}
	*ch = '\0';
	return;
}