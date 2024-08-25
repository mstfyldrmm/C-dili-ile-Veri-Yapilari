#include <stdio.h>
#include <stdlib.h>

//Dinamik dizi ile stack yapma

int *dizi;

int boyut = 2;

int tepe = 0;


void pop() {
	
	tepe -= boyut;
	
	if(dizi == NULL) {
		
		printf("Stack bos!!!!");
		
	}
	
	if(tepe <= boyut) {
		
		int *yeni_dizi = (int *)malloc(sizeof(int)*(boyut-1));
		
		int i = 0;
		
		for(i = 0; i < boyut; i++) {
			
			yeni_dizi[i] = dizi[i];
				
		}
		
		yeni_dizi = dizi;
		
		free(dizi);
		
		int eleman = dizi[boyut];
		
		printf("%d elemani silindi\n", eleman);
		
		boyut -= 1;		
		
	}
	
}

void push(int x) {
	
	tepe += boyut;
	
	if(tepe >= boyut) {
				
		int *yeni_dizi = (int *)malloc(sizeof(int)*(tepe+1));
		
		int i = 0;
		
		for(i = 0; i < boyut; i++) {
			
			yeni_dizi[i] = dizi[i];
				
		}
		
		yeni_dizi = dizi;
		
		free(dizi);
		
		tepe++;
		
		dizi[tepe] = x;
		
	}
	
}


void bastir(int dizi[]) {
	
	int i = 0;
	
	for(i = 0; i < boyut; i++) {
		
		printf("%d\t", dizi[i]);
		
	}
	
	
}



int main() {
	
	dizi = (int *)malloc(sizeof(int)*boyut);
	

	
	bastir(dizi);
	
	
	
	return 0;
}
