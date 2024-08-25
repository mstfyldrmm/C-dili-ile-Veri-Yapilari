#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int i;

int x = 0;

typedef struct dugum{     

    char adi[30];
    
	char soyadi[30];
	
    char tel_num[12];
    
    struct dugum *sonraki;
    
    struct dugum *onceki;

}tel_rehberi;  

tel_rehberi *baslangic = NULL;

tel_rehberi *temp = NULL;

tel_rehberi *root = NULL;

tel_rehberi *ondeki_dugum = NULL;

tel_rehberi *arkadaki_dugum = NULL;

tel_rehberi * dugum_olustur(char name[], char surname[], char numara[]) {

	tel_rehberi *yeni = (tel_rehberi *)malloc(sizeof(tel_rehberi));
	
	strcpy(yeni->adi, name);
	
	strcpy(yeni->soyadi, surname);
	
    strcpy(yeni->tel_num, numara);
    
    yeni->sonraki = NULL;
    
    yeni->onceki = NULL;
    
    return yeni;

}



void kisi_ekle(char a[], char b[], char c[]) {
	
	tel_rehberi *eklenecek = dugum_olustur(a, b, c);
	
	if( kisi_arama(a, b) == -1 ) {
		
		if(baslangic == NULL) {
		
			baslangic = eklenecek;
			
			printf("Rehbere %s %s isimli kisi eklendi\n", eklenecek->adi, eklenecek->soyadi);
		
		}
	
		else {
		
		 		temp = baslangic;
		
				while(temp->sonraki != NULL) {
			
				temp = temp->sonraki;
			
		}
		
			temp->sonraki = eklenecek;
			
			printf("Rehbere %s %s isimli kisi eklendi\n", eklenecek->adi, eklenecek->soyadi);

	}
			
  }
	
	else {
		
		printf("\nRehberde %s %s kisisi mevcuttur!!!!\n", eklenecek->adi, eklenecek->soyadi);
		
	}
	
	
}



void bastan_sil() {
	
	if(baslangic == NULL) {
		
		printf("Silinecek dugum bulunamadi");
		
	}
	
	else {
		
		temp = baslangic->sonraki;
		
		free(baslangic);
		
		baslangic = temp;
		
	}
	
}

void sondan_sil() {
	
	if(baslangic == NULL) {
		
		printf("Silinecek dugum bulunamadi");
		
	}
	
	else {
		
		temp = baslangic;
		while(temp != NULL)
		temp=temp->sonraki;
		free(temp);
		temp->sonraki=NULL;
		
	}
	
	
}

void kisi_sil() {
		
	char isim[30];
        
    char soyad[30];
        
    printf("\n\nSilmek istediginiz kisinin adi    : ");  
		                        
	scanf("%s", isim);
		
    printf("Silmek istediginiz kisinin soyadi : ");
        
    scanf("%s", soyad);
    
    if(kisi_arama(isim, soyad) == 1) {
    	
    	if( strcmp(baslangic->adi, isim) == 0 && strcmp(baslangic->soyadi, soyad) == 0){
		
		printf("Rehberden %s %s kisisi silindi\n", baslangic->adi, baslangic->soyadi);
		
		bastan_sil();
	

		}
	
		else {
		
		temp = baslangic;
	
			while( strcmp(temp->sonraki->adi, isim) != 0 && strcmp(temp->sonraki->soyadi, soyad) != 0) {
		
			temp = temp->sonraki;
		
		}
		
		if(temp->sonraki == NULL) {
		
			printf("Rehberden %s %s kisisi silindi\n", temp->adi, temp->soyadi);
			
			sondan_sil();
			
		
			
		}
	
		arkadaki_dugum = temp;
	
		ondeki_dugum = temp->sonraki->sonraki;
		
		printf("Rehberden %s %s kisisi silindi\n", temp->sonraki->adi, temp->sonraki->soyadi);
	
		free(temp->sonraki);
	
		arkadaki_dugum->sonraki = ondeki_dugum;
			
		}
    		
	}
	
	else  {
	
		printf("\n%s %s kisisi rehberde mevcut degil!!!\n", isim, soyad);
		
	}
	

}




int  kisi_arama(char ad[], char soyad[]) {
	
	temp = baslangic;
	
	while(temp != NULL) {
		
		if(strcmp(temp->adi, ad) == 0 && strcmp(temp->soyadi, soyad) == 0) {
				
			return 1;
			
		} 
			
		
		
		temp = temp->sonraki;
		
	}
	
	return -1;
	
}




