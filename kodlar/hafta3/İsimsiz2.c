#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum{
    int veri1;
    int veri2;
    struct dugum *onceki;
    struct dugum *sonraki;
};
typedef struct dugum cift_yonlu_bliste;

cift_yonlu_bliste *ilk = NULL;

cift_yonlu_bliste *son = NULL;


void listele(cift_yonlu_bliste*, char []);
void basa_ekle(int, int);
void sona_ekle(int, int);
void bastan_sil();
void sondan_sil();

void araya_ekle(int data1, int data2, int sira) {
	
	cift_yonlu_bliste *araya_eklenecek = (cift_yonlu_bliste *)malloc(sizeof(cift_yonlu_bliste));
	
	if(sira == 0) {
		
		basa_ekle(data1, data2);
		
		return;
	}
	
	if(ilk == NULL && sira > 0) {
		
		printf("Ekleme islemi yapilamaz");
		
		return;
		
	}
	
	int adet = 0, kontrol = 0;
	
	cift_yonlu_bliste *temp = (cift_yonlu_bliste *)malloc(sizeof(cift_yonlu_bliste));
	
	temp = ilk;
	
	while(temp != NULL) {
		
		 	if(adet == sira) {
		 		
		 		kontrol	 = 1;
		 		
		 		break;
			 }
		
			temp = temp->sonraki;
			
			adet++;
			
	}
	
	if(kontrol == 0) {
		
		printf("Eklenecek pozisyon yok\n");
		
		return;
		
	}
	
	if(temp->sonraki == NULL) {
		
		sona_ekle(data1, data2);
		
		return;
		
	}
	
	cift_yonlu_bliste *onceki_liste = (cift_yonlu_bliste *)malloc(sizeof(cift_yonlu_bliste));
	
	onceki_liste = temp->onceki;
	
	onceki_liste->sonraki = araya_eklenecek;
	
	araya_eklenecek->onceki = onceki_liste;
	
	araya_eklenecek->sonraki = temp;
	
	temp->onceki = araya_eklenecek;	
	
}

void aradan_eleman_silme(int sira) {
	
	if(sira == 0) {
		
		if(ilk != NULL) {
			
			bastan_sil();
			
			return;
			
		}
	
	}
	
	cift_yonlu_bliste *temp = (cift_yonlu_bliste *)malloc(sizeof(cift_yonlu_bliste));
	
	temp = ilk;
	
	int adet = 0, kontrol = 0;
	
	while(temp != NULL) {
		
		if(adet == sira) {
			
			kontrol = 1;
			
			break;
			
		}
		
		temp = temp->sonraki;
		
		adet++;
		
	}
	
	if(kontrol == 0) {
		
		printf("Sira girilmemis durumda \n");
		
		return;
		
		
	}
	
	if(temp->sonraki == NULL) {
		
		sondan_sil();
		
		return;
		
	}
	
	ilk = temp->onceki;
	
	son = temp->sonraki;
	
	ilk->sonraki = son;
	
	son->onceki = ilk;
	
	free(temp);
}























int main(){
	
    basa_ekle(3, 15);
    
    basa_ekle(5, 25);
    
    
    sona_ekle(21, 3);
    
    
    
  
    
    araya_ekle(12, 25, 1);
    
    aradan_eleman_silme(2);
    
    listele(ilk, "ileri");
    
   
    return 0;
}
void listele(cift_yonlu_bliste *baslama_noktasi, char mesaj[]){
    cift_yonlu_bliste *temp = baslama_noktasi;
    while(temp != NULL){
        printf("%d %d\n", temp -> veri1, temp -> veri2);
        if(!strcmp(mesaj, "geri"))
            temp = temp -> onceki;
        else
            temp = temp -> sonraki;
    }
}
void basa_ekle(int veri1, int veri2){
	
	if(ilk == NULL){ 
		ilk = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		ilk -> veri1 = veri1;
		ilk -> veri2 = veri2;
		ilk -> onceki = NULL;
    	ilk -> sonraki = NULL;
	}
	else{
		cift_yonlu_bliste 
		*temp = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		temp -> veri1 = veri1;
		temp -> veri2 = veri2;
		ilk -> onceki = temp;
		temp -> sonraki = ilk;
		temp -> onceki = NULL;
		ilk = temp;
	}
}
void sona_ekle(int veri1, int veri2){
	if(ilk == NULL){ 
		ilk = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		ilk -> veri1 = veri1;
		ilk -> veri2 = veri2;
		ilk -> onceki = NULL;
    	ilk -> sonraki = NULL;
	}
	else{
		cift_yonlu_bliste *temp1 = ilk;
		cift_yonlu_bliste 
		*temp2 = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		while(temp1 -> sonraki != NULL)
			temp1 = temp1 -> sonraki;
		temp2 -> veri1 = veri1;
		temp2 -> veri2 = veri2;
		temp1 -> sonraki = temp2;
		temp2 -> onceki = temp1;
		temp2 -> sonraki = NULL;
	}
}
void bastan_sil(){
	if(ilk == NULL){
		printf("Bos liste!");
	}
	else if(ilk -> sonraki == NULL){
		ilk = NULL;
		printf("Listede eleman kalmadi");
	}
	else{
		cift_yonlu_bliste *ikinci = ilk -> sonraki;
		ikinci -> onceki = NULL;
		free(ilk);
		ilk = ikinci;
	}
}
void sondan_sil(){
	if(ilk == NULL){
		printf("Bos liste!");
	}
	else if(ilk -> sonraki == NULL){
		ilk = NULL;
		printf("Listede eleman kalmadi");
	}
	else{
		cift_yonlu_bliste *temp = ilk;
		while(temp -> sonraki != NULL)
			temp = temp -> sonraki;
		cift_yonlu_bliste *sondanonceki = temp -> onceki;
		sondanonceki -> sonraki = NULL;
		free(temp);
	}
}
