#include<bits/stdc++.h>
using namespace std;

long long int maximocomundivisor(long long int a , long long int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return maximocomundivisor(b , a % b);
    }
}

int main()
{
    long long int n , n1 , n2;
    while(cin >> n)
    {
        n1 = n * 3;
        n2 = 2 * n + 1;
        if(n1 % n2 == 0)
        {
            cout << n1 / n2 << endl;
        }
        else
        {
            long long n3 = maximocomundivisor(n1 , n2);
            cout << n1 / n3 << "/" << n2 / n3 << endl;
        }
    }

    return 0;
}
