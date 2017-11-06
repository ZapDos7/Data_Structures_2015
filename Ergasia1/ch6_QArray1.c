/*************************************************************************
Αρχείo Υλoπoίησης	: QArray.c
Συγγραφέας			: Y. Cotronis
Σκoπός				: Υλoπoίηση με πίνακα Αφηρημένoυ Τύπoυ Δεδoμένων, Ουρά
Αναθεώρηση			:  Ioanna Zapalidi, 29/03/2015
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ch6_QArray1.h"

/*oρισμός συναρτήσεων*/

void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->counter = 0;
}

int OuraKeni(TOuras oura)
{
	return ( !oura.counter );
}

int OuraGemati(TOuras oura) /* OXI sthn diepafi-edv bohthitikh */
{
	return (oura.counter==PLITHOS);
}

int OuraProsthesi(TOuras *oura, TPelatis stoixeio)
{
	if (OuraGemati(*oura))
		return 0;
	else
	{
		Pelatis_setValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction of = for any type */
		oura->piso = ( oura->piso + 1 )% PLITHOS;
		oura->counter++;
	}
	return 1;
}

int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio)
{
	if (OuraKeni(*oura))
		return 0;
	else
	{
		Pelatis_setValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction of = for any type */
		oura->embros = ( oura->embros + 1 )% PLITHOS;
		oura->counter--;
	}
	return 1;
}

int SizeOuras (TOuras oura)
{
	return oura.counter;
}
