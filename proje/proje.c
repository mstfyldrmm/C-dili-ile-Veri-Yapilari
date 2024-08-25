#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
	
	if(baslangic == NULL) {
		
		baslangic = eklenecek;
		
	}
	
	else {
		
	 temp = baslangic;
		
		while(temp->sonraki != NULL) {
			
			temp = temp->sonraki;
			
		}
		
		temp->sonraki = eklenecek;
		
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
		
		temp = baslangic->sonraki;
		
		free(baslangic);
		
		baslangic = temp;
		
	}
	
	
}

void kisi_sil() {
		
	char isim[30];
        
    char soyad[30];
        
    printf("\n\nSilmek istediginiz kisinin adi    : ");  
		                        
	scanf("%s", isim);
		
    printf("Silmek istediginiz kisinin soyadi : ");
        
    scanf("%s", soyad);
	
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




void listele(tel_rehberi *dugum) {
	
	if(baslangic == NULL) {
		
		printf("Telefon rehberinde kayitli kisi bulunamadi\n");
		
	}
	
	else {
		
		temp = dugum;
	
		while(temp->sonraki != NULL) {
			
			printf("%s %s %s\n", temp->adi, temp->soyadi, temp->tel_num);
		
			temp = temp->sonraki;
			
		}

	}
		
}
 


int main(int argc, char *argv[]) {
	
	
	kisi_ekle("selim", "yildirim", "0656456");
    
    kisi_ekle("ahmet", "ala", "0656456");
   
    kisi_ekle("mehmet", "vere", "0656456");
   
	kisi_ekle("hasan", "kere", "0656456");
	
    kisi_ekle("huseyin", "dere", "0656456");
    
    listele(baslangic);
    

    
    
	

	
	
	
	
	return 0;
}
