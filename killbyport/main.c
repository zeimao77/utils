#include "winlib.h"
#include "constant.h"
#include "seq.h"
#include <string.h>

int findPid(char *port,struct Seq *set);
int killPid(char *pid);
void str_remove_blank(char *ch);

int main(int argc, char *argv[]){
	struct Seq *s1 = Seq_init(16);
	if(argc <= 1) {
		char str[32];
		printf("%s\n","请输入端口，多个端口用空格[' ']分隔:");
		scanf("%[^\n]", str);
		if(strlen(str) <= 1) {
			return CONSTANT_RESULT_SUCCESS;
		}
		char *p = strtok(str," ");
		while(p != NULL) {
			struct Node *n1 = Node_init(p);
			Seq_append(s1,n1);
	    	p = strtok(NULL," ");
	    }
	} else {
		for(int i=1;i<=argc;i++) {
			if(argv[i] != NULL && strlen(argv[i]) > 0) {
				struct Node *n1 = Node_init(argv[i]);
				Seq_append(s1,n1);
			}

		}
	}
    Seq_print("接收到如下端口需要处理",s1);
	struct Seq *s2 = Seq_init(32);
	for(int i=0;i<s1->current_length;i++) {
		char *p = s1->nodes[i].str;
    	findPid(p,s2);
	}
    Seq_print("查找到PID列表",s2);
    if(s2->current_length > 0) {
    	delay(3);
    }
    for(int i=0;i<s2->current_length;i++) {
    	char *p = s2->nodes[i].str;
    	killPid(p);
	}
	printf("%s\n","处理结束，成功！！");
    return 0;
}


int findPid(char *port,struct Seq *seq) {
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
		struct Node *n = Node_init(pid);
		if(pid != NULL && strlen(pid) > 0 && Seq_search(seq,*n) <0) {
			Seq_append(seq,n);
		}
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