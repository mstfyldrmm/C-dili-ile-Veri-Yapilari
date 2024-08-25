#include <stdio.h>
#include <stdlib.h>

#define BOYUT 10

int dizi[BOYUT];

int indis = -1;




void push(int dizi[], int eleman) {
	
	if(indis >= BOYUT-1) {
		
		printf("Yigin dolu!!!!");
		
	}
	
	else {
		
		indis++;
		
		dizi[indis] = eleman;
	
	}
	
}
 
void pop(int dizi[]) {
	
	if(indis == -1) {
		
		printf("Silinecek eleman bulunamadi");
		
	}
	
	else {
		
		int silinen = dizi[indis];
		
		indis--;
		
		printf("%d elemani silindi.", silinen);
		
	}
	
}

void listele(int dizi[]) {
	
	int i = 0;
	
	for(i = 0; i < BOYUT; i++) {
		
		printf("%d\n",dizi[i]);
		
	}
	
	
}




int main(int argc, char *argv[]) {
	

	push(dizi, 10);
	
	push(dizi, 20);
	
	push(dizi, 30);
	
	push(dizi, 40);
	
	push(dizi, 50);
	
	push(dizi, 60);
	
	pop(dizi);
	
	listele(dizi);
	
	
	return 0;
}
