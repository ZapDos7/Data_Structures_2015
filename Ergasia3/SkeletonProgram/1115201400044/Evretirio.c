/*Zapalidi Ioanna, 1115201400044*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "Evretirio.h"
#include "TSDDA.h"
#include "TSEvr.h"
#include <stdio.h>

#define MAXSIZE 5000

#define Simple 1 /* 0 for AVL - any Evr integer for Simple  */
   
#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; 	/* array of size MaxSize */
       int Index;             		/* index of first available element in array */
       typos_deikti TreeRoot;  	    /* Root of DDA */
} EvrNode;

/* Functions on EvrNode */

/* 1 */
EvrPtr EvrConstruct(int MaxSize)
{
	EvrPtr temp;
	typos_deikti TreeRoot;
#if (Simple)
	printf("Use simple BST.\n");
    Tree_dimiourgia(&TreeRoot);
#else   
    printf("Use AVL BST.\n");
    AVLTree_dimiourgia(&TreeRoot);
#endif
	temp = malloc(sizeof(EvrPtr));
	temp->DataArray = NULL;
	temp->DataArray[MaxSize];
	temp->Index = 0;
	temp->TreeRoot = NULL;
	return temp;
};

/* 2 */
int Evr_Insert(EvrPtr E, TStoixeiouEvr Data)
{
	assert (E == NULL);
	if (E==NULL) return 2;
	else {
		E++;
		E = malloc(sizeof(EvrPtr));
		strcpy (E->DataArray->ICAO, Data.ICAO);
		strcpy (E->DataArray->IATA, Data.IATA);
		strcpy (E->DataArray->City, Data.City);
		strcpy (E->DataArray->Name, Data.Name);
		strcpy (E->DataArray->Country, Data.Country);
		/*strcpy (E->TreeRoot.dedomena.key, E->DataArray->ICAO);	*/	/* same for BST & AVL */
		/* E->Index = E->TreeRoot->dedomena.arrayIndex; */				/* gives error about . and -> without solution!!! */
		return 0;
	};
};

/* 3 */
int EvrSearch(EvrPtr E, keyType key, int * found)
{
	assert (E == NULL);
	#if (Simple)
		/* Tree_anazitisi (E->TreeRoot, E->TreeRoot.dedomena, *(E->TreeRoot), found); */ /* gives error about . and -> without solution!!! */
	#else
		AVLTree_anazitisi (E->TreeRoot, E->TreeRoot.dedomena, *(E->TreeRoot), found);
	#endif
	return *found;
};

/* 4 */
int Evr_PrintAll(EvrPtr E, FILE *out, int * counter)
{
	typos_deikti a=E->TreeRoot;

	/* endo-diadromh - use recursion with apaidi-depaidi */ 
	/* example of use */
#if (Simple)
    a=Tree_apaidi(a);
#else   
    a=AVLTree_apaidi(a);
#endif
}

/* 5 */
int EvrDestruct(EvrPtr *E)
{
	;
};
