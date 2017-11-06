//Ioanna Zapalidi, 29/03/2015
#include "tamias.h"

void TamiasDimiourgia(TTamias *tamias) //arxikopoiei melh struct Tamia
{
	tamias->TimeBusy=0;
	tamias->TimeInactive=0;
	tamias->ArithmoPelaton=0;
	tamias->enapomenonXronos=0;
	return;
};

void TamiasNewCustomer(TTamias *tamias) //metritis pelatwn ++ & +1 lepto apasxolhshs
{
	tamias->ArithmoPelaton++;
	tamias->TimeBusy++;
	return;
};

void TamiasSetXrono(TTamias *tamias, int Duration) //arxikopoiei enapomeinanta xrono basei duration given
{
	tamias->enapomenonXronos=Duration;
	return;
};

void TamiasNoWork(TTamias *tamias) //time inactive ++
{
	tamias->TimeInactive++;
	return;
};

void TamiasBusy(TTamias *tamias) //time busy ++
{
	tamias->TimeBusy++;
	tamias->enapomenonXronos--;
	return;
};

int TamiasFree(TTamias tamias) //elegxei an dia8esimos
{
	return !(tamias.enapomenonXronos); //0!=1 => free, else not free//
};

int TamiasGetArithmosPelatwn(TTamias *tamias) //epistr ari8mo pelatwn
{
	return tamias->ArithmoPelaton;
}

int TamiasGetEnapomenonXronos(TTamias *tamias) //epistr enap xrono
{
	return tamias->enapomenonXronos;
};

int TamiasGetInactiveXronos(TTamias *tamias) //epistr xrono adraneias
{
	return tamias->TimeInactive;
};
int TamiasGetBusyXronos(TTamias *tamias) //epistr xrono apasxolhshs
{
	return tamias->TimeBusy;
};
