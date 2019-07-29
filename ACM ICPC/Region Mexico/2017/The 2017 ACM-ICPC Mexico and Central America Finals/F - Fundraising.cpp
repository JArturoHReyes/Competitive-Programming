#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n;

struct node
{
    ll b , f , d;

    node(ll ob , ll of , ll od)
    {
        b = ob;
        f = of;
        d = od;
    }

    node()
    {

    }

};

bool operator < (node x , node y)
{
    if(x.b != y.b)
    {
        return x.b < y.b;
    }

    if(x.f != y.f)
    {
        return x.f > y.f;
    }

    return x.d > y.d;
}

vector < node > v;

map < pair < int , int > , ll > group;

map < ll , ll > m;

int bi , fi;

ll di , maxi;

set < ll > s;

ll tree[maxn];

ll ldx = 1e5 + 5;

ll read(int idx)
{
    ll sum = 0;

    while(idx > 0)
    {
        sum = max(sum , tree[idx]);

        idx -= (idx & -idx);
    }

    return sum;
}

void update(int idx , ll val)
{
    while(idx <= ldx)
    {
        tree[idx] = max(tree[idx] , val);

        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> bi >> fi >> di;

        group[{bi , fi}] += di;
    }

    for(auto it = group.begin(); it != group.end(); it++)
    {
        auto t = it->first;

        ll total = it->second;

        v.push_back(node(t.first , t.second , total));
    }

    sort(v.begin() , v.end());

    n = v.size();

    for(int i = 0; i < v.size(); i++)
    {
        s.insert(v[i].f);
    }

    int cnt = 1;

    for(ll in : s)
    {
        m[in] = cnt++;
    }

    for(int i = 0; i < n; i++)
    {
        v[i].f = m[v[i].f];
    }

    ll last = v[0].b;

    for(int i = 0; i < v.size();)
    {
        while(i < v.size())
        {
            if(v[i].b != last)
            {
                break;
            }

            ll val = read(v[i].f - 1);

            ll g = read(v[i].f);

            ll k = max(val + v[i].d , g);

            update(v[i].f , k);

            maxi = max(maxi , k);

            i++;
        }

        if(i == v.size())
        {
            break;
        }

        last = v[i].b;
    }

    cout << maxi << endl;

    return 0;
}
