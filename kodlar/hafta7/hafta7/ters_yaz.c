#include <stdio.h>

void ters_cevir(char *, int);
int main() {
	char *s = "durmus";
	ters_cevir(s, 6);
	return 0;
}

void ters_cevir(char *dizi, int N){
	if(N == 0)
		printf("%c", *dizi);
	else {
		printf("%c", *(dizi + N));
		ters_cevir(dizi, N - 1);
	}
}
