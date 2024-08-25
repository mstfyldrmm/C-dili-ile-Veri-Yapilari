#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct dugum {
	
	struct dugum *onceki;
	
	struct dugum *sonraki;
	
	int veri1;
	
	int veri2;
	
}cift_bagli_liste;


cift_bagli_liste *start = NULL;

cift_bagli_liste *end = NULL;

void listele(cift_bagli_liste *baslangic, char mesaj[]) {
	
	cift_bagli_liste *temp = baslangic;
	
	while(temp != NULL) {
		
		printf("\n%d %d\n", temp->veri1, temp->veri2);
		
		if(!strcmp(mesaj, "geri"))
		
            temp = temp -> onceki;
            
        else
        
            temp = temp -> sonraki;
				
	}	
	
}

void basa_ekle(int x, int y) {

	if(start == NULL) {
		
	cift_bagli_liste  *start;
	
	start = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	start->veri1 = x;
	
	start->veri2 = y;
	
	start -> onceki = NULL;
	
    start -> sonraki = NULL;
	
	}
		
	else {
		
	cift_bagli_liste  *temp;
	
	temp = (cift_bagli_liste*)malloc(sizeof(cift_bagli_liste));
	
	
	temp->veri1 = x;
	
	temp->veri2 = y;
	
	start->onceki = temp;
	
	temp->onceki = NULL;
	
	start = temp;
		
}
			
}

void sona_ekle(int veri1, int veri2){
	
	if(start == NULL){ 
	
		start = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
		
		start -> veri1 = veri1;
		
		start -> veri2 = veri2;
		
		start -> onceki = NULL;
		
    	start -> sonraki = NULL;
    	
	}
	else {
		
		cift_bagli_liste *temp1 = start;
		
		cift_bagli_liste *temp2 = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
		
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
	
	if(start == NULL){
		
		printf("Bos liste!");
		
	}
	else if(start -> sonraki == NULL){
		
		start = NULL;
		
		printf("Listede eleman kalmadi");
		
	}
	else {
		
		cift_bagli_liste *ikinci = start -> sonraki;
		
		ikinci -> onceki = NULL;
		
		free(start);
		
		start = ikinci;
	}
}
void sondan_sil(){
	
	if(start == NULL){
		
		printf("Bos liste!");
		
	}
	else if(start -> sonraki == NULL){
		
		start = NULL;
		
		printf("Listede eleman kalmadi");
		
	}
	else{
		
		cift_bagli_liste *temp = start;
		
		while(temp -> sonraki != NULL)
		
			temp = temp -> sonraki;
			
		cift_bagli_liste *sondanonceki = temp -> onceki;
		
		sondanonceki -> sonraki = NULL;
		
		free(temp);
	}
}


void araya_ekle(int data1, int data2, int sira) {
	
	cift_bagli_liste *araya_eklenecek = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	if(sira == 0) {
		
		basa_ekle(data1, data2);
		
		return;
	}
	
	if(start == NULL && sira > 0) {
		
		printf("Ekleme islemi yapilamaz");
		
		return;
		
	}
	
	int adet = 0, kontrol = 0;
	
	cift_bagli_liste *temp = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	temp = start;
	
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
	
	cift_bagli_liste *onceki_liste = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	onceki_liste = temp->onceki;
	
	onceki_liste->sonraki = araya_eklenecek;
	
	araya_eklenecek->onceki = onceki_liste;
	
	araya_eklenecek->sonraki = temp;
	
	temp->onceki = araya_eklenecek;	
	
}

void aradan_eleman_silme(int sira) {
	
	if(sira == 0) {
		
		if(start != NULL) {
			
			bastan_sil();
			
			return;
			
		}
	
	}
	
	cift_bagli_liste *temp = (cift_bagli_liste *)malloc(sizeof(cift_bagli_liste));
	
	temp = start;
	
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
	
	cift_bagli_liste *start = temp->onceki;
	
	cift_bagli_liste *end = temp->sonraki;
	
	start->sonraki = end;
	
	end->onceki = start;
	
	free(temp);
}




int main() {
	
	
	
	basa_ekle(100, 41);
	
	sona_ekle(25, 50);
	
	basa_ekle(10, 4);
	
	sona_ekle(255, 505);
	
	basa_ekle(1005, 415);
	
	sona_ekle(2555, 5055);
	
	basa_ekle(10055, 4155);
	
	sona_ekle(25555, 50555);
	
	basa_ekle(10055555, 45551);
	
	sona_ekle(255535, 50353);
	
	listele(start, "ileri");
	
	aradan_eleman_silme(1);
	
	araya_ekle(1, 2, 3);
	
	
	return 0;
}
