#include <stdio.h>
#include <stdlib.h>

int faktor(int n) {
	
	if(n == 1) 
	
	return 1;
	
	else 
	
	return n * faktor(n-1);
		
}

int fibonacci(int n) {
	
	if(n == 1) 
	
	return 1;
	
	if(n == 0)
	
	return 0;
	
	else 
	
	return fibonacci(n-1) + fibonacci(n-2);
	
}



int main(int argc, char *argv[]) {
	
	printf("%d\n", faktor(3));
	
	printf("%d\n", faktor(5));
	
	printf("%d\n", fibonacci(3));
	
	
	return 0;
}
