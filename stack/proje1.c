#include <stdio.h>
#include <stdlib.h>
#define N 10

int yigin[N];

int us = -1;

void push(int sayi) {
	
	if(us == N - 1) {
		
		printf("Yigin doludur\n");
		
	}
	
	else {
		
		us++;
		
		yigin[us] = sayi;
		
		
		
	}
}

void pop() {
	
	if(us == N - 1) {
		
		printf("Yigin bos");
		
	}
	
	else {
		
		int cikan = yigin[us];
		
		printf("%d elemani yigittan cikarildi\n", cikan);
		
		us--;
		
		
	}
	
	
	
}

void yazdir() {
	
	int i;
	
	int temp = us;
	
	if(us == -1) {
		
		printf("Yigin bos!!!");
		
	}
	
	for(i = temp; i > -1; i--) {
		
		printf("%d\n", yigin[i]);
		
		temp--;
		
	}
	
	
}



int main() {
	
	push(25);
	
	push(50);
	
	push(75);
	
	yazdir();
	
	pop();
	
	yazdir();
	
	push(25);
	
	push(50);
	
	
		
	return 0;
}
