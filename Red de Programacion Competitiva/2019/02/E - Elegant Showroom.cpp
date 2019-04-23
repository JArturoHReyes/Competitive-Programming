#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 400
using namespace std;

ll dist[maxn][maxn];

string square[maxn];

int r , c , sx , sy , i , j , xx , yy;

vector < pair < int , int > > d;

pair < int , int > t;

int dx[] = {0 , 1 , 0 , -1};

int dy[] = {1 , 0 , -1 , 0};

ll ans;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for(i = 0; i < r; i++)
    {
        cin >> square[i];

        for(j = 0; j < c; j++)
        {
            dist[i][j] = LLONG_MAX;
        }
    }

    ans = LLONG_MAX;

    cin >> sx >> sy;

    queue < pair < int , int > > q;

    q.push({sx - 1 , sy - 1});

    dist[sx - 1][sy - 1] = 1;

    while(!q.empty())
    {
        t = q.front();

        q.pop();

        for(i = 0; i < 4; i++)
        {
            xx = t.first + dx[i];

            yy = t.second + dy[i];

            if(min(xx , yy) >= 0 && xx < r && yy < c && square[xx][yy] != '#')
            {
                if(dist[xx][yy] > dist[t.first][t.second] + (square[xx][yy] == 'c'))
                {
                    dist[xx][yy] = dist[t.first][t.second] + (square[xx][yy] == 'c');

                    q.push({xx , yy});
                }
            }
        }
    }

    for(i = 0; i < r; i++)
    {
        ans = min(ans , dist[i][0]);

        ans = min(ans , dist[i][c - 1]);
    }

    for(i = 0; i < c; i++)
    {
        ans = min(ans , dist[0][i]);

        ans = min(ans , dist[r - 1][i]);
    }

    cout << ans << endl;

    return 0;
}
