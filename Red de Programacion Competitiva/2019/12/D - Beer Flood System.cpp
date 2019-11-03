#include<bits/stdc++.h>
#define endl '\n'
#define maxn 4010
using namespace std;

int n , m , u , v;

vector < int > adj[maxn];

vector < int > matching;

vector < int > visited;

bool bpm(int actual , int s)
{
    for(int to : adj[actual])
    {
        if(visited[to] != s)
        {
            visited[to] = s;

            int mv = to - n;

            if(matching[mv] == -1 or bpm(matching[mv] , s))
            {
                matching[mv] = actual;

                return true;
            }
        }
    }

    return false;
}

int maxbpm()
{
    matching = vector < int > (n , -1);

    visited = vector < int > (2 * n , -1);

    int ret = 0;

    for(int i = 0; i < n; i++)
    {
        if(bpm(i , i))
        {
            ret++;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;

        u-- , v--;

        v += n;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    int maxedges = 2 * n - 2;

    int match = maxbpm();

    int need = maxedges - match;

    int remove = m - need;

    cout << remove << endl;

    return 0;
}
