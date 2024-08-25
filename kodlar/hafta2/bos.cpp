     
    
void sil(int sayi) {
	
	int kontrol = 0;
    
    if (ilk_node->veri == sayi) {
    	
        node_sil = ilk_node;
        
        ilk_node = ilk_node->next;
        
        free(node_sil);
    }    
	
	else {
    	
    gecici_node = ilk_node;
        
       while (gecici_node->next != NULL) { 
 
         if (gecici_node->next->veri == sayi) {
            	
            kontrol = 1;
                
        	node_sil = gecici_node->next; 
 
            if (node_sil == son_node) 
                
            son_node = gecici_node;
                    
            gecici_node->next = node_sil->next; 
                
            free(node_sil);
                
            break;
 
            }
            gecici_node = gecici_node->next;
        }
    }
    if (kontrol == 0)
    
        printf("Silmek Istediginiz Eleman Listede Yoktur...\n");
        
    else
    
        printf("%d sayisi listeden silinmiþtir...\n", sayi);
}

 
