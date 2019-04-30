#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
using namespace std;

int parent[maxn];

bool visited[maxn];

int t , n , m , child , q;

int lca(int x , int y)
{
    memset(visited , 0 , sizeof(visited));

    visited[x] = 1;

    while(parent[x] != x)
    {
        x = parent[x];

        visited[x] = 1;
    }

    while(visited[y] != 1)
    {
        y = parent[y];
    }

    return y - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x , y;

    cin >> n;

    for(int p = 1; p <= n; p++)
    {
        parent[p] = p;
    }

    for(int node = 1; node <= n; node++)
    {
        cin >> m;

        while(m--)
        {
            cin >> child;

            parent[child + 1] = node;
        }
    }

    cin >> q;

    while(q--)
    {
        cin >> x >> y;

        cout << lca(x + 1 , y + 1) << endl;
    }

    return 0;
}
