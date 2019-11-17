#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

struct person
{
    ll min_dist;

    int pos;
};

int p;

ll dist[maxn];

ll b;

int h;

person a[maxn];

vector < int > ans;

bool ok(int actual)
{
    if(actual - 1 >= 0 && dist[a[actual].pos + 1] - dist[a[actual - 1].pos] > b)
    {
        return false;
    }

    if(actual + 1 < h && dist[a[actual + 1].pos] - dist[a[actual].pos + 1] < max(a[actual].min_dist , a[actual + 1].min_dist))
    {
        if(a[actual + 1].pos != p - 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> b;

    cin >> p;

    for(int i = 0; i < p; i++)
    {
        cin >> dist[i];
    }

    cin >> h;

    for(int i = 0; i < h; i++)
    {
        cin >> a[i].min_dist >> a[i].pos;

        a[i].pos--;
    }

    int i = h;

    while(i--)
    {
        if(a[i].pos + 1 < p and ok(i))
        {
            ans.push_back(i + 1);

            a[i].pos++;

            i = min(i + 2 , h);
        }
    }

    if(a[0].pos != p - 1)
    {
        cout << "impossible" << endl;
    }
    else
    {
        for(int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << " ";
        }

        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
}
