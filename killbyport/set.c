#include "set.h"

struct Set Set_init() {
	struct Set set;
	set.current_length = 0;
	set.max_length = SET_MAX_LENGTH;
	return set;
}

int Set_set(struct Set *set,int index,char *str) {
	if(index > set->current_length) {
		return CONSTANT_RESULT_FAIL;
	}
	set->data[index] = str;
	return CONSTANT_RESULT_SUCCESS;
}

char* Set_get(struct Set *set,int index) {
	if(index >=  set -> current_length) {
		return NULL;
	}
	return set -> data[index];
}

int Set_exist(struct Set *set,char *str) {
	if(Set_query(set,str) >= 0) {
		return CONSTANT_RESULT_SUCCESS;
	}
	return CONSTANT_RESULT_FAIL;
}

void Set_print(char *title,struct Set *set) {
	if(set -> current_length > 0 && strlen(title) > 1) {
		printf("==========[%s]==========\n", title);
	}
	for (int i = 0; i < set -> current_length; i++){
		printf("[%d] %s ;\n",i,set->data[i]);
	}
}

int Set_add(struct Set *set,char *str) {
	if(str == NULL) {
		return CONSTANT_RESULT_FAIL;
	}
	if(strlen(str) == 0) {
		return CONSTANT_RESULT_FAIL;
	}
	if(Set_exist(set,str) == CONSTANT_RESULT_SUCCESS) {
		return CONSTANT_RESULT_SUCCESS;
	}
	if(set -> current_length > set -> max_length) {
		return CONSTANT_RESULT_FAIL;	
	}
	set->data[set->current_length] = str;
	set->current_length++;
	return CONSTANT_RESULT_SUCCESS;
}

int Set_query(struct Set *set,char *str) {
	for (int i = 0; i < set -> current_length; i++){
		if(strcmp(str,set->data[i]) == 0) {
			return i;
		}
	}
	return -1;
}


