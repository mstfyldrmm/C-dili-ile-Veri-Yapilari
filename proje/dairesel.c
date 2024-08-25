#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char *isimler[100];

char *soyadlar[100];
	
char *numaralar[100];
	
int eleman_sayisi = 0;

typedef struct dugum{     

    char adi[30];
    
	char soyadi[30];

    char tel_num[12];
    
    struct dugum *sonraki;
    
    struct dugum *onceki;

}tel_rehberi;  

tel_rehberi *baslangic = NULL;

tel_rehberi *temp = NULL;

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

int kisi_arama(char ad[], char soyad[]) ; 

void kisi_ekle(char a[], char b[], char c[]) {

	tel_rehberi *eklenecek = dugum_olustur(a, b, c);

	if( kisi_arama(a, b) == -1 ) {

		if(baslangic == NULL) {

			baslangic = eklenecek;

			printf("\nRehbere %s %s isimli kisi eklendi\n", eklenecek->adi, eklenecek->soyadi);

		}

		else {

			temp = baslangic;

			while(temp->sonraki != NULL) {

			temp = temp->sonraki;

		}

		temp->sonraki = eklenecek;

		printf("\nRehbere %s %s isimli kisi eklendi\n", eklenecek->adi, eklenecek->soyadi);

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

		if(temp->sonraki == NULL ){         
	
			free(temp); 
			
			baslangic= NULL; 
		}

		else{
	
			while(temp->sonraki != NULL) {
			
				temp=temp->sonraki;
				
				free(temp);
				
				temp->sonraki=NULL; 
			
			}
		
		} 
	} 
}

void kisi_sil() {

	char isim[30];
        
    char soyad[30];
        
    printf("\n\nSilmek istediginiz kisinin adi    : ");  
                       
	scanf(" %[^\n]s", isim);

    printf("\n\nSilmek istediginiz kisinin soyadi : ");
        
    scanf(" %[^\n]s", soyad);
    
    if(kisi_arama(isim, soyad) == 1) {

    	if( strcmp(baslangic->adi, isim) == 0 && strcmp(baslangic->soyadi, soyad) == 0){

			printf("\nRehberden %s %s kisisi silindi\n", baslangic->adi, baslangic->soyadi);

			bastan_sil();             
		} 
		
		else {
  
			temp = baslangic;
			
			arkadaki_dugum = baslangic ; 
			
			while( temp->sonraki!=NULL  ) {
			
				arkadaki_dugum = temp ; 
				
				temp= temp->sonraki ; 
				
				if( strcmp(temp->adi, isim) == 0 && strcmp(temp->soyadi, soyad) == 0  ){
				
					arkadaki_dugum->sonraki = temp->sonraki; 
					
					printf("\n%s %s rehberden silindi ", temp->adi, temp->soyadi );
					 
					free(temp)   ; 

				}

			}

			if(strcmp(temp->adi, isim) == 0 && strcmp(temp->soyadi, soyad) == 0  ){

				sondan_sil(); 
			
			}

		}

	}

	else{

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
	
	int sonuc = 0; 
	
	while(temp != NULL) {

		if(strcmp(temp->adi, ad) == 0 || strcmp(temp->soyadi, soyad) == 0) {

			printf("\nRehberde bu kisi mevcut numarasi : %s  \n ", temp->tel_num ); 
			
			sonuc = 1; 
			
			break; 
		
		}

		temp = temp->sonraki;

	}
	
	if(sonuc == 0)
	
		printf("\nRehberde bu kisi mevcut degildir!!!!\n");


}


void sirala(){

	temp = baslangic;

	while(temp != NULL){

		isimler[eleman_sayisi] = temp->adi;

		soyadlar[eleman_sayisi] = temp->soyadi;

		numaralar[eleman_sayisi] = temp->tel_num;  

		temp = temp->sonraki;

		eleman_sayisi++;

	}
		
	char t[eleman_sayisi];
	
	
	if(baslangic == NULL)
	
		printf("\n\nRehber BOS!!!!\n\n");

	int a,b;

	for(a = 0; a < eleman_sayisi; a++){ 

		for(b = 1; b < eleman_sayisi; b++){
			
				if(strcmp(soyadlar[b-1] , soyadlar[b]) > 0 ){  
				
				strcpy(t , soyadlar[b-1]);
				
				strcpy(soyadlar[b-1] , soyadlar[b]);
				
		    	strcpy(soyadlar[b] , t);

				strcpy(t , isimler[b-1]);
				
				strcpy(isimler[b-1] , isimler[b]);
				
				strcpy(isimler[b] , t);
				
				strcpy(t , numaralar[b-1]);
				
				strcpy(numaralar[b-1] , numaralar[b]);
				
				strcpy(numaralar[b] , t);
			}
			
				if(strcmp(isimler[b-1] , isimler[b]) > 0 ){  
				
				strcpy(t , isimler[b-1]);
				
				strcpy(isimler[b-1] , isimler[b]);
				
				strcpy(isimler[b] , t);

				strcpy(t , soyadlar[b-1]);
				
				strcpy(soyadlar[b-1] , soyadlar[b]);
				
				strcpy(soyadlar[b] , t);

				strcpy(t , numaralar[b-1]);      
				    
				strcpy(numaralar[b-1] , numaralar[b]);
				
				strcpy(numaralar[b] , t); 
		}
	 
		}
		
	}

	temp = baslangic; 
	
	printf("%-30s \t %-30s \t%s\n\n", "AD", "SOYAD", "TELEFON");
	
	for(a = 0; a < eleman_sayisi; a++){
		
		strcpy(temp->adi, isimler[a] ); 
		
		strcpy(temp->soyadi, soyadlar[a] ); 
		
		strcpy(temp->tel_num, numaralar[a] );

		printf("%-30s \t %-30s \t%s\n\n", isimler[a],soyadlar[a], numaralar[a]);
		
		temp= temp->sonraki; 

	}
	 
	eleman_sayisi = 0; // x i tekrar 0 a set ettim, listele fonksiyonunu tekrar çaðýrýrsan 0 dan baþlasýn diye 

	getch();   
}


void kisi_paylas(){
	
	FILE *dosya = fopen("telefon_rehberi.txt","w");
	
	char t[100];

	temp = baslangic;

	while(temp != NULL){

		isimler[eleman_sayisi] = temp->adi;

		soyadlar[eleman_sayisi] = temp->soyadi;

		numaralar[eleman_sayisi] = temp->tel_num;  

		temp = temp->sonraki;

		eleman_sayisi++;

	}
	

	int a,b;

	for(a = 0; a < eleman_sayisi; a++){  

		for(b = 1; b < eleman_sayisi; b++){
			
				if(strcmp(soyadlar[b-1] , soyadlar[b]) > 0 ){  

				strcpy(t , soyadlar[b-1]);
				
				strcpy(soyadlar[b-1] , soyadlar[b]);
				
		    	strcpy(soyadlar[b] , t);

				strcpy(t , isimler[b-1]);
				
				strcpy(isimler[b-1] , isimler[b]);
				
				strcpy(isimler[b] , t);
				
				strcpy(t , numaralar[b-1]);
				
				strcpy(numaralar[b-1] , numaralar[b]);
				
				strcpy(numaralar[b] , t);
			}
			
				if(strcmp(isimler[b-1] , isimler[b]) > 0 ){ 

				strcpy(t , isimler[b-1]);
				
				strcpy(isimler[b-1] , isimler[b]);
				
				strcpy(isimler[b] , t);

				strcpy(t , soyadlar[b-1]);
				
				strcpy(soyadlar[b-1] , soyadlar[b]);
				
				strcpy(soyadlar[b] , t);

				strcpy(t , numaralar[b-1]);   
				       
				strcpy(numaralar[b-1] , numaralar[b]);
				
				strcpy(numaralar[b] , t); 
		}
		
		}
		
	}

	temp = baslangic; 
	
	fprintf(dosya, "%-30s\t%-30s\t%s\n\n", "AD", "SOYAD", "TELEFON");
	
	for(a = 0; a < eleman_sayisi; a++){
		
		strcpy(temp->adi, isimler[a] ); 
		
		strcpy(temp->soyadi, soyadlar[a] ); 
		
		strcpy(temp->tel_num, numaralar[a] );  

		fprintf(dosya, "%-30s\t%-30s\t%s\n\n", isimler[a], soyadlar[a], numaralar[a]);
		
		temp= temp->sonraki; 

	} 
	
	eleman_sayisi = 0;
}


int main(int argc, char *argv[]) {

	int secim = 0;

	char ad[30];

	char soyad[30];

	char numara[12];
	

	do {
		
		printf("\n\n\n\t\t  ----------------------------------------------------------------\n");
		
		printf("\t\t  ----------------------------------------------------------------\n\t\t  ||  \t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  \t\t\tTELEFON REHBERI\t\t\t\t||\n");
		
		printf("\t\t  ||  \t\t\t\t\t\t\t\t||\n");
		
		printf("\t\t  ||  \t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  1-Kisi Ekleme\t\t\t\t\t\t||\n\t\t  ||  \t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  2-Kisi Silme\t\t\t\t\t\t||\n\t\t  ||  \t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  3-Kisi Aramak\t\t\t\t\t\t||\n\t\t  ||  \t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  4-Rehberi listeleme\t\t\t\t\t||\n\t\t  ||\t\t\t\t\t\t\t\t||\n");
		
		printf("\t\t  ||  5-Rehberi paylas\t\t\t\t\t\t||\n\t\t  ||\t\t\t\t\t\t\t\t||\n");

		printf("\t\t  ||  Cikis yapmak icin 6'yi tuslayiniz\t\t\t\t||\n\t\t  ||  \t\t\t\t\t\t\t\t||\n");
	
		printf("\t\t  ----------------------------------------------------------------\n");
		
		printf("\t\t  ----------------------------------------------------------------\n\n");
		
		printf("\t\t\tLutfen [1-5] arasinda yapmak istediginiz islemi tuslayiniz : ");

		scanf("%d", &secim);

		system("cls");

		if(secim == 1) {

				printf("\nEklemek istediginiz kisinin adi :");

				scanf(" %[^\n]s", &ad);

				printf("\nEklemek istediginiz kisinin soyadi :");

				scanf(" %[^\n]s", &soyad);

				printf("\nEklemek istediginiz kisinin numarasi :");

				scanf("%s", &numara);

				kisi_ekle(ad, soyad, numara);

				sleep(1);

				system("cls");

		}

		else if(secim == 2){
		
				
				sirala();
				
				kisi_sil();

				sleep(1);

				system("cls");

		}

		else if(secim == 3) {
			
				printf("\nAramak istediginiz kisinin adi :");

				scanf("%[^\n]s", &ad);

				printf("\nAramak istediginiz kisinin soyadi :");

				scanf("%[^\n]s", &soyad);

				numara_bul(ad, soyad);

				sleep(3);

				system("cls");
			
		}
		
		else if(secim == 4) {
			
				printf("\n\n-----------Rehberdeki isimler------\n\n");

				sirala();

				system("cls");
			
		}

				
		else if(secim == 5) {
			
				printf("\n\nTelefon rehberi paylasiliyor...");
				
				sleep(3);
				
				kisi_paylas();
				
				system("cls");
				
				printf("\n\n\t\tTelefon rehberi telefon_rehberi.txt adli dosya ile paylasildi\n\n");
				
				sleep(2);
				
				system("cls");
			
		}
		
		else if(secim == 6){ 
			
			break;
			
		}
		
		else {
		
			printf("\nLutfen [1-5] arasinda tuslayiniz\n");
				
		}

	}while(secim != 6);
	
	
		printf("\n\n------------Uygulamadan cikis yapildi--------------\n\n");

		return 0;
		
}

