#include <stdio.h>

int main(){

    int t;
    while(~scanf("%i",&t)){
        getchar();
        int a = 2*t-1 ;
        char j[7] = {0};
        for(int i= 0; i < a;i++ ){
            
            j[0] ^= getchar_unlocked();            
            j[1] ^= getchar_unlocked();
            j[2] ^= getchar_unlocked();
            j[3] ^= getchar_unlocked();
            j[4] ^= getchar_unlocked();
            j[5] ^= getchar_unlocked();
            j[6] ^= getchar_unlocked();
            
            getchar();
        }
        printf("%s\n",j);
    }

    return 0;
}