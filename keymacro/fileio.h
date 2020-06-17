#ifndef __FILEIO_H__

#define __FILEIO_H__

#include <stdio.h>
#include "keyboard.h"
#include "libstring.h"

void readfile(char* filepath, struct KeyBoardActionList* actionList);

#endif