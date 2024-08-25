#include <stdio.h>
#include <stdlib.h>

/* Son dugume eleman ekleme iþlemi */

typedef struct dugum {
	
	struct dugum *pointer;
	
	int veri;
	
}node;





int main(int argc, char *argv[]) {
	
	node *root;
	
	root = (struct dugum*)malloc(sizeof(struct dugum));
	
	root->veri = 1;
	
	root->pointer = (struct dugum*)malloc(sizeof(struct dugum));
	
	root->pointer->veri = 2;
	
	root->pointer->pointer = (struct dugum*)malloc(sizeof(struct dugum));
	
	root->pointer->pointer->veri = 3;
	
	root->pointer->pointer->pointer = NULL;
	
	node *iter;
	
	iter = (struct dugum*)malloc(sizeof(struct dugum));
	
	iter = root;
	
	
	while(iter->pointer != NULL) {
		
		printf("%d\n", iter->veri);
		
		iter = iter->pointer;
		
	}
	
	//Sona eleman eklemek
	
	int i = 0;
	
	for(i = 0; i <= 4; i++) {
		
		iter->pointer = (struct dugum*)malloc(sizeof(struct dugum));
		
		iter = iter->pointer;
		
		iter->veri = i * 10;
		
		//Null problemini çözmek için ise her zaman sonuna NULL yapýlýr
		
		iter->pointer = NULL;
	}
	
	
	
	return 0;
}
