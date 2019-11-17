#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

string x , sx;

int p[maxn];

int n;

bool cmp(int a , int b)
{
    return x[a] < x[b];
}

vector < pair < int , int > > ans;

vector < vector < int > > get_graph()
{
    vector < vector < int > > g;

    for(int i = 0; i < n; i++)
    {
        if(p[i] != -1)
        {
            vector < int > v;

            int actual = i;

            int to = -1;

            while(p[actual] != -1)
            {
                swap(to , p[actual]);

                v.push_back(actual);

                actual = to;

                to = -1;
            }

            g.push_back(v);
        }
    }

    return g;
}

void gen(int a , int b , bool ok)
{
    if(ok)
    {
        swap(a , b);
    }

    ans.push_back(make_pair(a , b));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    n = x.length();

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    sort(p , p + n, cmp);

    sx = x;

    sort(sx.begin() , sx.end());

    for(auto adj : get_graph())
    {
        for(int i = 0 , j = adj.size(); j-- > 1; i = j)
        {
            gen(adj[i] , adj[j] , sx[adj[i]] < sx[adj[j]]);

            swap(sx[adj[i]] , sx[adj[j]]);
        }
    }

    for(auto t : ans)
    {
        cout << t.first + 1 << " " << t.second + 1 << endl;
    }

    return 0;
}
