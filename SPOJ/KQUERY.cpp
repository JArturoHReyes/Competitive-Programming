#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 30010
#define maxnq 230010
using namespace std;

int btree[maxn];

struct pos
{
    int l , r , p;

    ll v;
};

pos a[maxnq];

bool cmp(pos a,  pos b)
{
    if(a.v == b.v)
    {
        return a.l > b.l;
    }

    return a.v > b.v;
}


void update_it(int idx , int n)
{
    while(idx <= n)
    {
        btree[idx] += 1;

        idx += idx & (-idx);
    }
}

int read_it(int idx)
{
    int s = 0;

    while(idx > 0)
    {
        s += btree[idx];

        idx -= idx &(-idx);
    }

    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(btree , btree + maxn , 0);

    int n , q;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].v;


        a[i].l = 0;


        a[i].p = 0;


        a[i].r = i + 1;
    }

    cin >> q;

    int ans[q + 1];

    for(int i = n; i < n + q; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].v;

        a[i].p = i - n + 1;
    }

    sort(a , a + n + q , cmp);

    for(int i = 0; i < n + q; i++)
    {
        if(a[i].l == 0)
        {
            update_it(a[i].r , n + 9);
        }
        else
        {
           ans[a[i].p] = read_it(a[i].r) - read_it(a[i].l - 1);
        }
    }


    for(int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
