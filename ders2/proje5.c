#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* cift yonlu bagli listede bastan silmek, basa eklemek ve sondan silmek ve sona dugum eklemek */

struct dugum {
	
	struct dugum *next;
	
	struct dugum *prev;
	
	int deger;
	
};

typedef struct dugum node;

node *start = NULL;

void listele(node *baslangic_dugumu, char mesaj[]) {
	
	node *temp = (node*)malloc(sizeof(node));
	
	temp = baslangic_dugumu;
	
	while(temp != NULL) {
		
	printf("%d\n", temp->deger);
		
	if(!strcmp(mesaj, "geri")) 
	
		temp = temp->prev;
	
	else 
		
		temp = temp->next;
}
	
}




void basa_ekle( int veri) {

	node *basa_eklenecek = (node *)malloc(sizeof(node));
	
	basa_eklenecek->deger = veri;

	start->next = NULL;
	
	start->prev = NULL;
	
	if(start == NULL) {
		
		start = basa_eklenecek;
	
	
	}
		
	else {
		
		start->prev = basa_eklenecek;
		
		basa_eklenecek->next = start;
		
		start = basa_eklenecek;
	
		
}
		

	
}




int main() {
	
	node *dugum1;
	
	dugum1 = (node*)malloc(sizeof(node));
	
	node *dugum2;
	
	dugum2 = (node*)malloc(sizeof(node));
	
	node *dugum3 = (node*)malloc(sizeof(node));
	
	dugum1->next = dugum2;
	
	dugum2->next = dugum3;
	
	dugum2->prev = dugum1;
	
	dugum3->prev = dugum2;
	
	dugum1->prev = NULL;
	
	dugum3->next = NULL;
	
	dugum1->deger = 1;
	
	dugum2->deger = 2;
	
	dugum3->deger = 3;
	
	
	
	listele(dugum3, "geri");
	
	basa_ekle(15);
	
	listele(dugum1, "ileri");
	
	
	return 0;
}
