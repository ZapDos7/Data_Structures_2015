//Zapalidi Ioanna, AM:1115201400044

#ifndef __TSMENU__
#define __TSMENU__
#include <stdio.h>

typedef struct Komvos {
	char * Name; 	// Name of Category or Plate
	int Category;	// 0 if Plate, 1 if Category
	float Price;	// Valid only if Plate
} TStoixeiouMenu;

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs); // Lhs = Rhs
int TSPrintValue(FILE *out, TStoixeiouMenu V);
int TSReadValue(FILE *in, TStoixeiouMenu * V);

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs) { 	// Lhs = Rhs
	strcpy (Lhs->Name, Rhs.Name);							//name
	Lhs->Category = Rhs.Category;							//category (1/0)
	Lhs->Price = Rhs.Price;								//price whether it is plate or not
	return;
};

int TSPrintValue(FILE *out, TStoixeiouMenu V) { 
	fprintf(out, "Name is %s.\nCategory is %d.\nPrice is %f.\n", V.Name, V.Category, V.Price);
	return 0;
};

int TSReadValue(FILE *in, TStoixeiouMenu * V) {
	fscanf(in, "%s, %d, %f", &V->Name, &V->Category, &V->Price);
	return 0;
};
#endif
