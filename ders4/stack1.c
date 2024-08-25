#include <stdio.h>
#include <stdlib.h>

int *dizi;

int boyut = 2;

int tepe = 0;

int pop() {  //Po
	
	//Diziyi pop ettikçede dizinin boyutunu dusurmemiz gerekiyor
	
	//Bellekte fazladan yer kaplar
	
	if(dizi == NULL) { // Eger dizi bos ise 
		
		printf("Dizi bos!!!!");
		
	}
	
	if(tepe <= (boyut/4) ){
	
		
		int *dizi2 = (int *)malloc(sizeof(int)*(boyut/2)); //Dizi1 in yarýsý boyutunda yeni dizi tanýmladýk
		
		int i = 0;
		
		for(i = 0; i < boyut; i++) {
			
			dizi2[i] = dizi[i];
			
		}
		
		free(dizi);
		
		dizi = dizi2; // Dizi1 in verileri bellekten silinmeden yeni tanýmladýgýmýz dizi2 ye kopyalamamýz gerekir.
		
		boyut /= 2;
		
	}
	
	return dizi[--tepe];	
	
}


void push(int a) {   //Push en alttan baslayarak sirali olarak deger ekler
	
	if(tepe >= boyut) {
		
		//Dizinin eleman alacak kapasitesi yoksa
		
		//Dizilerin boyutunu degisken ile belirtemeyiz. Örn, int dizi[a+2]
		
		//Bu yuzden pointer kullanýmý gereklidir.
		
		
		if(dizi == NULL) {
			
			//Dizi bos ise boyutunu tanýmlarýz
			
			dizi = (int *)malloc(sizeof(int)*boyut);
			

		}
		
		int *dizi2 = (int *)malloc(sizeof(int)*(boyut*2)); //Dizi1 in 2 katý boyutunda yeni dizi tanýmladýk
		
		int i = 0;
		
		for(i = 0; i < boyut; i++) {
			
			dizi2[i] = dizi[i];
			
		}
		
		free(dizi);
		
		dizi = dizi2; // Dizi1 in verileri bellekten silinmeden yeni tanýmladýgýmýz dizi2 ye kopyalamamýz gerekir.
		
		boyut *= 2;
		
	}
	 
	 //Dizi doldukca her seferinde yeni dizi olusturup iki kat boyuta sahip olusturmak	
	
	dizi[tepe++] = a;
	
	
}

void bastir() {
	
	printf("Boyut : %d \n", boyut);
	
	int i = 0;
	
	for(i = 0; i < tepe; i++) {
		
		printf("%d ", dizi[i]);
		
		
	}
	
	
	
}



int main(int argc, char *argv[]) {
	
	dizi = (int *)malloc(sizeof(int)*boyut);
	
	push(10);  // degerleri ilk olarak 10 ekler . 20 
	
	push(20);
	
	push(30);
	
	push(40);
	
	push(50);
	
	bastir();
	
	printf("popped : %d\n", pop());
	
	printf("popped : %d\n", pop());
	
	printf("popped : %d\n", pop());
	
	printf("popped : %d\n", pop());
	
	bastir();
	
	push(10);  
	
	push(20);
	
	push(30);
	
	push(40);
	
	push(50);
	
	push(60);
	
	push(70);
	
	push(80);
	
	push(90);
	
	push(100);
	
	bastir();
	
	return 0;
}
