#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char *isimler[100];

char *soyadlar[100];

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
	
	tel_rehberi *onceki = NULL, *eklenecek, *etkin ;
	
	eklenecek = dugum_olustur(a, b, c);
	
	etkin = baslangic;
	
	int i = 0;
	
	while (etkin != NULL && eklenecek->adi[0] > etkin->adi[0] ){ 

			
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

}


	

	



int main(int argc, char *argv[]) {
	
	kisi_ekle("selim", "yildirim", "0656456");
    
    kisi_ekle("ahmet", "zela", "0656456");
   
    kisi_ekle("mehmet", "vere", "0656456");
   	
	listele(baslangic);
	
	kisi_sil();
	
	listele(baslangic);
	
	return 0;
}
