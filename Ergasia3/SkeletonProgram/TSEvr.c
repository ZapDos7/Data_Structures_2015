/*Zapalidi Ioanna, 1115201400044*/

#include "TSEvr.h"
#include <stdlib.h>
#include <string.h>

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source)
{
	malloc(sizeof(TStoixeiouEvr));
	strcpy (target->ICAO, source.ICAO);
	strcpy (target->IATA, source.IATA);
	strcpy (target->City, source.City);
	strcpy (target->Name, source.Name);
	strcpy (target->Country, source.Country);
	return 0;
};

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem)
{
	fscanf (from, "%s, %s, %s, %s, %s", Elem->ICAO, Elem->IATA, Elem->City, Elem->Name, Elem->Country);
	return 0;
};

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem)
{
	fprintf (to, "ICAO code is %s.\nIATA code is %s.\nCity is %s.\nName is %s.\nCountry is %s.\n", Elem.ICAO, Elem.IATA, Elem.City, Elem.Name, Elem.Country);
	return 0;
};

