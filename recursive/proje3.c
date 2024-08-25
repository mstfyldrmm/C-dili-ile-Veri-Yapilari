#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void foo(int n) {
	
	if(n > 0) {
		
		printf("%d", n);
		
		n -= 1;
		
		foo(n);
		
		printf("\n");
		
		printf("%d", n);
		
	}
	
	
	//Her adimda stack yigilir.
	
	
}



int main() {
	
	foo(3);
	
	
	
	return 0;
}
