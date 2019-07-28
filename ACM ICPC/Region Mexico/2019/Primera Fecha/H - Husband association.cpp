#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , t;

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    cin >> n >> t;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a , a + n);

    int ans2 = t , cnt2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(ans2 - a[i] > 0)
        {
            cnt2++;

            ans2 -= a[i];
        }
        else
        {
            break;
        }
    }

    int ans1 = t , cnt1 = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(ans1 - a[i] > 0)
        {
            cnt1++;

            ans1 -= a[i];
        }

    }

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}
