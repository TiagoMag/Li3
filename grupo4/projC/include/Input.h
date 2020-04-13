#ifndef Input_H
#define Input_H

#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "View.h"

int inputQuery1(SGV sgv,char* filenames[3]);
char inputQuery2();
char inputQuery3(char* codigo,int* mes);
int inputQuery4();
int inputQuery7(char* code);
int inputQuery8(int* mes1,int* mes2);
int inputQuery9(char* productID);
int inputQuery10(char* clientID);
int inputQuery11();
int inputQuery12(char* clientID);

#endif