#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

bool isprime(int a)
{
    for(int i = 2; i * i <= a; i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    int n;
    
    cin >> n;
    
    while(!isprime(n))
    {
        n--;
    }
    
    cout << n << endl;

    return 0;

}
