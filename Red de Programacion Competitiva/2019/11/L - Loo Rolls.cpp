#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll l , n , a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> n;

    a = 1;

    while(l % n)
    {
        n -= (l % n); 

        a++;
    }

    cout << a << endl;

    return 0;
}
