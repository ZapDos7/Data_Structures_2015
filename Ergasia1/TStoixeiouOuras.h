/**********************************************+**************************
Αρχείο Επικεφαλίδας	: TStoixeioOyras.h
Συγγραφέας				: Y. Cotronis 14/03/2015
Σκοπός					: Diepafi typou stoixeiou Pelatis ths oyras
Αναθεώρηση				:  <Ioanna Zapalidi, 29/03/2015
**************************************************************************/
#ifndef __TStoixeioOuras__ 
#define __TStoixeioOuras__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis; /* xronos pou apaiteitai gia thn eksuphrethsh ka8e pelath */
} TPelatis;

void PelatisSetXronoEisodou(TPelatis *stoixeioPtr, int xronos);
int PelatisGetXronoEisodou(TPelatis *stoixeioPtr);

void Pelatis_setValue(TPelatis *stoixeioPtr, TPelatis testdata);

void Pelatis_printValue(TPelatis testdata);
int  Pelatis_readValue(TPelatis *testdata);

void PelatisSetXronoEksipiretisis(TPelatis *stoixeioPtr, int duration);
int PelatisGetXronoEksipiretisis(TPelatis *stoixeioPtr);

#endif
