#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

ll x[maxn] , y[maxn] , r[maxn] , p[maxn];

ll n , m , s;

bool inside(int i , int j)
{
    return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) <= ((r[i] + r[j]) * (r[i] + r[j]));
}

int find(int v)
{
    while(v != p[v])
    {
        v = p[v];
    }

    return v;
}

void unite(int i  , int j)
{
    int pi = find(i);

    int pj = find(j);

    p[pi] = pj;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> s;

    for(int i = 0; i < s; i++)
    {
        cin >> x[i] >> y[i] >> r[i];

        p[i] = i;
    }

    for(int i = 0; i < 4; i++)
    {
        p[s + i] = s + i;
    }

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(inside(i , j))
            {
                unite(i , j);
            }
        }

        if(x[i] <= r[i])
        {
            unite(i , s);
        }

        if((m - x[i]) <= r[i])
        {
            unite(i , s + 1);
        }

        if(y[i] <= r[i])
        {
            unite(i , s + 2);
        }

        if((n - y[i]) <= r[i])
        {
            unite(i , s + 3);
        }
    }

    unite(s , s + 3);

    unite(s + 2, s + 1);

    if(find(s) == find(s + 2))
    {
        cout << "N" << endl;

        return 0;
    }

    cout << "S" << endl;

}
