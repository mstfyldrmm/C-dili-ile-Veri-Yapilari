#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* çift bağlı listelerde ileri-geri gitme islemi ve dugum sayisi bulma */

typedef struct dugum{
	
	struct dugum *next;
	
	struct dugum *prev;
	
	int data;
	
	
}cift_bagli_liste;

cift_bagli_liste* dugum_olustur(int veri) {
	
	cift_bagli_liste *yeni_dugum;
	
	yeni_dugum = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	yeni_dugum->data = veri;
	
	yeni_dugum->next = NULL;
	
	yeni_dugum->prev = NULL;
	
	return yeni_dugum;
	
}

void yazdir(cift_bagli_liste *baslama_dugumu, char mesaj[]) {
	
	cift_bagli_liste *temp;
	
	temp = baslama_dugumu;
	
	while(temp != NULL) {
		
		printf("%d\n", temp->data);
		
		if(!strcmp(mesaj, "geri")) 
			
			temp = temp->prev;
			
		
		else 
			
			temp = temp->next;
				
	}
	
	
	
}

int dugum_sayisi(cift_bagli_liste *start_node, char mesaj[]) {
	
	int adet = 0;
	
	cift_bagli_liste *temp = start_node;

		if(!strcmp(mesaj, "geri")) {
			
			if(temp == NULL) {
				
				return 0;
				
			}
			
			else {
				
				while( temp != NULL) {
					
					adet += 1;
					
					temp = temp->prev;
					
				}
				
				
			}
			
			
			
		}
		
		else {
			
			if(temp == NULL) {
				
				return 0;
				
			}
			
			else {
				
				while(temp != NULL) {
					
					adet += 1;
					
					temp = temp->next;
					
				}
				
			}
			
		}
		
		return adet;
		
	}
	
	
	
	
	
	





int main() {
	
	cift_bagli_liste *dugum1;
	
	dugum1 = (cift_bagli_liste *)malloc(sizeof(struct dugum)); //sizeof(cift_bagli_liste) ile aynı işlevi görür.
	
	cift_bagli_liste *dugum2 = dugum_olustur(50);
	
	cift_bagli_liste *dugum3 = dugum_olustur(75);
	
	dugum1->data = 25;
	
	dugum2->data = 50;
	
	dugum3->data = 75;
	
	dugum1->next = dugum2;
	
	dugum2->next = dugum3;
	
	dugum2->prev = dugum1;
	
	dugum3->prev = dugum2;
	
	cift_bagli_liste *temp = (cift_bagli_liste *)malloc(sizeof(struct dugum));

	temp = dugum1;
	
	temp->data = 25;

	printf("Dugum1 den sonra %d kadar dugum vardir",dugum_sayisi(dugum3, "geri"));
	
	
	
	
	
	return 0;
}
