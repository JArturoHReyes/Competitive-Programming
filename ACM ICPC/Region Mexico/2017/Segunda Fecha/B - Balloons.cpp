#include <stdio.h>


int main(void){

    int N, B, X, arreglo[' '], i, suma, precio;

do{
    do{
       scanf("%d", &N);
    }while(N < 0 || N > 100);

    do{
       scanf("%d", &B);
    }while(B < 0 || B > 5000);

    if(N != 0 && B != 0){
        suma = 0;
        arreglo[N];

        for(i = 0; i < N;){

            scanf("%d", &precio);

                if(precio >= 1 && precio <= 500){
                    arreglo[i] = precio;
                    suma += arreglo[i];
                    i++;
                }

        }

        X = B / suma;
        printf("%d\n", X);

    }

}while(N != 0 && B != 0);


    return 0;
}
