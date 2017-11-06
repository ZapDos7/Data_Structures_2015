/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 14/03/2015
Skopos				: Ylopoihsh ouras prosomoiwshs
Αναθεώρηση			: I.Zapalidi  20/03/2015
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch6_QArray1.h"
#include "TStoixeiouOuras.h"
#include "tamias.h"

int main(void)
{	TOuras      	oura;					 	 /*oura pelatwn*/
	float			pithanotita_afiksis; 	     /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis_MAX;   	 /*megistos xronos e3yphrethshs enos pelath*/ 
	unsigned int	a;
	
	unsigned int	xronos;						 /*roloi prosomoiwshs*/
	unsigned int	enapomenon_xronos;			 /*xronos gia to telos e3yphrethshs enos pelath*/
	unsigned int	arithmos_pelaton; 			 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis;			 /*synolikos xronos anamonhs*/
	TPelatis		Pelatis;		 		     /* o pelaths sthn oyra*/
	float			mesos_xronos;				 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int				tamiasInactive=0;
	time_t			t;    						 /* orismeno sto time.h */
	
	unsigned int	closing_time;		/* closing time duuuuh */
	unsigned int	extra_minutes=0;
	TTamias			tamias;

	printf("Dwste to xrono pou kleinei h trapeza (0<=), pi8anothta afikshs (0 ws 1) kai megisto xrono e3yphrethshs (>=1) )\n");
	scanf("%u %f %u",&closing_time,&pithanotita_afiksis,&xronos_eksipiretisis_MAX);
	getchar();
	printf("\nH trapeza kleinei meta apo %4u lepta kai de dexetai allous pelates!\n",closing_time);
	printf("H pi8anothta afikshs pelath se ena lepto einai: %4.2f.\n",pithanotita_afiksis);
	printf("O xronos e3yphrethshs enos pelath einai to megisto %d lepta.\n",xronos_eksipiretisis_MAX);

	OuraDimiourgia(&oura);
	xronos = 0;
	enapomenon_xronos = 0;
	arithmos_pelaton = 0;
	xronos_anamonis = 0;
	srand(time(&t));
	
	TamiasDimiourgia(&tamias); /* create struct tamias */

	while ( (xronos<closing_time) || (!OuraKeni(oura)) || enapomenon_xronos )	/* an ekleise h bank */
	{	/* Pelatis */								/* h uparxei pelatis */
		if (xronos<closing_time)
		{
			randomAfixi = (float)rand()/(float)RAND_MAX; 				/* h ekleise h trapeza alla o tamias exei akoma douleia!*/
			
			if ( randomAfixi < pithanotita_afiksis ){
				arithmos_pelaton++;
				a=rand()%xronos_eksipiretisis_MAX+1;
				PelatisSetXronoEksipiretisis(&Pelatis , a);
				PelatisSetXronoEisodou(&Pelatis, xronos);
				if (!OuraProsthesi(&oura, Pelatis)){
     	            printf("\nH oyra einai mikrh! H prosomoivsh stamataei! \n");
      	            getchar();
      	            return 0;
      		  		};
    			};
    	};

	if (xronos>=closing_time) extra_minutes++;    	

    		/* Tamias */
    	
		if (TamiasFree(tamias))			/*eley8eros tamias*/
			if (!OuraKeni(oura))			/*yparxei pelaths*/
			{	OuraApomakrynsh(&oura,&Pelatis);		/*phgainei sto tameio*/
				TamiasNewCustomer(&tamias);
				TamiasBusy(&tamias);
				TamiasSetXrono(&tamias, Pelatis.XronosEksipiretisis);	
			}
			else TamiasNoWork(&tamias);
		else 
		{
			TamiasBusy(&tamias);
			enapomenon_xronos = TamiasGetEnapomenonXronos(&tamias);		/*o tamias apasxolhmenos me pelath */
			xronos_anamonis++;
		}
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 lepto*/
	}

	if (TamiasGetArithmosPelatwn(&tamias) == 0) mesos_xronos = 0.0;
	else mesos_xronos = ((float)xronos_anamonis)/((float)TamiasGetArithmosPelatwn(&tamias));

	printf("\nEksyphreth8hkan %d pelates.\n",TamiasGetArithmosPelatwn(&tamias));
	printf("O mesos xronos anamonhs htan %4.2f lepta.\n",mesos_xronos);
	printf("O tamias htan adranhs gia %d lepta\n", TamiasGetInactiveXronos(&tamias));
	printf("Telikos pragmatikos xronos leitourgias = %u lepta.\nExtra minutes needed = %u minutes.\n", closing_time+extra_minutes, extra_minutes);
	printf("To megethos ths ouras einai %d.\n", SizeOuras(oura) );
	getchar();
    
	return 0;
}
