#include <time.h>
#include "systemutil.h"
#include "logger.h"

int main(int argc, char *argv[]){
	char range[80],rangeFlag[5],password[512],temp[32];
	int range_length = 0,i=0,length = 0;
	if(argc >= 2) {
		length = atoi(argv[1]);
	} else {
		printf("%s","�����볤��[Ĭ��12]��");
		if(scanf("%[0-9]%[^\n]",temp) == 0) {
			length = 0x0C;
		} else {
			length = atoi(temp);
		}
		fflush(stdin);
	}
	if(argc >= 3) {
		strcpy(rangeFlag,argv[2]);
	} else {
		printf("%s\n","0001 ֧��Сд��ĸ");
		printf("%s\n","0010 ֧�ִ�д��ĸ");
		printf("%s\n","0100 ֧�������ַ�");
		printf("%s\n","1000 ֧���������");
		printf("%s","�����������ѡ��[Ĭ��0x0111]��0x");
		if(scanf("%[0-9]%[^\n]", rangeFlag) == 0) {
			rangeFlag[0] = 0x30;
			rangeFlag[1] = 0x31;
			rangeFlag[2] = 0x31;
			rangeFlag[3] = 0x31;
			rangeFlag[4] = '\0';
		}
	}
	printf("���볤��=%d\n",length);
	printf("��������=%s;\n",rangeFlag);
	if(rangeFlag[2] == 0x31) {
		for(i = 0x41;i<=0x5A;i++) {
			range[range_length++] = i;
		}
	}
	if(rangeFlag[3] == 0x31) {
		for(i = 0x61;i<=0x7A;i++) {
			range[range_length++] = i;
		}
	}
	if(rangeFlag[1] == 0x31) {
		for(i = 0x30;i<=0x39;i++) {
			range[range_length++] = i;
		}
	}
	if(rangeFlag[0] == 0x31) {
		range[range_length++] = 0x21;
		range[range_length++] = 0x40;
		range[range_length++] = 0x23;
		range[range_length++] = 0x24;
		range[range_length++] = 0x25;
		range[range_length++] = 0x5E;
		range[range_length++] = 0x26;
		range[range_length++] = 0x2A;
		range[range_length++] = 0x28;
		range[range_length++] = 0x29;
	}
	range[range_length] = '\0';
	srand((unsigned)time(NULL));
	for (i = 0; i < length; i++) {
		int ind = rand() % range_length;
		password[i] = range[ind];
	}
	password[i]='\0';
    FILE *file = initLogger("generatePassword.log");
    info(file,password);
	if(!copyToClipboard(password)) {
		printf("���(�Ѹ��Ƶ���ճ��):%s\n",password);
	} else {
		printf("���:%s\n",password);
	}
	closeLogger(file);
	system("pause");
}