#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	
	struct stack *next;
	
	int eleman;

}stack;

typedef struct stack yigin;

yigin *temp = NULL;

yigin *us = NULL;

yigin *ekle(int x) {
	
	yigin *yeni = (yigin *)malloc(sizeof(yigin));
	
	yeni->eleman = x;
	
	if(us == NULL) {
		
		us = yeni;
		
		us->next = NULL;
		
	}
	
	else {
		
		yeni->next = us;
		
		us = yeni;
		
		
		
	}
	
	
}

void pop() {
	
	if(us == NULL) {
		
		printf("Cikarilacak eleman yok");
		
	}
	
	else {
		
		printf("%d elemani stact cikarildi\n", us->eleman);
		
		temp = us->next; //Silme isleminden sonra en ustteki eleman olur.
		
		free(us);
		
		us = temp;
		
	}
	
	
}

void listele() {
	
	temp = us;
	
	while(temp != NULL) {
		
		printf("%d\n", temp->eleman);
		
		temp = temp->next;
	}
	
	
}

void peek() { //en ustteki degeri gosterir.
	
	if(us == NULL) {
		
		printf("Yigin bos");
		
	}
	
	else {
		
		printf("Stack deki en ustteki eleman : %d\n", us->eleman);
		
	}
	
	
}



int main() {
	
	int i;
	
	for(i = 0; i < 10; i++) {
		
		ekle(i*10);
		
	}
	
	pop();
	
	listele();
	
	pop();
	
	listele();
	
	peek();
	
	
	
		
	return 0;
}
