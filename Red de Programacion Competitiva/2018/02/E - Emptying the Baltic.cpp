#include<bits/stdc++.h>
#define endl '\n'
#define maxn 510
#define ll long long
using namespace std;

int h , w , dx , dy , actualx , actualy , nextx , nexty;

ll m[maxn][maxn];

ll b[maxn][maxn];

ll actuald , ans , nextd;

set < pair < ll , pair < int , int > > > q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> m[i][j];

            b[i][j] = 1e9;
        }
    }

    cin >> dx >> dy;

    dx-- , dy--;

    b[dx][dy] = m[dx][dy];

    q.insert(make_pair(b[dx][dy] , make_pair(dx , dy)));

    while(!q.empty())
    {
        actuald = q.begin()->first;

        tie(actualx , actualy) = q.begin()->second;

        q.erase(q.begin());

        ans += max(0LL , -actuald);

        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                nextx = actualx + i;

                nexty = actualy + j;

                if(min(nextx , nexty) >= 0 && nextx < h && nexty < w)
                {
                    nextd = max(actuald , m[nextx][nexty]);

                    if(nextd < b[nextx][nexty])
                    {
                        b[nextx][nexty] = nextd;

                        q.insert(make_pair(nextd , make_pair(nextx , nexty)));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
