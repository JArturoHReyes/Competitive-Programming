#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , l;

int f[maxn];

void pre()
{
    int k = 1 , ans = 1;

    while(ans <= maxn)
    {
        f[l++] = ans;

        k++;

        ans *= k;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre();

    while(cin >> n && n)
    {
        int ans = 0;

        int pos = l - 1;

        while(n)
        {
            if(f[pos] <= n)
            {
                n -= f[pos];

                ans++;
            }
            else
            {
                pos--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
