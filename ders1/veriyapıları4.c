#include <stdio.h>
#include <stdlib.h>

/* baðlý listedeki elemanlari bastiran fonksiyon */

typedef struct dugum {
	
	struct dugum *next;
	
	int veri;
	
	
}nesne;

void bastir(nesne *r) {
	
	while(r != NULL) {
		
		printf("%d\n", r->veri);
		
		r = r->next;
	
	}
}



int main(int argc, char *argv[]) {
	
	nesne *root;
	
	root = (struct dugum*)malloc(sizeof(struct dugum));
	
	nesne *iter = (struct dugum*)malloc(sizeof(struct dugum));
	
	iter = root;
	
	iter->veri = 1;
	
	int i = 0;
	
	for(i = 0; i < 10; i++) {
		
		iter->next = (struct dugum*)malloc(sizeof(struct dugum));
		
		iter = iter->next;
		
		iter->veri = i * 10;
		
		iter->next = NULL;
		
		
		
	}
	
	bastir(root);
	
	
	
	return 0;
}
