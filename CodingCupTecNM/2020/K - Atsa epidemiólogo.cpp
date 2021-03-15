#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 100010
using namespace std;

/* Graph Entry */
int n , m , u , v;

/* What is the limit of people with virus */
int limit;

/* Adjacency list */
vector < int > adj[MAXN];

/* I have reached this node? */
bool visited[MAXN];

/* For binary search */
int low, mid, high, ans;

/* When testing a solution how many people will have the virus */
int cnt;

/* Depth First Search in the graph*/
void dfs(int actual)
{
    visited[actual] = true;

    for(int nxt : adj[actual])
    {
        /* to > mid meaning = Can I pass here? */

        if(!visited[nxt] && nxt > mid)
        {
            cnt++;

            dfs(nxt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);

    /* n nodes m edges */

    cin >> n >> m;

    /* Construct the graph */

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    cin >> limit;

    /* The answer should be between 1 and n - 1 */

    low = 1;

    high = n - 1;

    ans = -1;

    while(low <= high)
    {
        mid = (low + high) >> 1; /* Assume mid vaccuns */

        memset(visited, false, sizeof(visited));

        cnt = 1;

        dfs(0);

        /* If it pass the limit then it's a good answer, try less vaccuns */

        if(cnt <= limit)
        {
            ans = mid;

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
