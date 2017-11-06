//Zapalidi Ioanna, AM:1115201400044

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "TyposStoixeiouMenu.h"

typedef struct MenuNode *MenuNodePtr; // Ο τύπος δείκτη σε κόμβο

struct InfoMenu {
	char* 	  Name; 	   // το όνομα του εστιατορίου/kafeterias
	MenuNodePtr Start;	   // Δείκτης στον πρώτο κόμβο του πρώτου επιπέδου
	MenuNodePtr Current;   // Δείκτης στον τρέχοντα κόμβο
	MenuNodePtr CutToPaste;// Δείκτης στον κόμβο προς μεταφορά σε άλλη θέση
};

struct MenuNode {
	MenuNodePtr Prev, Next, Up, Down;
	TStoixeiouMenu Data;
};
/////////////////
//functions
////////////////

//1
void MenuCreate (InfoMenuPtr Info, char* Name){
	Info = malloc (sizeof(InfoMenuPtr));		 //allocate space for Info
	Info->Start = malloc (sizeof(MenuNodePtr)); //kanonise thn poreia sou edw ekanes malloc e!!!!!!!
	Info->Current = Info->Start;			 //curr & start -> same
	Info->CutToPaste = NULL;				 //null ctp
	Info->Name = malloc (sizeof(Name));		 //*char needs space too
	strcpy (Info->Current->Data.Name, Name);				 //let us name this space now
	return;
};

//2
int MenuVacant (InfoMenuPtr Info) {
	return ((Info->Current->Prev == NULL) && (Info->Current->Next == NULL)); //prev null dld exoume kefalh, exoume kai 8ewrhtika toulax kathgoria kai next gia kenh
};

//3
void MenuInsertNode (InfoMenuPtr Info){
	MenuNodePtr Temp;								 //temp pointer to MenuNode gia na kanw douleia m
	Info->Current->Next = malloc (sizeof(MenuNodePtr)); //allocate space for new node
	Temp = Info->Current;							 //temp gets a point to excist <3
	Info->Current = Info->Current->Next; 			 //current goes to new node :D
	Info->Current->Prev = Temp;						 //o prev tou new node htan o 1os
	Info->Current->Down = NULL;						 //kai o down tou neou kenos
	Info->Current->Up = Temp->Up;					 //O up deixnei ekei pou htan prin o curr
	Info->Current->Next = NULL;						 //Akoma dn uparxei epomenos node
};

//4
int MenuPrintData (InfoMenuPtr Info){
	if (Info->Current->Prev == NULL) return 1; 												//error if kefalh
	else {
		printf("Current point at \"%s\".\n", Info->Current->Data.Name);					//onoma
		if (Info->Current->Data.Category == 1) printf("It is a category.\n");				//kathgoria h piato
		else printf("It is a plate, and it costs %f.\n", Info->Current->Data.Price);		//piato kai timh
		return 0;
	}
};

//5
int MenuChangeData (InfoMenuPtr Info){
	if (Info->Current->Prev == NULL) return 2; 		//error an o curr se kefalh
	else {
		printf("Type wanted values for: Name & Price of Plate or Name for Category.\n");
		fgets (Info->Current->Data.Name, 21, stdin);
		//getchar();
		scanf("%f", Info->Current->Data.Price);
	//	getchar();
		return 0;
	}
};

//6
void MenuNext (InfoMenuPtr Info){
	if (Info->Current->Next != NULL){			//o epomenos uparxei dld dn einai NULL
		Info->Current = Info->Current->Next;	//Pame ston next alliws tpt
	}
};

//7
void MenuPrev (InfoMenuPtr Info){
	if (Info->Current->Prev != NULL){			//o prohgoumenos uparxei dld dn einai NULL
		Info->Current = Info->Current->Prev;	//Pame ston prev alliws tpt
	}
};

//8 
int MenuMoveAfter (InfoMenuPtr Info){
	MenuNodePtr Temp;								//temp for else
	if (Info->Current->Next == NULL) return 3;		//den uparxei epomenos
	else {											//uparxei epomenos:
		Temp = Info->Current->Next;					//o temp boh8aei g t epomeno node
		Info->Current->Prev = Temp;					//o prev tou curr einai o temp
		Temp->Next->Prev = Info->Current;			//edw ekana papatza?
		Info->Current->Next = Temp->Next;			//o epomenos tou curr gnt o prwhn next tou temp
		Temp->Next = Info->Current;					//o prev tou temp einai o curr
		Info->Current->Prev->Next = Temp;			//o prwhn prev tou curr exei ws next ton temp
		Temp->Prev = Info->Current->Prev;			//antallagh prev
	};
};

//9
int MenuMoveBefore (InfoMenuPtr Info){
	MenuNodePtr Temp;
	if (Info->Current->Prev == NULL) return 4;	//den uparxei previous
	else{
		Temp = Info->Current->Prev;				//O temp einai o prev tou current ok?
		Temp->Prev->Next = Info->Current;		//o 1os sth seira exei next ton current
		Info->Current->Next->Prev = Temp;		//o 4os exei prev ton temp
		Info->Current->Prev = Temp->Prev;		//antallagh prev meta3u curr kai temp
		Info->Current->Next = Temp;				//o curr exei next ton temp
		Temp->Prev = Info->Current;				//o temp exei prev ton curr <3
		Temp->Next = Info->Current->Prev;		//o next tou temp einai o 4os sth seira
	};
};

//10
int MenuInsertCateg (InfoMenuPtr Info){
	if (Info->Current->Prev == NULL) return 5;		//ama kefalh sfalma
	else{
		Info->Current->Down = malloc(sizeof(MenuNodePtr));
		Info->Current->Down->Up = Info->Current;	//dei3e ston curr, paidi m
		Info->Current->Down->Down = NULL;
		Info->Current->Down->Prev = NULL;
		Info->Current->Down->Next = NULL;
		return 0;
	};
};

//11
void MenuMoveUp (InfoMenuPtr Info){
	if (Info->Current->Up != NULL) Info->Current = Info->Current->Up;
};

//12
void MenuMoveDown (InfoMenuPtr Info){
	if (Info->Current->Down != NULL) Info->Current = Info->Current->Down;
};

//13
void MenuPrintCateg (InfoMenuPtr Info){
	if (Info->Current->Prev == NULL){
		while (Info->Current->Next != NULL){
			TSPrintValue (stdout, Info->Current->Data);
			while (Info->Current->Down != NULL){
				TSPrintValue (stdout, Info->Current->Data);
				printf("\n");
				Info->Current = Info->Current->Down;
			};
			printf("\n");
			Info->Current = Info->Current->Next;
		};
	}
	else ;
};

//14
void MenuCybermen (InfoMenuPtr Info){
	if (Info->Current->Down != NULL) ;
	else if (Info->Current->Next == NULL) ;
	else free (Info->Current->Next);
};

//15
void MenuCybermenAll (InfoMenuPtr Info){
	while (Info->Current->Down != NULL){
		;
	};
};

//16
void MenuCut (InfoMenuPtr Info){
	MenuNodePtr Temp;
	Temp = Info->Current;
	Info->CutToPaste = Info->Current;
	Temp = Info->Current->Prev;
};

//17
void MenuPaste (InfoMenuPtr Info){
	MenuNodePtr Temp;
	Temp = Info->CutToPaste;
	Info->Current->Next = Temp;
	Info->Current = Info->Current->Next;
	Info->CutToPaste = NULL;
};

//18
void MenuHulk (InfoMenuPtr Info){
	;
};

//Bonus

