#include <stdio.h>
#include <stdlib.h>

typedef struct dugum {
	
	struct dugum *next;
	
	struct dugum *prev;
	
	int data;
	
}cift_bagli_liste;

cift_bagli_liste *root = NULL;

cift_bagli_liste *ilk_dugum = NULL;


cift_bagli_liste* olustur(int veri) {
	
	cift_bagli_liste *yeni_dugum = (cift_bagli_liste*)malloc(sizeof(cift_bagli_liste));
	
	yeni_dugum->data = veri;
	
	yeni_dugum->next = NULL;
	
	yeni_dugum->prev = NULL;
	
	
}

int dugum_sayisi(cift_bagli_liste* baslama) {
	
	int adet = 0;
	
	root = baslama;
	
	while(root != NULL) {
		
		adet++;
		
		root = root->next;
		
		
	}
	
	return adet;
	
	
}


void listele(cift_bagli_liste* baslama, char mesaj[]){

	root = baslama;
	
	while(root != NULL) {
		
		printf("%d\n", root->data);
		
		if(!strcmp(mesaj, "geri")) 
			
			root = root->prev;
			
		
		else 
			
			root = root->next;
				
	}
	

}

void aramak(cift_bagli_liste* baslama, int veri) {
	
	root = baslama;
	
	while(root != NULL) {
		
		if(root->data == veri) {
			
			printf("Aranan eleman bulundu\n");
			
			return;
		}
	
			root = root->next;
	
		
	}
	
	printf("Aranan eleman bulunamadi\n");
	
	
	
}

void bastan_sil() {
	
	
	
	if(ilk_dugum == NULL) {
		
		printf("Silinecek dugum bulunamamaktadir\n");
		
	}
	
	else {
		
		cift_bagli_liste *gecici_dugum = ilk_dugum->next;
		
		gecici_dugum->prev = NULL;
		
		free(ilk_dugum);
		
		ilk_dugum = gecici_dugum;
		
		
	}
	
	
	
}






int main() {
	
	cift_bagli_liste *ilk_dugum = (cift_bagli_liste*)malloc(sizeof(cift_bagli_liste));
	
	cift_bagli_liste *ikinci_dugum = (cift_bagli_liste*)malloc(sizeof(cift_bagli_liste));
	
	cift_bagli_liste *ucuncu_dugum = olustur(25);
	
	ilk_dugum->data = 1;
	
	ikinci_dugum->data = 2;
	
	ilk_dugum->next = ikinci_dugum;
	
	ikinci_dugum->next = ucuncu_dugum;
	
	ucuncu_dugum->next = NULL;
	
	ilk_dugum->prev = NULL;
	
	ikinci_dugum->prev = ilk_dugum;
	
	ucuncu_dugum->prev = ikinci_dugum;
	
	bastan_sil();
	
	listele(ilk_dugum, "ileri");
	

	
	return 0;
}
