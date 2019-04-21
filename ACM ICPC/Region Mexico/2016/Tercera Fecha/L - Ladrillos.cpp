#include<bits/stdc++.h>
#define endl '\n'
#define maxn 210
using namespace std;

int h , l , area;

int t[maxn][maxn];

int dx[] = {0 , 1 , 0 , -1};

int dy[] = {1 , 0 , -1 , 0};

int dfs(int i , int j, int c)
{
    int xx , yy , k;

    int ret = 1;

    t[i][j] = -1;

    for(k = 0; k < 4; k++)
    {
        xx = i + dx[k];

        yy = j + dy[k];

        if(min(xx , yy) >= 0 && xx < l && yy < h && t[xx][yy] == c)
        {
            ret += dfs(xx , yy , c);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> h;

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < h; j++)
        {
            cin >> t[i][j];
        }
    }

    int ans = INT_MAX;

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < h; j++)
        {
            if(t[i][j] != -1)
            {
                ans = min(ans , dfs(i , j , t[i][j]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
