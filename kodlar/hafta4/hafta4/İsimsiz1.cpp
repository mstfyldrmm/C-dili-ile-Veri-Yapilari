#include <stdio.h>
#include <stdlib.h>

/* Dairesel ba�li liste */

typedef struct dugum{
	
	struct dugum *next;
	
	int data;
	
	
}dairesel_bagli_liste;

dairesel_bagli_liste *ilk_dugum = NULL;

dairesel_bagli_liste *temp = NULL;

dairesel_bagli_liste *iter = NULL;

void bastir(dairesel_bagli_liste *ilk) {
	
	temp = ilk;
	
	do {
		
		printf("%d\n", temp->data);
		
		temp = temp->next;
		
		
	}while(temp != ilk);
	
}

void basa_ekle(int veri) {
	
	dairesel_bagli_liste *eklenecek = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
	
	eklenecek->data;
	
	if(ilk_dugum == NULL) {
		
		dairesel_bagli_liste *temp = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
		
		temp->data = veri;
		
		ilk_dugum = temp;
		
		temp->next = ilk_dugum;
		
	}
	
	else {
		
		temp = ilk_dugum;
		
		while(temp->next != ilk_dugum) {
			
			temp = temp -> next;
		}
		
		temp->next = eklenecek;
		
		eklenecek->next = ilk_dugum;
		
		ilk_dugum = eklenecek;
		
		
		
		
	}
	
}

void sona_ekle(int x) {
	
	dairesel_bagli_liste *sona_eklenecek = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
	
	sona_eklenecek->data = x;
	
	if(ilk_dugum == NULL) {
		
		ilk_dugum = sona_eklenecek;
		
	}
	
	else {
		
		temp = ilk_dugum;
	
	while(temp->next != ilk_dugum) {
		
		temp = temp->next;
		
		
	}
	
	temp->next = sona_eklenecek;
	
	sona_eklenecek->next = ilk_dugum;
	
		
	}
	
	
}

void bastan_sil();
	
	






int main(int argc, char *argv[]) {
	
	dairesel_bagli_liste *ilk_dugum = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
	
	dairesel_bagli_liste *ikinci_dugum = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
	
	dairesel_bagli_liste *ucuncu_dugum = (dairesel_bagli_liste *)malloc(sizeof(dairesel_bagli_liste));
	
	ilk_dugum->data = 1;
	
	ikinci_dugum->data = 2;
	
	ucuncu_dugum->data = 3;
	
	ilk_dugum->next = ikinci_dugum;
	
	ikinci_dugum->next = ucuncu_dugum;
	
	ucuncu_dugum->next = ilk_dugum;
	
	bastir(ilk_dugum);
	
	bastan_sil();

	bastir(ilk_dugum);

	
	
	
	
	return 0;
}

void bastan_sil() {	
	
	if(ilk_dugum == NULL) {
		
		printf("Silinecek dugum bulunmamaktadir\n");
		
	}
	
	else {
		
		while(temp->next != ilk_dugum) {
			
			temp = temp->next;
			
		}
		
		iter = ilk_dugum->next;
		
		free(ilk_dugum);
		
		temp->next = iter;
		
		ilk_dugum = iter;
		
		
		
	}
	
	
	
	
	
	
}















