#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n , ans;

int a , dp[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextL.txt" , "r")) freopen("ArturoTextL.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a;

        dp[a] = dp[a - 1] + 1;

        ans = max(ans , dp[a]);
    }

    cout << n - ans << endl;

    return 0;
}
