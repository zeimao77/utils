#include "logger.h"

FILE *initLogger(char *path) {
	FILE *fp; 
	fp=fopen(path,"a");
	if(fp == NULL) {
		printf("LOGGER OPEN ERROR");
	} else {
		return fp;
	}
}

void info(FILE *file,char *msg) {
    time_t rowTime;
    struct tm *ltm;
    char nowTime[80];
    time( &rowTime );
    ltm = localtime( &rowTime );
    strftime(nowTime, 80, "%Y-%m-%d %H:%M:%S", ltm);
    fprintf(file, "[INFO][%s]:%s\n",nowTime,msg);
}

void error(FILE *file,char *msg) {
    time_t rowTime;
    struct tm *ltm;
    char nowTime[80];
    time( &rowTime );
    ltm = localtime( &rowTime );
    strftime(nowTime, 80, "%Y-%m-%d %H:%M:%S", ltm);
    fprintf(file, "[ERROR][%s]:%s\n",nowTime,msg);
}

void warn(FILE *file,char *msg) {
    time_t rowTime;
    struct tm *ltm;
    char nowTime[80];
    time( &rowTime );
    ltm = localtime( &rowTime );
    strftime(nowTime, 80, "%Y-%m-%d %H:%M:%S", ltm);
    fprintf(file, "[WARN][%s]:%s\n",nowTime,msg);
}

void closeLogger(FILE *file) {
	if(fclose(file) != 0) {
		printf("LOGGER CLOSE ERROR");
	}
}