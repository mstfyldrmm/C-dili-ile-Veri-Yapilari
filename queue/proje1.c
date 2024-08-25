#include <stdio.h>
#include <stdlib.h>

#define BOY 5

//Front ilk dügüm

//rear son dugum

//FIFO--> Ilk giren ilk isleme tabi tutulur.

//Silme isleminde ise en sondaki veri silinir

int dizi[BOY];

int rear = -1;

int front = -1;

void eleman_ekle(int veri) { //Enqueue
	
	if(rear == BOY - 1) {
		
		printf("Kuyruk dolu!!!!");
		
	}
	
	else {
		
		if(front == -1) 
			
			front = 0;
			
			rear++;
			
			dizi[rear] =  veri;
			
		
	}
	
}


void eleman_sil() {
	
	if(front == -1 || front > rear) {
		
		printf("Kuyruk bos!!!");
		
		front = -1;
		
		rear = -1;
		
	}
	
	else {
		
		front++;
		
	}
	
	
	
}

void yazdir() {
	
	
	
	int i = 0;
	
	if(front == -1) {
		
		printf("Kuyruk bos");
		
	}
	
	else { 
	
	}
	
	for(i = front; i < rear; i++) {
		
		printf("eleman --> %d\n", i, dizi[i]);
		
	}
	
	
	
}








int main() {
	
	int i = 0;
	
	for(i = 0; i < 5; i++) {
		
		eleman_ekle(i*25);
		
	}
	
	yazdir();
	
	eleman_sil();
	
	eleman_sil();
	
	yazdir();
	
	eleman_ekle(25);
	
	yazdir();
	
	
	
	
		
	return 0;
}
