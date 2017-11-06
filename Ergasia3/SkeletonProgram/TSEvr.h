/*Zapalidi Ioanna, 1115201400044*/

#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>
typedef char keyType[5];

typedef struct data {
        keyType ICAO;
        char 	IATA[4];
        char 	*City;
        char 	*Name;
        char 	*Country;
} TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source);

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem);

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem);

#endif
