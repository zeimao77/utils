#include "libstring.h"

char* rtrim(char *str) {
    if (str == NULL || *str == '\0') {
        return str;
    }
    int len = strlen(str);
    char *p = str + len - 1;
    while (p >= str  && isspace(*p)) {
        *p = '\0';
        --p;
    }
    return str;
}

int haveChar(char *str,char ch) {
    for(int i=0;i<strlen(str);i++) {
        if(ch == str[i]) {
            return 1;
        }
    }
    return 0;
}