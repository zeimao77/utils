#ifndef __SET_H__
#define __SET_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constant.h"


#define SET_MAX_LENGTH 32

struct Set {
	char *data[SET_MAX_LENGTH];
	unsigned int current_length;
	unsigned int max_length;
};

struct Set Set_init();

int Set_set(struct Set *set,int index,char *str);

char* Set_get(struct Set *set,int index);

int Set_exist(struct Set *set,char *str);

int Set_add(struct Set *set,char *str);

int Set_query(struct Set *set,char *str);

void Set_print(char *title,struct Set *set);

#endif
