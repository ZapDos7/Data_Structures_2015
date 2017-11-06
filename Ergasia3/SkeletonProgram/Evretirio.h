/*Zapalidi Ioanna, 1115201400044*/

#ifndef __Evr__
#define __Evr__

#include <stdlib.h>
#include <stdio.h>
#include "TSEvr.h"

typedef struct EvrNode *EvrPtr;

EvrPtr EvrConstruct(int MaxSize);
int EvrInsert(EvrPtr E, TStoixeiouEvr Data);
int EvrSearch(EvrPtr E, keyType key, int * found);
int EvrPrintAll(EvrPtr E, FILE *out, int *counter);
int EvrDestruct(EvrPtr *E);							/* na kseroume na bazoume idio onomataki stis fucntions to .c kai to .h allh fora!!! */

#endif
