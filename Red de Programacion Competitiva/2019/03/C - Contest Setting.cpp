#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

map < int , int > freq;

int n , k , e;

const ll z =  998244353LL;

vector < ll > ans;

void printvector(vector < ll > f)
{
    for(int i = 0; i < f.size(); i++)
    {
        cout << "i -> " << i << " ans -> " << f[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> e;

        freq[e]++;
    }

    ans.push_back(1);

    for(auto t : freq)
    {
        vector < ll > ans2(ans.begin() , ans.end());

        ans2.push_back(0);

        //cout << "before ans2" << endl;

        //printvector(ans2);

        for(int i = 0; i < ans.size(); i++)
        {
            ans2[i + 1] = (ans2[i + 1] + t.second * ans[i]) % z;
        }

        //cout << "after ans2" << endl;

        //printvector(ans2);

        swap(ans , ans2);
    }

    if(k < ans.size())
    {
        cout << ans[k] << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}
