#include<bits/stdc++.h>
#define maxn 35
using namespace std;

char e = 10;

double dist[maxn][maxn];

map < string , int > id;

string c , u , v;

int n , m , t;

double conv;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n && n)
    {
        id.clear();

        cout << "Case " << ++t << ": ";

        memset(dist , 0.0 , sizeof(dist));

        for(int i = 0; i < n; i++)
        {
            cin >> c;

            id[c] = i;
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            cin >> u >> conv >> v;

            int uid = id.find(u)->second;

            int vid = id.find(v)->second;

            dist[uid][vid] = conv;
        }

        for(int node = 0; node < n; node++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][node] * dist[node][j] > dist[i][j])
                    {
                        dist[i][j] = dist[i][node] * dist[node][j];
                    }
                }
            }
        }

        int node = 0;

        for(; node < n; node++)
        {
            if(dist[node][node] > 1.0)
            {
                break;
            }
        }

        if(node == n)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
