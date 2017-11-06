//Zapalidi Ioanna, AM:1115201400044

#ifndef __MENU__
#define __MENU__

#include "TyposStoixeiouMenu.h"

typedef struct InfoMenu *InfoMenuPtr; // Ο Τύπος δείκτη σε Πληροφοριακό Κόμβο Μενού

///////////
//functions
///////////
void MenuCreate (InfoMenuPtr Info, char* name); //creates InfoMenu
int MenuVacant (InfoMenuPtr Info); //1=>current se kefalh xwris next node, else 0 dld mh kenh 
void MenuInsertNode (InfoMenuPtr Info); //new node after current node, update prev&next, down=null, up=up curr, curr = new
int MenuPrintData (InfoMenuPtr Info); //emfanise node data curr (category or plate&price, ERROR <=>curr kefalh
int MenuChangeData (InfoMenuPtr Info); //allagh sting (&timh if plate) curr node, ERROR <=> curr kefalh
void MenuNext (InfoMenuPtr Info);//curr -> next, if last then STAY not NULL!
void MenuPrev (InfoMenuPtr Info);//curr -> prev, if first then STAY not NULL!
int MenuMoveAfter (InfoMenuPtr Info); //exchange curr me next & possible subcateg. curr remains. if no next ERROR
int MenuMoveBefore (InfoMenuPtr Info); //exchange curr me prev NOT KEFALH & ossible subcateg. curr remains. if no prev ERROR
int MenuInsertCateg (InfoMenuPtr Info);//insert node kefalh subcateg sto Down tou Curr, if kefalh ERROR, up->curr, down/prev/next=NULL, curr remain to NODE
void MenuMoveUp (InfoMenuPtr Info);//curr = KEFALH anwkathgorias else stay
void MenuMoveDown (InfoMenuPtr Info);//curr = KEFALH subcateg = DOWN, else stay
void MenuPrintCateg (InfoMenuPtr Info);//curr se kombo kefalh kai print nodes & subcateg, oxi kombous kefales
void MenuCybermen (InfoMenuPtr Info);//deletes node after curr (PREV&NEXT, curr stays, if node=subcat DONT, if no next DONT
void MenuCybermenAll (InfoMenuPtr Info);//delete all subcateg apo DOWN tou CURR * their subs, curr stays, OI KEFALES EXOUN PREV NULL!!!
void MenuCut (InfoMenuPtr Info);//update cuttopaste* kai shoo node, curr -> prev
void MenuPaste (InfoMenuPtr Info);//paste cuttopaste* apo curr sth lista prev-next, curr goes to it
void MenuHulk (InfoMenuPtr Info);//rm -rf... huuulk smaaash!!!
//Bonus


#endif
