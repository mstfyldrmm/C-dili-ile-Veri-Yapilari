#include <stdio.h>
#define SATIR 2
#define SUTUN 3

int main(){
 int a[SATIR][SUTUN] = {1, 2, 3, 4, 5, 6};
 int b[SATIR][SUTUN] = {7, 8, 9, 0, -1, -2};
 int c[SATIR][SUTUN];
 int i, j;
 puts("A Matrisi:");
 for(i = 0; i < SATIR; i++){
 	for(j = 0; j < SUTUN; j++)
 		printf("%d  ", a[i][j]);
 	printf("\n");
 }
 puts("B Matrisi:");
 for(i = 0; i < SATIR; i++){
 	for(j = 0; j < SUTUN; j++)
 		printf("%d  ", b[i][j]);
 	printf("\n");
 }
 puts("\nA + B Matrisi:");
 for(i = 0; i < SATIR; i++){
 	for(j = 0; j < SUTUN; j++){
 		c[i][j] = a[i][j] + b[i][j];
 		printf("%d  ", c[i][j]);
 	}
 	printf("\n");
 }
 return 0;
}

