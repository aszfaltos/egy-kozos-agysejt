#include <stdio.h>

int main(){
        int mask = 1;
        float f = -100.423321;
        void* p = &f;
        int number = *(int*)p;

        for(int i = 31; i >= 0; --i){
                int bit = mask << i & number;
                if (i == 30) {printf(" ");}
                if (i == 21) {printf(" ");}
                if (bit){
                        printf("%d", 1);
                } else {
                        printf("%d", 0);
                }
        }
        printf("\n");

        return 0;
}