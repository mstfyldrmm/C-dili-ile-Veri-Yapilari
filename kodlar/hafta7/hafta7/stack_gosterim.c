#include <stdio.h>

void foo(int);
int main() {
	foo(3);
	return 0;
}
void foo(int n){
	if(n > 0) {
		printf("%d", n);
		n = n - 1;
		foo(n);
		printf("\n");
		printf("%d", n);
	}
}
