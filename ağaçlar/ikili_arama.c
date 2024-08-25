#include <stdio.h>
#include <stdlib.h>

typedef struct agac{
	
	struct agac *sol;
	
	struct agac *sag;
	
	int veri;
	
	
}ikili_agac;

ikili_agac *root = NULL;

ikili_agac *kok_dugum_olustur(int veri) {
	
	ikili_agac *root = (ikili_agac *)malloc(sizeof(ikili_agac));
	
	root->sol = NULL;
	
	root->sag = NULL;
	
	root->veri = veri;
	
	return root;
}


ikili_agac *eleman_ekle(ikili_agac *root, int veri) {
	
	if(root == NULL) {
		
		root = kok_dugum_olustur(veri);
		
	}
	
	else {
		
		ikili_agac *temp = root;
		
		if(veri < root->veri) {
			
			root->sol = eleman_ekle(root->sol, veri);
			
		}
		
		else {
			
			root->sag = eleman_ekle(root->sag, veri);
			
		}
		
		
	}
	
	return root;
	
}

void inorder(ikili_agac *baslangic) {
	
	if(baslangic != NULL) {
		
		inorder(baslangic->sol);
		
		printf(" %d ", baslangic->veri);
		
		inorder(baslangic->sag);
		
	}
	
	
}

ikili_agac *eleman_ara(ikili_agac *root, int aranan) {
	
	if(root != NULL) {
		
		if(aranan == root->veri) {
			
			printf("\nAranan deger bulundu\n");
			
		}
		
		else if(aranan < root->veri) {
			
			return eleman_ara(root->sol, aranan);
			
		}
		
		else if(aranan > root->veri) {
			
			return eleman_ara(root->sag, aranan);
			
		}
		
		
	}
	
	
}





int main(int argc, char *argv[]) {
	
	
	int i;
	
	root = kok_dugum_olustur(25);
	
	for(i = 1; i < 10; i++) {
		
		eleman_ekle(root, i*10);
		
	}
	
	printf("inorder gosterimi(kucukten buyuge dogru) : \n");
	
	inorder(root);	
	
	eleman_ara(root, 50);
	
	eleman_ara(root, 100);
	
	
	
	return 0;
}
