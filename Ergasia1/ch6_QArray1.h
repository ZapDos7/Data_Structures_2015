/**********************************************+**************************
Αρχείο Επικεφαλίδας	: QArray.h
Συγγραφέας				: Y. Cotronis 14/03/2015
Σκοπός					: Υλοποίηση με πίνακα Αφηρημένου Τύπου Δεδομένων Ουρά
Αναθεώρηση				:  Ioanna Zapalidi, 29/03/2015
**************************************************************************/
#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"

/*δηλώσεις τύπων*/

#define PLITHOS 1000

typedef struct {
	int embros;		/*θέση του πρώτου στοιχείου της ουράς*/
	int piso;		/*θέση του τελευταίου στοιχείου της ουράς*/
	TPelatis pinakas[PLITHOS];	/*ο πίνακας στοιχείων*/
	int counter;
} TOuras;	   /*ο τύπος της ουράς*/

/*δηλώσεις συναρτήσεων*/

/*δημιουργία*/  
void OuraDimiourgia(TOuras *oura);

/*Πράξεις έλεγχου*/
int	OuraKeni	(TOuras oura);

/*Πράξεις προσθεσης/απομάκρυνσης*/
int OuraProsthesi	(TOuras *oura, TPelatis stoixeio);
int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio);

int SizeOuras (TOuras oura);

#endif /*#ifndef __CH2_QARRAY__ */
