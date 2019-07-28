#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define ll long long
using namespace std;

int n , q;

ll a[maxn] , k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextG.txt" , "r")) freopen("ArturoTextG.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> q;

    while(q--)
    {
        cin >> k;

        if(a[k - 1] % 5 == 0)
        {
            cout << a[k - 1] / 5 << endl;
        }
        else
        {
            cout << (a[k - 1] / 5) + 1 << endl;
        }
    }

    return 0;
}
