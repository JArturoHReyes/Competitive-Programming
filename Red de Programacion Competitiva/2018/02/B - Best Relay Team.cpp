#include<bits/stdc++.h>
#define endl '\n'
#define maxn 510
using namespace std;

int n , cond;

string x[maxn];

pair < double , int > fl[maxn];

pair < double , int > ol[maxn];

double ans , actual;

vector < string > nans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> fl[i].first >> ol[i].first;

        fl[i].second = ol[i].second = i;
    }

    sort(fl , fl + n);

    sort(ol , ol + n);

    ans = 1e8;

    for(int i = 0; i < n; i++)
    {
        actual = fl[i].first;

        cond = 3;

        vector < string > nactual;

        nactual.push_back(x[fl[i].second]);

        for(int j = 0; j < cond; j++)
        {
            if(ol[j].second == fl[i].second)
            {
                cond++;
                continue;
            }

            actual += ol[j].first;

            nactual.push_back(x[ol[j].second]);
        }

        if(actual < ans)
        {
            ans = actual;

            nans = nactual;
        }
    }

    cout << ans << endl;

    for(string g : nans)
    {
        cout << g << endl;
    }

    return 0;
}
