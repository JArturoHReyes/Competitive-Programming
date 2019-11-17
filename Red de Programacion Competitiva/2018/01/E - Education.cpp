#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

pair < int , int > s[maxn];

pair < int , pair < int , int > > b[maxn];

int n , m;

int ans[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> s[i].first;

        s[i].second = i;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i].second.first;

        b[i].second.second = i;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i].first;
    }

    sort(s , s + n);

    sort(b , b + m);

    for(int i = 0; i < m; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(b[i].second.first >= s[j].first && !ans[s[j].second])
            {
                ans[s[j].second] = b[i].second.second + 1;

                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(!ans[i])
        {
            cout << "impossible" << endl;

            return 0;
        }
    }

    for(int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " ";
    }

    cout << ans[n - 1] << endl;

    return 0;
}
