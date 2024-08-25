#include <stdio.h>
#include <stdlib.h>

//Algoritma tasar�m yakla��mlar�

//Ana mant�k olarak d�ng� yok

int factor(int sayi) {
	
	if(sayi == 1)
	
	return 1;
	
	else 
	
	//Mant�k--> 5.4! , 5.4.3!
	
	return sayi*factor(sayi-1);
	
}

int factoriyel(int sayi) {
	
	return (sayi == 1) ? 1 : sayi * factoriyel(sayi-1);
	
}





int ardisik_toplam(int n) {
	
	return (n == 1) ? 1 : n + ardisik_toplam(n-1);
	
	
}





int main(int argc, char *argv[]) {
	
	
	printf("%d\n", factor(5));
	
	printf("Kisa hali : %d\n", factoriyel(4));	
	
	printf("Toplam : %d", ardisik_toplam(10));
	
	
	
	return 0;
}
