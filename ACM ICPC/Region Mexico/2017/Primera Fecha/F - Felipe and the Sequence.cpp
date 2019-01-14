#include<stdio.h>

int main(void){

    int i;
    long long int t, s, a;

    scanf("%lli",&t);

    for(i = 0; i < t; i++){

    scanf("%lli",&s);

    a=(s*s)+((s*2));

    printf("%lli\n", a);

}

return 0;
}
