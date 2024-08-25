#include <stdio.h>
#include <limits.h>

int main(){
 	int dizi[] = {700, -120, 423, 521, 55, 912, 986, 356, 247, 100};
 	int i, max = INT_MIN;
 	int N = sizeof(dizi) / sizeof(int);
 	for(i = 0; i < N; i++)
		if(dizi[i] > max)
			max = dizi[i];
 	printf("En buyuk eleman = %d\n", max);
	return 0;
}
