#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n , m , id;

ll t[2 * maxn];

const ll inf = 1e18;

ll cost[maxn];

ll e , c , ans;

vector < ll > energy[maxn];

vector < ll > price[maxn];

void modify(int p , ll v)
{
    for(t[p += n] = v; p > 1; p >>= 1)
    {
        t[p >> 1] = min(t[p], t[p ^ 1]);
    }
}

ll query(int l , int r)
{
    ll res = inf;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = min(res, t[l++]);
        }

        if (r & 1)
        {
            res = min(res, t[--r]);
        }
    }

    return res;
}

ll sum(int i , int j)
{
    if(j < i)
    {
        return 0;
    }

    ll ret = cost[j];

    if(i)
    {
        return ret - cost[i - 1];
    }

    return ret;
}

ll add(ll x , ll y)
{
    x += y;

    if(x > inf)
    {
        return inf;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    for(int i = 1; i < n; i++)
    {
        cost[i] += cost[i - 1];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> id >> e >> c;

        energy[id - 1].push_back(e);

        price[id - 1].push_back(c);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        ll start = sum(0 , i - 1);

        modify(i , inf);

        for(int k = 0; k < energy[i].size(); k++)
        {
            int j = upper_bound(cost , cost + n , start + energy[i][k]) - cost;

            if(j > i)
            {
                ll cmp = add(query(i + 1 , j + 1) , price[i][k]);

                if(cmp < query(i , i + 1))
                {
                    modify(i , cmp);
                }
            }
        }
    }

    ans = query(0 , 1);

    if(ans < inf)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
