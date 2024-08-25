#include <stdio.h>
#include <stdlib.h>

struct dugum {
	
	int veri;
	
	struct dugum *pointer;
	
	
};


int main() {
	
	struct dugum *p;
	
	p = (struct dugum*)malloc(sizeof(struct dugum)); // p pointeri artýk bir baslangic dugumunu gösterir.
	
	struct dugum *j = (struct dugum*)malloc(sizeof(struct dugum));
	
	
	p->veri = 25;
	
	p->pointer = j;
	
	j->veri = 50;
	
	printf("ilk dugum = %d ikinci dugum = %d", p->veri, j->veri);
	
	
	
	
	return 0;
}
