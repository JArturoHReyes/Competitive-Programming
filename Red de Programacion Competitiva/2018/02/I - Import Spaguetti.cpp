#include<bits/stdc++.h>
#define endl '\n'
#define maxn 510
using namespace std;

int n , k , ans;

string x[maxn];

int dist[maxn];

int p[maxn];

map < string , int > info;

vector < int > adj[maxn];

string s;

char c;

int source;

vector < int > path;

void bfs(int actual)
{
    for(int i = 0; i < n; i++)
    {
        dist[i] = 1e9;
    }

    queue < int > q;

    for(int to : adj[actual])
    {
        dist[to] = 1;

        q.push(to);

        p[to] = actual;
    }

    p[actual] = -1;

    while(!q.empty())
    {
        actual = q.front();

        q.pop();

        for(int to : adj[actual])
        {
            if(dist[to] == 1e9)
            {
                dist[to] = dist[actual] + 1;

                q.push(to);

                p[to] = actual;
            }
        }
    }

    if(dist[source] < ans)
    {
        ans = dist[source];

        path.clear();

        path.push_back(source);

        if(ans != 1)
        {
            actual = p[source];

            while(actual != source)
            {
                path.push_back(actual);

                actual = p[actual];
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    ans = 1e9;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];

        info[x[i]] = i;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> s >> k;

        for(int j = 0; j < k; j++)
        {
            cin >> s;

            s = "";

            c = getchar();

            while(c != '\n')
            {
                c = getchar();

                if(isalpha(c))
                {
                    s += c;
                }
                else
                {
                    if(c == ',')
                    {
                        adj[i].push_back(info[s]);

                        s = "";
                    }
                }
            }

            adj[i].push_back(info[s]);
        }
    }

    for(source = 0; source < n; source++)
    {
        bfs(source);
    }

    if(ans == 1e9)
    {
        cout << "SHIP IT" << endl;

        return 0;
    }

    for(int i = path.size() - 1; i >= 1; i--)
    {
        cout << x[path[i]] << " ";
    }

    cout << x[path[0]] << endl;

    return 0;
}
