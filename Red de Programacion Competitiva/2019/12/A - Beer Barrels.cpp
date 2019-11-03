#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a , b , c , k;

const ll z = 1e9 + 7;

ll fpow(ll ba , ll e)
{
    ll ret = 1;

    while(e)
    {
        if(e & 1)
        {
            ret = ret * ba % z;
        }

        e >>= 1;

        ba = ba * ba % z;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> k >> c;

    if(k == 0)
    {
        cout << 0 << endl;

        return 0;
    }

    if(a == c && b == c)
    {
        cout << k << endl;

        return 0;
    } 

    if(a != c && b != c)
    {
        cout << 0 << endl;

        return 0;
    }

    ll lal = fpow(2 , k - 1);

    lal = lal * k % z;

    cout << lal << endl;

    return 0;
}
