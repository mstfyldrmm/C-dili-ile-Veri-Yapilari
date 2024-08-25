#include <stdio.h>
#include <stdlib.h>

typedef struct dugum{
	
	struct dugum *pointer;
	
	int deger;
	
	
}node;
 
 

int main() {
	
	node *root;
	
	root = (struct dugum*)malloc(sizeof(struct dugum));

	root->pointer = (struct dugum*)malloc(sizeof(struct dugum));
	
	root->deger = 25;
	
	root->pointer->deger = 50;
	
	root->pointer->pointer = (struct dugum*)malloc(sizeof(struct dugum));
	
	root->pointer->pointer->deger = 75;
	
	root->pointer->pointer->pointer = NULL; // c de hatali deger almamak için son pointerýn gosterdigi degeri NULL olarak el ile degeri verilir	
	
	node *iter = (struct dugum*)malloc(sizeof(struct dugum));
	
	iter = root;
	
	
	while(iter != NULL) {
		
		printf("%d\n", iter->deger);
		
		iter = iter->pointer;
		
	}
	
	
	return 0;
}
