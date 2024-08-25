#include <stdio.h>
#include <stdlib.h>

struct blisteler{
	
	int veri;
	
	struct blisteler *gosterici;
	
	
	
};

int main() {
	
	struct blisteler *ilkdugum = (struct blisteler*)malloc(sizeof(struct blisteler));
	
	struct blisteler *ikincidugum = (struct blisteler*)malloc(sizeof(struct blisteler));
	
	struct blisteler *ucuncudugum = (struct blisteler*)malloc(sizeof(struct blisteler));
	
	ilkdugum->veri = 25;
	
	ilkdugum->gosterici = ikincidugum;
	
	ikincidugum->gosterici = ucuncudugum;
	
	ikincidugum->veri = (ilkdugum->veri) * 2;
	
	ucuncudugum->veri = (ilkdugum->veri) * 4;
	
	ucuncudugum->gosterici = NULL;
	
	printf("ilk dugum : %d \t ikinci dugum : %d \t ucuncu dugum : %d", ilkdugum->veri, ikincidugum->veri, ucuncudugum->veri);
	
	
	return 0;
}
