//Ioanna Zapalidi, 29/03/2015
#ifndef __TAMIAS__ 
#define __TAMIAS__

typedef struct {
	unsigned int TimeBusy;
	unsigned int TimeInactive;
	unsigned int ArithmoPelaton;
	unsigned int enapomenonXronos;
} TTamias;

void TamiasDimiourgia(TTamias *tamias);
void TamiasNewCustomer(TTamias *tamias);
void TamiasSetXrono(TTamias *tamias, int Duration);
void TamiasNoWork(TTamias *tamias);
void TamiasBusy(TTamias *tamias);
int TamiasFree(TTamias tamias);
int TamiasGetArithmosPelatwn(TTamias *tamias);
int TamiasGetEnapomenonXronos(TTamias *tamias);
int TamiasGetInactiveXronos(TTamias *tamias);
int TamiasGetBusyXronos(TTamias *tamias);

#endif
