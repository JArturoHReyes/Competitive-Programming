#include<bits/stdc++.h>
#define endl '\n'
#define maxn 55
using namespace std;

int t , n , q , u , v;

int dist[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> dist[i][j];
            }
        }

        for(int node = 0; node < n; node++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j] , dist[i][node] + dist[node][j]);
                }
            }
        }

        cin >> q;

        int ans = 0;

        while(q--)
        {
            cin >> u >> v;

            ans += dist[u - 1][v - 1];
        }

        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
