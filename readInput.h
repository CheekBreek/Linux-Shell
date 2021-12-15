#ifndef READINPUT_H
#define READINPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "model.h"


#define MAX 100


int splitString(char* strIn, char** strOut);
void printShell();
int readInput(char* str, struct Command* command);





#endif
