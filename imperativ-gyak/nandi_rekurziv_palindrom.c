#include <stdio.h>


int reverseInt(int le, int fel){
	if (le == 0) {
		return fel;
	} else {
		int marad = le%10;  
		le /=10;
		fel *= 10;
		fel += marad;
		return reverseInt(le,fel);
	}
	
}

int main(){

	int szam;
	printf("Adjon meg egy számot: ");
	scanf("%d",&szam);
	
	int rev = reverseInt(szam,0);

	if (rev == szam){
		printf("A szám palindrom.\n");
	} else {
		printf("A szám nem palindrom.\n");
		printf("%d != %d\n",szam,rev);
	}	
}
