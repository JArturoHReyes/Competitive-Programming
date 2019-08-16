#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

set < int > adj[maxn];

set < pair < int , int > > info;

int n , m , a , b , u , v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    cin >> n >> m >> a >> b;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].insert(v);

        adj[v].insert(u);
    }

    for(int i = 1; i <= n; i++)
    {
        info.insert(make_pair(adj[i].size() , i));
    }

    // info is sorted by degree

    while(info.size() > 0)
    {
        auto s = *info.begin();

        auto t = *(--info.end());

        int actualsize = info.size();

        if(s.first >= a && actualsize - t.first - 1 >= b)
        {
            break;
        }

        if(s.first < a)
        {
            int actual = s.second;

            info.erase(make_pair(adj[actual].size() , actual));

            for(int to : adj[actual])
            {
                int size_to = adj[to].size();

                info.erase(make_pair(size_to , to));

                if(size_to > 1)
                {
                    info.insert(make_pair(size_to - 1 , to));
                }

                adj[to].erase(actual);
            }

            adj[actual].clear();

            continue;
        }

        if(actualsize - t.first - 1  < b && s != t)
        {
            int actual = t.second;
            
            info.erase(make_pair(adj[actual].size() , actual));

            for(int to : adj[actual])
            {
                int size_to = adj[to].size();

                info.erase(make_pair(size_to , to));

                if(size_to > 1)
                {
                    info.insert(make_pair(size_to - 1 , to));
                }

                adj[to].erase(actual);
            }

            adj[actual].clear();
        }
    }

    cout << info.size() << endl;

    return 0;

}
