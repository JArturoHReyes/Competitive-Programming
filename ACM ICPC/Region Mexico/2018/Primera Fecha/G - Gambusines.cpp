#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ull unsigned long long
#define eps 1e-8
#define maxn 101
#define ll long long
using namespace std;

ll t , g , r , c ,ii , jj;

ll m[maxn][maxn];

int dy[4] = {0 , 0 , 1 , -1};
int dx[4] = {1 , -1 , 0 , 0};

int floodfill(int i , int j)
{
    if(m[i][j] != 1)
    {
       return 0;
    }

    m[i][j] = -1;

    int res = 1;

    for(int k = 0; k < 4; k++)
    {
        ii = i + dx[k];
        jj = j + dy[k];

        if(min(ii , jj) >= 0 && ii < r && jj < c)
        {
            res += floodfill(ii , jj);
        }
    }

    return res;
}

int main()
{
    opt;

    cin >> t >> g >> r >> c;

    for(ll i = 0; i < r; i++)
    {
        for(ll j = 0; j < c; j++)
        {
           cin >> m[i][j];
        }
    }

    ll ans = 0 , cont = 0;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(m[i][j] == 1)
            {
                int y = floodfill(i , j);

                if(y >= t)
                {
                    ans += ((y - t) * g);
                    cont++;
                }
            }
        }
    }

    cout << cont << " " << ans << endl;

    return 0;

}
