#include <stdio.h>
#include <stdlib.h>

typedef struct dugum {
	
	struct dugum *sonraki;
	
	int data;
	
}tek_yonlu;

tek_yonlu *ilk_dugum = NULL;

tek_yonlu *root = NULL;

tek_yonlu *on = NULL;


void listele() {
	
	root = ilk_dugum;
	
	while(root != NULL) {
		
		printf("%d\n", root->data);
		
		root = root -> sonraki;
		
		
	}
	

}

void basa_ekle(int veri) {
	
	tek_yonlu *yeni = (tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	yeni->data = veri;
	
	if(ilk_dugum == NULL) {
	
		yeni = ilk_dugum;
		
	}
	
	else {
		
		root = ilk_dugum;
		
		ilk_dugum = yeni;
		
		ilk_dugum->sonraki = root;
		
	}
	
		
	
}

void sona_ekle(int sayi) {
	
	tek_yonlu *sona_eklenecek = (tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	sona_eklenecek->data = sayi;
	
	sona_eklenecek->sonraki = NULL;

	if(ilk_dugum == NULL) {
		
		ilk_dugum = sona_eklenecek;
		
	}
		
	else {
		
		root = ilk_dugum;
		
		while(root->sonraki != NULL) {
			
			root = root->sonraki;
			
			
		}
		
		root->sonraki = sona_eklenecek;
		
	}
		
	
}

void araya_ekle(int x, int y) {
	
	tek_yonlu *araya_eklenecek = (tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	araya_eklenecek->data = y;
	
	root = ilk_dugum;
	
	while(root->sonraki->data != x) {
		
		root = root->sonraki;
		
	}
	
	tek_yonlu *onune = 	(tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	onune = root->sonraki;
	
	root->sonraki = araya_eklenecek;
	
	araya_eklenecek->sonraki = onune;
}

void bastan_sil() {
	
	if(ilk_dugum == NULL) {
		
		printf("Listede silinecek dugum bulunmamaktadir");
		
		
	}
	
	else {
		
		root = ilk_dugum->sonraki;
		
		free(ilk_dugum);
		
		ilk_dugum = root;
		
	}
	
	
	
}

void sondan_sil() {
	
	root = ilk_dugum;
	
	if(root == NULL) {
		
		printf("Listede silinecek dugum bulunmamaktadýr.");
		
		
	}
	
	else {
		
		while(root->sonraki->sonraki != NULL) {
		
		root = root->sonraki;
		
		
	}
	
		free(root->sonraki);
		
		root->sonraki = NULL;
	
	
	}
	
	
	
}

	


	

int main() {
	
	tek_yonlu *ilk_dugum = (tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	tek_yonlu *ikinci_dugum = (tek_yonlu *)malloc(sizeof(tek_yonlu));

	tek_yonlu *ucuncu_dugum = (tek_yonlu *)malloc(sizeof(tek_yonlu));
	
	ilk_dugum->data = 1;
	
	ikinci_dugum->data = 2;
	
	ucuncu_dugum->data = 3;
	
	ilk_dugum->sonraki = ikinci_dugum;
	
	ikinci_dugum -> sonraki = ucuncu_dugum;
	
	ucuncu_dugum->sonraki = NULL;
	
	sona_ekle(2);
	
	basa_ekle(1);
	
	basa_ekle(8);
	
	araya_ekle(1, 25);
	
	listele();
	
	bastan_sil();
	
	listele();
	
	sondan_sil();
	
	listele();

	

	
	







return 0;
}
