#include <stdio.h>
#include <stdlib.h>

typedef struct dugum{
	
	struct dugum *next;
	
	struct dugum *prev;
	
	int deger;
	
	
}node;
 
 
 
 


int main() {
	
	node *dugum1;
	
	dugum1 = (node*)malloc(sizeof(node));
	
	dugum1->deger = 1;
	
	dugum1->next = NULL;
	
	dugum1->prev = NULL;
	
	dugum1->next = (node*)malloc(sizeof(node));
	
	dugum1->next->deger = 2;
	
	dugum1->prev = dugum1;
	
	dugum1->next->next = (node*)malloc(sizeof(node));
	
	dugum1->next->next->deger = 3;
	
	dugum1->next->next->prev = dugum1->next;
	
	dugum1->next->next->next = NULL;
	
	node *temp;
	
	temp = dugum1;
	
	while(temp->next != NULL) {
		
		printf("%d\n", temp->deger);
		
		temp = temp->next;
	}
	

	
	
	return 0;
}
