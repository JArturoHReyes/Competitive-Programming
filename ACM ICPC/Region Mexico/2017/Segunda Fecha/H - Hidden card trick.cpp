#include<stdio.h>
int main(void)
{
long long int n;
    while(scanf("%lli",&n) && n)
    {
        long long ans = 1;
        long long ind = 1;
        while(ind + ans <= n)
        {
            ind += ans;
            ans = ans * 2;
        }
        long long f = n - ind;
        printf("%llu\n",(1+2*f));
    }
return 0;
}
