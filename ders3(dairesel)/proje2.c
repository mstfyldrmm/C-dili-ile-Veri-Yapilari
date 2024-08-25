#include <stdio.h>
#include <stdlib.h>

/* çift yönlü dairesel bağli liste */

typedef struct node {
	
	struct node *prev;
	
	struct node *next;
	
	int data;

}cift_yonlu_dairesel;

cift_yonlu_dairesel *temp = NULL;

cift_yonlu_dairesel *ilk = NULL;

cift_yonlu_dairesel *son = NULL;

void listele() {
	
	temp = ilk;
	
	do {
		
		printf("%d\n", temp->data);
		
		temp = temp->next;
		
		
	}while(temp != ilk);
	
}

void basa_ekle(int sayi) {
	
	cift_yonlu_dairesel *eklenecek = (cift_yonlu_dairesel *)malloc(sizeof(cift_yonlu_dairesel));
	
	eklenecek->data = sayi;
	
	if(ilk == NULL) {
		
		ilk = eklenecek;
		
		ilk->next = ilk;
		
		ilk->prev = ilk;
		
		return;
	}
	
	else {
		
		temp = ilk;
		
		while(temp->next != ilk) {
			
			temp = temp->next;
			
		}
		
		temp->next = eklenecek;
		
		eklenecek->prev = temp;
		
		eklenecek->next = ilk;
		
		ilk = eklenecek;
		
	}
	
	
	
}

void sona_ekle(int c) {
	
	cift_yonlu_dairesel *eklenecek = (cift_yonlu_dairesel *)malloc(sizeof(cift_yonlu_dairesel));
	
	eklenecek->data = c;
	
	
	if(ilk == NULL) {
		
		ilk = eklenecek;
		
		ilk->next = ilk;
		
		ilk->prev = ilk;
		
	}
	
	else {
		
		temp = ilk;
		
		while(temp->next != ilk) {
			
			temp = temp -> next;
			
		}
		
		temp->next = eklenecek;
		
		eklenecek->next = ilk;
		
		ilk->prev = eklenecek;
		
		
	}
	
	
}

void araya_ekleme(cift_yonlu_dairesel *dugum, int veri) {
	
	cift_yonlu_dairesel *eklenecek = (cift_yonlu_dairesel *)malloc(sizeof(cift_yonlu_dairesel));
	
	eklenecek->data = veri;
	
	temp = dugum;
	
	if(temp == NULL) {
		
		ilk = eklenecek;
		
		ilk->next = ilk;
		
		ilk->prev = ilk;
		
	}
	
	else {
		
		temp = ilk;
		
		while(temp->next->data != dugum->data) {
			
			temp->next = son;
			
			temp = ilk;
			
			temp->next = eklenecek;
			
			eklenecek->next = son;
			
			eklenecek->prev = ilk;
				
		}
		
		
		
	}
		
}

void bastan_sil() {
	
	if(ilk == NULL) {
		
		printf("Silinecek dugum bulunamadi");
		
	}
	
	else {
		
		temp = ilk;
		
		while(temp->next != ilk) {
			
			temp = temp->next;
		}
		
		int silinen = temp->next->data;
		
		 son = ilk->next;
		 
		 temp->next = son;
		 
		 son->prev = temp;
		 
		 ilk = son;
		 
		 printf("%d elemani silindi\n", silinen);
	
	}
	
	
}

void sondan_sil() {
	
	if(ilk == NULL) {
		
		printf("Silinecek dugum bulunamadi");
		
		return;
		
	}
	
	else {
		
		temp = ilk;
		
		while(temp->next != ilk) {
			
			temp = temp->next;
			
		}
		
		//temp suan son dugumden onceki dugumu gosteriyor.
		
		int silinen = temp->data;
		
		son = temp->prev;
		
		free(temp);
		
		son->next = ilk;
		
		ilk->prev = son;
		
		printf("Su eleman silindi : %d\n\n", silinen);
		
	}
	
	
	
}


void eleman_ara(int aranan) {
	
	temp = ilk;
	
	while(temp->next != ilk) {
	
		temp = temp->next;
		
		if(temp->data == aranan) {
			
			printf("Eleman listede var");
			
			return;
			
		}
		
	}
	
	printf("Eleman listede bulunamadş");
	
	
	
}


int main(int argc, char *argv[]) {
	
	basa_ekle(25);
	
	basa_ekle(41);
	
	basa_ekle(81);
	
	sona_ekle(1);
	
	listele();
	
	sondan_sil();
	
	eleman_ara(41);
	
	return 0;
}
