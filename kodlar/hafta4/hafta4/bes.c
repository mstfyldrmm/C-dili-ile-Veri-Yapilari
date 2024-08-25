#include <stdio.h>
#define N 10

int main(){
	int i;
 	float dizi[N], ortalama, toplam = 0.0;
 	for(i = 0; i < N; i++){
 		printf("%d. sayi :", i + 1);
 		scanf("%f", (dizi + i));
 		toplam += *(dizi + i);
 	}
 	ortalama = toplam / N;
 	printf("Sayilarin ortalamasi = %f\n", ortalama);
	return 0;
}
