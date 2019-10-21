#include<bits/stdc++.h>
#define endl '\n'
#define maxn 110
using namespace std;

int r , c , mro, mco;

int ro , co;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        cin >> ro;

        mro = max(mro , ro);
    }

    for(int i = 0; i < c; i++)
    {
        cin >> co;

        mco = max(mco , co);
    }

    if(mco == mro)
    {
        cout << "possible" << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}
