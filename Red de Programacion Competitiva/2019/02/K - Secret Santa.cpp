#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define e 2.71828182845904523536
#include<cmath>
using namespace std;

ll n;

double fact[32] , d[32];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;

    fact[0] = fact[1] = d[0] = 1.0;

    for(int i = 2; i < 32; i++)
    {
        fact[i] = fact[i - 1] * i;

        d[i] = (d[i - 1] + d[i - 2]) * (i - 1);
    }

    cin >> n;

    if(n > 30)
    {
        cout << 1 - (1 / e) << endl;
    }
    else
    {
        cout << 1 - d[n] / fact[n] << endl;
    }

    return 0;
}
