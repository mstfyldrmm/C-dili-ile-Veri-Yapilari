#include <stdio.h>
#include <stdlib.h>

typedef struct dugum {
	
	struct dugum *sol;
	
	struct dugum *sag;
	
	int x;
	
}agac;

agac *kok = NULL;


agac *dugum_olustur(int veri) {
	
	agac *root = (agac *)malloc(sizeof(agac));
	
	root->x = veri;
	
	root->sol = NULL;
	
	root->sag = NULL;
	
	return root;
}


void preorder(agac *baslangic) {
	
	if(kok != NULL) {
		
		printf(" %d ", baslangic->x);
		
		preorder(baslangic->sol);
		
		preorder(baslangic->sag);
		
	}
	
}

void postorder(agac *baslangic) {
	
	if(kok != NULL) {
		
		postorder(baslangic->sol);
		
		postorder(baslangic->sag);
		
		printf(" %d ", baslangic->x);
		
	}
	
}

void inorder(agac *baslangic) {
	
	if(kok != NULL) {
		
		inorder(baslangic->sol);
		
		printf(" %d ", baslangic->x);
		
		inorder(baslangic->sag);
		
		
		
	}
	
}



int main(int argc, char *argv[]) {
	
	kok = dugum_olustur(10);
	
	agac *b = dugum_olustur(20);
	
	agac *c = dugum_olustur(30);
	
	agac *d = dugum_olustur(40);
	
	agac *e = dugum_olustur(50);
	
	agac *f = dugum_olustur(60);
		
	agac *g = dugum_olustur(70);
	
	kok->sol = b;
	
	kok->sag = c;
	
	kok->sol->sol = d;
	
	kok->sol->sag = e;
	
	kok->sag->sol = f;
	
	kok->sag->sag = g;
	
	printf("Preorder gosterimi :\n");
	
	preorder(kok);
	
	printf("\n");
	
	printf("Postorder gosterimi :\n");
	
	postorder(kok);
	
	printf("\n");
	
	printf("Inorder gosterimi :\n");
	
	inorder(kok);
	
	
	
	
	
	
	return 0;
}
