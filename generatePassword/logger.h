#ifndef __LOGGER_H__

#define __LOGGER_H__

#include <stdio.h>
#include <time.h>

enum LEVEL {
    LOGGER_LEVEL_INFO,LOGGER_LEVEL_WARN,LOGGER_LEVEL_ERROR
};

FILE *initLogger(char *path);
void info(FILE *file,char *str);
void error(FILE *file,char *str); 
void warn(FILE *file,char *str); 
void LoggerClose(FILE *file); 
#endif