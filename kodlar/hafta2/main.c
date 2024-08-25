#include <stdio.h>
#include <stdlib.h>

typedef struct dugum {
	
	struct dugum *next;
	
	int veri;
	
	
}nesne;

nesne *ilk_node = NULL, *son_node = NULL, *yeni_node, *node_sil, *gecici_node;

void bastir(nesne *r) {
	
	while(r != NULL) {
		
		printf("%d\n", r->veri);
		
		r = r->next;
	
	}
}

nesne * sil(nesne *r, int aranan){
	
      nesne *temp;
 
      nesne *iter = r;
 
      if( r->veri == aranan){
 	
      temp = r;
  
      r = r->next;
  
     free (temp);
  
     return r;
     
   }
 
  while ( iter->next != NULL && iter->next->veri != aranan) {
  	
  iter = iter->next;
  
  
 }
 
 if ( iter->next == NULL){
 	
  printf( "Sayi bulunamadi!\n" );
  
  return r;
 }
 temp = iter->next;
 
 iter->next = iter->next->next; 
 
 free (temp);
 
 return r;
}


int main(int argc, char *argv[]) {
	
	int deger = 0;
	
	nesne *root;
	
	root = (struct dugum*)malloc(sizeof(struct dugum));
	
	nesne *iter = (struct dugum*)malloc(sizeof(struct dugum));
	
	iter = root;
	
	iter->veri = 1;
	
	int i = 0;
	
	for(i = 1; i < 10; i++) {
		
		iter->next = (struct dugum*)malloc(sizeof(struct dugum));
		
		iter = iter->next;
		
		iter->veri = i * 10;
		
		iter->next = NULL;
	
}

	void arama(int aranan) {
	
    int kontrol = 0;
    
    ilk_node = root;
    
    gecici_node = ilk_node;
    
    if (gecici_node == NULL)
    
        kontrol = -1;
        
    else{
    	
        while (gecici_node != NULL) {
        	
            if (aranan == gecici_node->veri) {
            	
                kontrol = 1;
            }
            gecici_node = gecici_node->next;
        }
    }
     
    if (kontrol == 1)
    
    printf("%d Sayisi bagli listede var\n", aranan);
        
    else {
    	
    	printf("%d Sayisi bagli listede yok\n", aranan);
    	
	}
    
}
	printf("1-Bagli liste elemanlarini yazdir\n2-Bagli listeden istenilen elemani silmek\n3-Bagli listede deger arama\n");
	
	int islem;
	
	printf("Yapmak istediginiz islemi tuslayin : ");
	
	scanf("%d",&islem);
	
	
	switch(islem) {
		
		case 1 : 
		
		bastir(root);
		
		
		break;
		
		case 2 : 
		
		printf(" Silmek istediginiz degeri girin : ");
			
			scanf("%d", &deger);
			
			root = sil(root, deger);
			
			bastir(root);
		
		break;
		
		
		case 3 :
			
			printf("Aramak istediginiz degeri girin : ");
			
			scanf("%d", &deger);
			
			arama(deger);
		
		break;
		
		default : 
		
		printf("Hatali tuslama yaptiniz lutfen tekrar deneyiniz");
		
		break;
		
	}
		
		
	
	return 0;
}
