#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n;

pair < int , int > p[maxn];

set < pair < int , int > > s;

pair < int , int > diff(pair < int , int >  a , pair < int , int > b)
{
    return make_pair(a.first - b.first , a.second - b.second);
}

set < pair < int , int > > ans;

bool ok(pair < int , int > d)
{
    for(int i = 0; i < n; i++)
    {
        auto tsum = make_pair(p[i].first + d.first , p[i].second + d.second);

        auto tsub = make_pair(p[i].first - d.first , p[i].second - d.second);

        if(!s.count(tsum) && !s.count(tsub))
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

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;

        s.insert(p[i]);
    }

    for(int i = 1; i < n; i++)
    {
        auto t = diff(p[i] , p[0]);

        if(ok(t))
        {
            if(t.first < 0)
            {
                t = make_pair(-t.first , -t.second);
            }

            if(t.first == 0)
            {
                t.second = abs(t.second);
            }

            ans.insert(t);
        }
    }

    cout << ans.size() * 2 << endl;

    return 0;
}
