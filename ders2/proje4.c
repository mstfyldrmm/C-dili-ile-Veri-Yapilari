#include <stdio.h>
#include <stdlib.h>

/* istenilen elemani aramak*/

typedef struct node{
	
	struct node *sonraki;
	
	struct node *onceki;
	
	int veri;
	
	
}couple_node;

void eleman_ara(couple_node *baslangic_dugumu, int aranan) {
	
	couple_node *temp = (couple_node *)malloc(sizeof(struct node));
	
	temp = baslangic_dugumu;
	
	while(temp != NULL) {
		
		if(temp->veri == aranan) {
			
			printf("Aranan eleman bulundu : %d", temp->veri);
			
			return;
			
		}
		
		temp = temp->sonraki;
		
		
	}
	
	printf("Aranan eleman listede bulunamadi");
	
	
}



int main(int argc, char *argv[]) {
	
	
	couple_node *dugum1 = (couple_node *)malloc(sizeof(struct node));
	
	couple_node *dugum2 = (couple_node *)malloc(sizeof(struct node));
	
	couple_node *dugum3 = (couple_node *)malloc(sizeof(struct node));
	
	dugum1->sonraki = dugum2;
	
	dugum2->sonraki = dugum3;
	
	dugum1->onceki = NULL;
	
	dugum2->onceki = dugum1;
	
	dugum3->onceki = dugum2;
	
	dugum3->sonraki = NULL;
	
	dugum1->veri = 25;
	
	dugum2->veri = 50;
	
	dugum3->veri = 75;
	
	eleman_ara(dugum1, 25);
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
