#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dugum {
	
	struct dugum *sag;
	
	struct dugum *sol;
	
	int veri;
	
}ikili_agac;

ikili_agac *root = NULL;

ikili_agac *dugum_olustur(int veri) {
	
	ikili_agac *root = (ikili_agac *)malloc(sizeof(ikili_agac));
	
	root->sol = NULL;
	
	root->sag = NULL;
	
	root->veri = veri;
	
	return root;
}

void preorder(ikili_agac *baslangic) {
	
	if(baslangic != NULL) {
		
		printf(" %d ", baslangic->veri);
		
		preorder(baslangic->sol);
		
		preorder(baslangic->sag);
		
	}
	
	
	
}




int main(int argc, char *argv[]) {
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
