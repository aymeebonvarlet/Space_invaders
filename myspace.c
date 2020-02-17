
#include "vt100.h"

/* dans ce programme on va initialiser les positions des vaisseaux un à un afin de leurs rentrée des coordonnées d'origines et pouvoir els modifier
 au cours du temps grâce aux pointeurs. On choisit de mettre 10 gros monstres de taille 9, 14 petits monstres de taille 5. On va aussi créer une fonction
 delete qui permettrait d'effacer le vaisseau d'espace utiliser par le vaisseau précédent écrit*/





void myspace(uint8_t x , uint8_t pas){// = pernet de modifier la valeur en x du myspace
	if (new_x == 0){ //attention au contour
		new_x=1;
	}
	if (new_x == 80){
		new_x = 79;
	}
	myspace.tab[x] =  myspace.tab[x] + pas ;
	vt100_move( myspace.tab[x] , myspace.tab[1] );
	serial_puts("(-O-)");
}

void delete_myspace(){ // permet de supprimer l’ancien myspace
	vt100_move( myspace.tab[x] -1 , myspace.tab[1] );
	serial_puts("     ");
}

void init_myspace(){

	myspace.tab[0]= (VT100_SCREEN_XMIN+VT100_SCREEN_XMAX)/2 ;
	myspace.tab[1]= VT100_SCREEN_YMAX - 4 ;
	vt100_move( myspace.tab[0] , myspace.tab[1] );
	serial_puts("(-O-)");

}

