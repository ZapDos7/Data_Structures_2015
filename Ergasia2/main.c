//Zapalidi Ioanna, AM:1115201400044

#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"
#include "TyposStoixeiouMenu.h"



int main(int argc, char *argv[]) {
	InfoMenuPtr 	FoodMenu=NULL,
					CafeMenu=NULL;
	unsigned int	s;
	InfoMenuPtr		Info;
	char			c[256];
	
	printf("Hello! Welcome to MenuCreator ver 1.1.\n");
	printf("Please select which of the following actions you wish to execute now:\n");
	printf("01. Create a Menu\n02. Check if the category is vacant\n03. Create node for the menu\n04. Print selected category/plate and price\n");
	printf("05. Change category/plate and price\n06. Go to next node\n07. Go to previousnode\n08. Exchange with the next node\n");
	printf("09. Exchange with previous node\n10. Insert Category\n11. Move Up\n12. Move Down\n13.Print selected category\n14. Delete Menu\n15. Delete All\n16. Cut\n17. Paste\n18. Destroy\n");
	
	do{
		scanf ("%d", &s);	
		switch(s){
			case 1  : 	printf("Please type wanted name:\n");
						fgets(c, 255, stdin);
						c[255] = 0;
						MenuCreate (Info, c);
						printf("Next choice?\n");
			case 2  :	if (MenuVacant(Info) == 1) printf("This is not an empty category.\n");
						else printf("This is an empty category.\n");
						printf("Next choice?\n");
			case 3  :	MenuInsertNode (Info);
						printf("Next choice?\n");
			case 4  :	MenuPrintData(Info);
						printf("Next choice?\n");
			case 5  :	MenuChangeData(Info);
						printf("Next choice?\n");
			case 6  :	MenuNext(Info);
						printf("Next choice?\n");
			case 7  :	MenuPrev(Info);
						printf("Next choice?\n");
			case 8  :	MenuMoveAfter(Info);
						printf("Next choice?\n");
			case 9  :	MenuMoveBefore(Info);
						printf("Next choice?\n");
			case 10 :	MenuInsertCateg(Info);
						printf("Next choice?\n");
			case 11 :	MenuMoveUp(Info);
						printf("Next choice?\n");
			case 12 :	MenuMoveDown(Info);
						printf("Next choice?\n");
			case 13 :	MenuPrintCateg(Info);
						printf("Next choice?\n");
			case 14 :	MenuCybermen(Info);			//Doctor?
						printf("Next choice?\n");
			case 15 :	MenuCybermenAll(Info);		//Doctor Who?
						printf("Next choice?\n");
			case 16 :	MenuCut(Info);
						printf("Next choice?\n");
			case 17 :	MenuPaste(Info);
						printf("Next choice?\n");
			case 18 :	MenuHulk(Info);
						printf("Next choice?\n");
			default :	printf("Please, print a valid option. We're doing businness here, you know!\n");
		}
	} while (s>=1 && s<=18);
	return 0;
}
