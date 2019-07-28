#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t;

ll k;

const ll z = 1e9 + 7;

ll fpow(ll b , ll e)
{
    ll ret = 1;

    while(e > 0)
    {
        if(e & 1)
        {
            ret = ret * b % z;
        }

        b = b * b % z;

        e >>= 1;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextC.txt" , "r")) freopen("ArturoTextC.txt" , "r" , stdin);

    cin >> t;

    while(t--)
    {
        cin >> k;

        cout << (10 * fpow(9 , k - 1)) % z << endl;
    }

    return 0;
}
