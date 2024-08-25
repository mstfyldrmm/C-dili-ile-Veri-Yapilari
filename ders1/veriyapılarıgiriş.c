#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dugum {
	
	struct dugum *sonraki;
	
	int data;
	
	
	
}tek_yonlu;

tek_yonlu *ilk_dugum = NULL;

tek_yonlu *root = NULL;


void listele() {
	
	root = ilk_dugum;
	
	while(root != NULL) {
		
		printf("%d\n", root->data);
		
		root = root -> sonraki;
		
		
	}
	

}

void basa_ekle(int sayi) {
	
	tek_yonlu *basa_eklenecek = (tek_yonlu *)malloc(sizeof(ilk_dugum));
	
	basa_eklenecek->data = sayi;

	
	if(ilk_dugum == NULL) {
		
		ilk_dugum = basa_eklenecek;
		
		return;
	}
	
	else {
		
		root = ilk_dugum;
		
		basa_eklenecek->sonraki = root;
		
		ilk_dugum = basa_eklenecek;
			
		
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
		
		ikinci_dugum->sonraki = ucuncu_dugum;
		
		ucuncu_dugum->sonraki = NULL;
		
		listele();
		
		
		
	
	
	
		
	return 0;
}
