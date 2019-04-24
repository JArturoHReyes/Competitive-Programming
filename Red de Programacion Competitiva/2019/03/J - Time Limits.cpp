#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n;

ll m , e , mi;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    mi = LLONG_MIN;

    while(n--)
    {
        cin >> e;

        mi = max(mi , e);
    }

    mi *= m;

    while(mi % 1000 != 0)
    {
        mi++;
    }

    cout << mi / 1000 << endl;

    return 0;
}