void numara_bul(char ad[], char soyad[]) {
	
	temp = baslangic;
	
	while(temp != NULL) {
		
		if(strcmp(temp->adi, ad) != 0 || strcmp(temp->soyadi, soyad) != 0) {
			
			printf("\nRehberde bu kisi mevcut degildir!!!!\n");
	
			
		}
		
		else {
			
			printf("\nRehberde %s %s kisinin numarasi : %s\n", temp->adi, temp->soyadi, temp->tel_num);
			
			break;
			
		}
		
		temp = temp->sonraki;
		
	}
		
}


void sirala(){
	
	char *isimler[100];

	char *soyadlar[100];	

	char t[100];
	
	temp = baslangic;
	
	while(temp != NULL){
		
		isimler[x] = temp->adi;
		
		soyadlar[x] = temp->soyadi;
		
		temp = temp->sonraki;
		
		x++;
		
	}
	
	int a,b;
	
	/*printf("rehberdeki Isimler : \n");
	
	for(a = 0; a < x; a++){
		
		printf("\n%s  %s", isimler[a], soyadlar[a]);
		
	}*/
	
	for(a = 1; a < x; a++){
		
		for(b = 1; b < x; b++){
			
			if(strcmp(soyadlar[b-1] , soyadlar[b]) > 0){
			
				strcpy(t , isimler[b-1]);
				strcpy(isimler[b-1] , isimler[b]);
				strcpy(isimler[b] , t);
				
				strcpy(t , soyadlar[b-1]);
				strcpy(soyadlar[b-1] , soyadlar[b]);
				strcpy(soyadlar[b] , t);
				
			}
			
			if(strcmp(isimler[b-1] , isimler[b]) > 0){
				
				strcpy(t , soyadlar[b-1]);
				strcpy(soyadlar[b-1] , soyadlar[b]);
				strcpy(soyadlar[b] , t);
				
				strcpy(t , isimler[b-1]);
				strcpy(isimler[b-1] , isimler[b]);
				strcpy(isimler[b] , t);
				
			}
		}
	}
	
	for(a = 0; a < x; a++){
		
		if(isimler[a] != "0" && soyadlar[a] != "0") {
			
			printf("\n%s  %s ", isimler[a],soyadlar[a]);
			
		}
		
		
		
	}
	
}


int main(int argc, char *argv[]) {
	
	int secim = 0;
	
	char ad[30];
				
	char soyad[30];
				
	char numara[12];
	
	do {
		
		printf("\n\n\n\n****TELEFON REHBERI***\n\n\n\n");
	
		printf("1-Kisi Ekleme\n\n");
	
		printf("2-Kisi Silme\n\n");
	
		printf("3-Kisi Aramak\n\n");
	
		printf("4-Rehberi listeleme\n\n");
	
		printf("Cikis yapmak icin 5 ' tuslayiniz\n\n");

		printf("Lutfen yapmak istediginiz islemi tuslayiniz : ");
	
		scanf("%d", &secim);
	
		system("cls");
		
		switch(secim) {
			
			case 1: 
			
				printf("\nEklemek istediginiz kisinin adi :");
				
				scanf("%s", &ad);
				
				printf("\nEklemek istediginiz kisinin soyadi :");
				
				scanf("%s", &soyad);
				
				printf("\nEklemek istediginiz kisinin numarasi :");
				
				scanf("%s", &numara);
				
				kisi_ekle(ad, soyad, numara);
				
				sleep(3);
				
				system("cls");
				
				break;
			
			case 2:
				
				kisi_sil();
				
				sleep(3);
				
				system("cls");
				
				break;
			
			case 3:
				
				printf("\nAramak istediginiz kisinin adi :");
				
				scanf("%s", &ad);
				
				printf("\nAramak istediginiz kisinin soyadi :");
				
				scanf("%s", &soyad);
				
				numara_bul(ad, soyad);
				
				sleep(3);
				
				system("cls");
				
				break;
				
			case 4:
				
				//system("cls");
				
				printf("\n\n-----------Rehberdeki isimler------\n\n");
				
				sirala();
				
				sleep(3);
				
				system("cls");
				
				break;

		}
	
	}while(secim != 5);
	
	
	
	return 0;
}
