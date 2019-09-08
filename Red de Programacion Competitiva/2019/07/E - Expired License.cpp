#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 1e7 + 1e6;

bool notprime[maxn];

void sieve()
{
    notprime[0] = notprime[1] = true;

    for(int i = 2; i * i <= maxn; i++)
    {
        if(!notprime[i])
        {
            for(int j = i * i; j <= maxn; j += i)
            {
                notprime[j] = true;
            }
        }
    }
}

int t;

double a , b;

int x , y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextE.txt" , "r")) freopen("ArturoTextE.txt" , "r" , stdin);

    sieve();

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        x = round(a * 1e5) , y = round(b * 1e5);

        int g = __gcd(x , y);

        x /= g , y /= g;

        if(x == 1 && y == 1)
        {
            x = y = 2;
        }

        if(!notprime[x] && !notprime[y])
        {
            cout << x << " " << y << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
