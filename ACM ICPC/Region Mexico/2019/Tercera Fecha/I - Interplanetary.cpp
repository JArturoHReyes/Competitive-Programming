#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 410
#define maxq 100010
using namespace std;

int n , m , q , a , b , k , qt , stsize , u , v;

map < ll , vector < int > > st;

map < int , vector < pair < int , pair < int , int > > > > hottest , coldest;

ll d;

ll t[maxn] , ans[maxq];

ll dist[maxn][maxn] , dist2[maxn][maxn];

ll vertex[maxn];

int level[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];

        st[t[i]].push_back(i);

        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = 1e17;

            dist2[i][j] = 1e17;
        }

        dist[i][i] = 0;
    }

    stsize = st.size();

    int pos = 0;

    int actual = 1;

    for(auto it = st.begin(); it != st.end(); it++)
    {
        for(int av : it->second)
        {
            vertex[pos] = av;

            level[pos++] = actual;
        }

        actual++;
    }

    while(m--)
    {
        cin >> u >> v >> d;

        dist[u][v] = d;

        dist[v][u] = d;

        dist2[u][v] = d;

        dist2[v][u] = d;
    }

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> a >> b >> k >> qt;

        k = min(k , stsize);

        if(qt)
        {
            hottest[stsize - k + 1].push_back(make_pair(i , make_pair(a , b)));
        }
        else
        {
            coldest[k].push_back(make_pair(i , make_pair(a , b)));
        }
    }

    int coldestsize = coldest.size();

    int hottestsize = hottest.size();

    if(coldestsize)
    {
        int prevpos = 0;

        auto it = coldest.begin();

        while(it != coldest.end())
        {
            vector < int > nowv;

            while(prevpos != pos && level[prevpos] <= it->first)
            {
                nowv.push_back(vertex[prevpos++]);
            }

            for(int actualvertex : nowv)
            {
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        dist[i][j] = min(dist[i][j] , dist[i][actualvertex] + dist[actualvertex][j]);
                    }
                }
            }

            for(auto vt : it->second)
            {
                ans[vt.first] = dist[vt.second.first][vt.second.second];
            }

            it++;
        }
    }

    if(hottestsize)
    {
        int prevpos = pos - 1;

        auto it = hottest.end();

        it--;

        while(true)
        {
            vector < int > nowv;

            while(prevpos != -1 && level[prevpos] >= it->first)
            {
                nowv.push_back(vertex[prevpos--]);
            }

            for(int actualvertex : nowv)
            {
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        dist2[i][j] = min(dist2[i][j] , dist2[i][actualvertex] + dist2[actualvertex][j]);
                    }
                }
            }

            for(auto vt : it->second)
            {
                ans[vt.first] = dist2[vt.second.first][vt.second.second];
            }

            if(it == hottest.begin())
            {
                break;
            }

            it--;
        }
    }

    for(int i = 0; i < q; i++)
    {
        if(ans[i] == 1e17)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans[i] << endl;
        }
    }

}

/*

7 9
-53 -180 456 420 -210 15 150
1 2 2
1 3 1
2 3 4
2 4 2
2 5 5
3 4 6
6 4 10
4 5 4
3 7 2
4
1 5 2 1
1 2 1 1
5 6 1 0
1 7 2 1 */
