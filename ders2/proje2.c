#include <stdio.h>
#include <stdlib.h>

/*çift yönlü bağlı listede dugum olustur fonksiyonu ve yazdir fonksiyonu */

struct dugum {
	
	struct dugum *next;
	
	struct dugum *prev;
	
	int deger;
	
};

typedef struct dugum node;

node* dugum_olustur(int veri) {
	
	node *yeni_dugum = (node *)malloc(sizeof(node));
	
	yeni_dugum -> deger = veri;
	
	yeni_dugum->next = NULL;
	
	yeni_dugum->prev = NULL;
	
	return yeni_dugum;
	
}

void bastir(node *baslama_dugumu) {
	
	node *temp = (node *)malloc(sizeof(node));
	
	temp = baslama_dugumu;
	
	while(temp != NULL) {
		
		printf("%d\n", temp->deger);
		
		temp = temp->next;
	}
	
}


int main() {
	
	
	node *dugum1;
	
	dugum1 = (node*)malloc(sizeof(node));
	
	dugum1->deger = 1;
	
	dugum1->next = NULL;
	
	dugum1->prev = NULL;

	node *dugum3 = dugum_olustur(75);
	
	dugum1->next = dugum3;
	
	bastir(dugum1);
	
	
	
	
	
	return 0;
}
