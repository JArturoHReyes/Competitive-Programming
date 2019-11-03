#include<bits/stdc++.h>
#define endl '\n'
#define maxn 610
using namespace std;

bool c[maxn][maxn][4];

bool v[maxn][maxn];

int n , x , y , ans;

char s;

int dx[] = {-1 , 1 , 0 , 0};

int dy[] = {0 , 0 , 1 , -1};

void bfs(int i , int j)
{
    v[i][j] = true;

    queue < pair < int , int > > q;

    q.push(make_pair(i , j));

    while(!q.empty())
    {
        auto t = q.front();

        q.pop();

        for(int k = 0; k < 4; k++)
        {
            x = t.first + dx[k];

            y = t.second + dy[k];

            if(min(x , y) >= 0 && x < (2 * n) && y < (2 * n + 1) && !v[x][y] && c[t.first][t.second][k])
            {
                v[x][y] = true;

                q.push(make_pair(x , y));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n)
    {
        memset(c , true , sizeof(c));

        memset(v , false , sizeof(v));

        ans = -1;

        for(int i = 0; i < 2 * n - 1; i++)
        {
            for(int j = 0; j < n; j++)
            {
                x = i;

                y = 2 * j + (i & 1);

                cin >> s;

                if(s == 'H')
                {
                    c[x][y][1] = false;
                    c[x][y + 1][1] = false;
                    c[x + 1][y][0] = false;
                    c[x + 1][y + 1][0] = false;
                }
                else
                {
                    c[x][y][2] = false;
                    c[x][y + 1][3] = false;
                    c[x + 1][y][2] = false;
                    c[x + 1][y + 1][3] = false;
                }
            }
        }

        for(int i = 0; i < 2 * n; i++)
        {
            for(int j = 0; j < 2 * n + 1; j++)
            {
                if(!v[i][j])
                {
                    ans++;
                    bfs(i , j);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}