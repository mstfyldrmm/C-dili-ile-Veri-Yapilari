#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char *isimler[100];

char *soyadlar[100];

int i;

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
	
	tel_rehberi *onceki = NULL, *eklenecek, *etkin ;
	
	eklenecek = dugum_olustur(a, b, c);
	
	etkin = baslangic;
	
	int i = 0;
	
	if(kisi_arama(a, b) == -1) {
		
		int i = 0;
		
		while (etkin != NULL && eklenecek->adi > etkin->adi){
					
				onceki = etkin;
        
        		etkin = etkin->sonraki;
        		
        		while(etkin != NULL && eklenecek->adi[i] != etkin->adi[i]  && i < 30) {
        			
        			onceki = etkin;
        
        			etkin = etkin->sonraki;
        		
        			i++;
				}
				
				
			
    	}
    	
    	while (etkin != NULL && strcmp(eklenecek->adi, etkin->adi) == 0 && eklenecek->soyadi > etkin->soyadi){
					
				onceki = etkin;
        
        		etkin = etkin->sonraki;
						
    	}
    	

 			if (onceki == NULL) {
 		
        		baslangic = eklenecek;
        
    	}
    
			else {
		
        		onceki->sonraki = eklenecek;
        
    	}
    
   				eklenecek->sonraki = etkin;
		
		
	}
	
	else {
		
		printf("Bu kisi listede mevcuttur");
		
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
        
    printf("\n\nRehberden silmek istediginiz kisinin adi : ");  
		                        
	scanf("%s", isim);
		
    printf("\n\nRehberden silmek istediginiz kisinin soyadi : ");
        
    scanf("%s", soyad);
    
    if(kisi_arama(isim, soyad) == 1) {
    	
    	if( strcmp(baslangic->adi, isim) == 0 && strcmp(baslangic->soyadi, soyad) == 0){
		
		printf("\nRehberden %s %s kisisi silindi\n", baslangic->adi, baslangic->soyadi);
		
		bastan_sil();

		}
	
		else {
		
		temp = baslangic;
	
			while( strcmp(temp->sonraki->adi, isim) != 0 && strcmp(temp->sonraki->soyadi, soyad) != 0) {
		
			temp = temp->sonraki;
		
		}
		
		if(temp->sonraki == NULL) {
		
		
			printf("\nRehberden %s %s kisisi silindi\n", temp->adi, temp->soyadi);
			
			sondan_sil();
			
		}
	
		arkadaki_dugum = temp;
	
		ondeki_dugum = temp->sonraki->sonraki;
		
		printf("\nRehberden %s %s kisisi silindi\n", temp->sonraki->adi, temp->sonraki->soyadi);
	
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






void listele(tel_rehberi *dugum) {
	
	if(baslangic == NULL) {
		
		printf("Telefon rehberinde kayitli kisi bulunamadi\n");
		
	}
	
	else {
		
		temp = dugum;
		
		while(temp != NULL) {
		
			printf("%s %s %s\n", temp->adi, temp->soyadi, temp->tel_num);
		
			temp = temp->sonraki;
			
			i++;
			
		}
	}
	
	getch();
	
}
	







int main(int argc, char *argv[]) {
		
	char ad[30];
				
	char soyad[30];
				
	char ortak[30];
	
	scanf("%s", &ad);
	
	scanf("%s", &soyad);
	
	printf("Aramak istenilen");
	
	scanf("%s", &ortak);
	
	int i, j;
	
	for(i = 0; i < strlen(ortak); i++) {
		
		for(j = 0; ad[i] != '\0' || soyad[i] != '\0'; j++) {
			
			if(ad[j] != ortak[i] && soyad[j] != ortak[i]) {
				
				
			}
			
			else {
				
				printf("%s %s %s\n ", ad, soyad, ortak);
				
				break;
				
			}
			
		}
		
	}
										
	

	
	return 0;
}
