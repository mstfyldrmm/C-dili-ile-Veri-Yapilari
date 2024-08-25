#include <stdio.h>

int factoriyel(int);
int topla(int);
int main() {
	printf("%d\n", factoriyel(6));
	printf("%d\n", topla(7));
	return 0;
}

int factoriyel(int n) {
	return (n == 1) ? 1 : n * factoriyel(n - 1);		
}
int topla(int n) {
	return (n == 1) ? 1 : n + topla(n - 1);		
}
