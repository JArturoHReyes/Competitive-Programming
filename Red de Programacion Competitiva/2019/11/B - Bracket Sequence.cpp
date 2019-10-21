#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define OPEN -1
#define CLOSE -2
#define iv vector < long long > :: iterator
using namespace std;

int n;

string x;

const ll z = 1e9 + 7;

ll dfs(iv * b, bool sum)
{
    ll res = sum? 0:1;

    for(++*b; **b != CLOSE; ++*b)
    {
        ll k = 0;

        if(**b == OPEN)
        {
            k = dfs(b , !sum);
        }
        else
        {
            k = **b;
        }

        if(sum)
        {
            res = (res + k) % z;
        }
        else
        {
            res = (res * k) % z;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector < ll > v;

    v.push_back(OPEN);

    for(int i = 0; i < n; i++)
    {
        cin >> x;

        if(x == "(")
        {
            v.push_back(OPEN);
        }
        else
        {
            if(x == ")")
            {
                v.push_back(CLOSE);
            }
            else
            {
                v.push_back(stoll(x));
            }
        }
    }

    v.push_back(CLOSE);

    auto it = begin(v);

    cout << dfs(&it , true) << endl;

    return 0;
}
