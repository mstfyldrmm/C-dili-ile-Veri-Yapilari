#include <stdio.h>

int main(){
	char katar[40];
	int i = 0;
	printf("Bir seyler yazin: ");
 	gets(katar);
 	while(katar[i])
 		i++;
 	printf("Dizinin uzunlugu : %d\n", i);
	return 0;
}
