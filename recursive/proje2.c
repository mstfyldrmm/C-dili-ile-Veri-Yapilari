#include <stdio.h>
#include <stdlib.h>


int us_alma(int taban, int kuvvet) {
	
	if(kuvvet == 1) 
	
	return taban;
	
	else if(kuvvet == 0) 
	
	return 1;
	 
	
	else {
		
		return us_alma(taban, kuvvet-1)*taban;
		
		
	}
}





int main() {

	printf("3 uzeri 5 : %d", us_alma(1, 97897));
	
	
	
	
	
	
	return 0;
}
