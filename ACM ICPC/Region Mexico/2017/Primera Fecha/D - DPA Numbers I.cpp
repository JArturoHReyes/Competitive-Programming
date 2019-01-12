#include <stdio.h>


int main(void){

    int i, j, t, n, suma;

    scanf("%d", &t);

    for(i = 1; i <= t; i++){

        scanf("%d", &n);

        for(j = 1; j < n; j++){
                if(j==1){suma=0;}
            if(n%j == 0){
                suma+=j;
            }
        }
        if(suma < n ){
            printf("deficient\n");
        }

        if(suma == n){
            printf("perfect\n");
        }

        if(suma > n){
            printf("abundant\n");
        }
    }
    return 0;

}
