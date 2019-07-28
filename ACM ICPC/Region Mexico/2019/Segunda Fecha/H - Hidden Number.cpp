#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1000010
using namespace std;

int n;

ll a[maxn];

ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a , a + n);

    ans = 1;

    for(int i = 0; i < n && a[i] <= ans; i++)
    {
        ans += a[i];
    }

    cout << ans << endl;


    return 0;
}
