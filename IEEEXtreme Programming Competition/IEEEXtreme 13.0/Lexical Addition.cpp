#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string filename = "u.txt";

ll n , a , b , d , rem , s;

const ll maxs = 1e5;

ll arr[maxs];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n >> a >> b;

    s = n / b;

    if(s > maxs)
    {
        cout << "NO" << endl;

        return 0;
    }

    rem = n % b;

    fill(arr , arr + s , b);

    if(rem != 0)
    {
        for(int i = 0; i < s; i++)
        {
            d = max(0LL , min(a - rem , b - a));

            rem += d;

            arr[i] -= d;
        }

        if(rem < a)
        {
            cout << "NO" << endl;

            return 0;
        }
    }

    cout << "YES" << endl;

    if(rem != 0)
    {
        cout << rem << " ";
    }

    for(int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
