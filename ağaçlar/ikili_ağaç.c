#include <stdio.h>
#include <stdlib.h>

typedef struct agac{
	
	struct agac *sol;
	
	struct agac *sag;
	
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

void preorder(ikili_agac *baslangic) { //Kok-sol-sag seklinde arama yapilir.
	
	if(baslangic != NULL) {
		
		printf(" %d ", baslangic->veri);
		
		preorder(baslangic->sol);
		
		preorder(baslangic->sag);
		
	}
}

void postorder(ikili_agac *baslangic) { //sol-sag-kok seklinde arama yapilir.
	
	if(baslangic != NULL) {
		
		postorder(baslangic->sol);
		
		postorder(baslangic->sag);
		
		printf(" %d ", baslangic->veri);
	}

}


void inorder(ikili_agac *baslangic) { //sol-kok-sag seklinde arama yapilir.
	
	if(baslangic != NULL) {
		
		inorder(baslangic->sol);
		
		printf(" %d ", baslangic->veri);
		
		inorder(baslangic->sag);
		
	}
}



int main(int argc, char *argv[]) {
	
	
	root = dugum_olustur(10);
	
	ikili_agac *b = dugum_olustur(20);
	
	ikili_agac *c = dugum_olustur(30);
	
	ikili_agac *d = dugum_olustur(40);
	
	ikili_agac *e = dugum_olustur(50);
	
	ikili_agac *f = dugum_olustur(60);
		
	ikili_agac *g = dugum_olustur(70);
	
	root->sol = b;
	
	root->sag = c;
	
	root->sol->sol = d;
	
	root->sol->sag = e;
	
	root->sag->sol = f;
	
	root->sag->sag = g;
	
	printf("Preorder gosterimi :\n");
	
	preorder(root);
	
	printf("\n");
	
	printf("Postorder gosterimi :\n");
	
	postorder(root);
	
	printf("\n");
	
	printf("Inorder gosterimi :\n");
	
	inorder(root);
	
	
	return 0;
}
