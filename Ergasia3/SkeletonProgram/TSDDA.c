/*Zapalidi Ioanna, 1115201400044*/

#include <stdlib.h>
#include <string.h>
#include "TSDDA.h"

int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source)
{
	malloc(sizeof(TStoixeiouDDA));
	strcpy (target->key, source.key);
	target->arrayIndex = source.arrayIndex;
	return 0;
};

int TSDDA_setKey(keyType * key, keyType Val)
{
	strcpy (*key, Val);
	return 0;
};

int TSDDA_setIndex(int * Index, int Val)
{
	malloc(sizeof(int*));
	*Index = Val;
	return 0;
};

/* Comparing Functions - Basical */

int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2) 			/*return 1 if equal, else 0 */
{
	return(strcmp(s1.key, s2.key)==0);
};

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2)  /*return 1 if s1<s2 else 0 */
{
	return(strcmp(s1.key, s2.key)<0);
};

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2) /*return 1 if s1>s2 else 0 */
{
	return(strcmp(s1.key, s2.key)>0);
};

/* The Following are already Implemented using Above */

int TSDDA_mikrotero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{ 
    return TSDDA_mikrotero(s1,s2)||TSDDA_iso(s1,s2);
};

int TSDDA_megalytero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_megalytero(s1,s2)||TSDDA_iso(s1,s2);
};

int TSDDA_diaforo(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return !TSDDA_iso(s1,s2);
};
