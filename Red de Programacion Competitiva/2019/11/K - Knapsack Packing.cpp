#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , e;

multiset < int > a , ans , newa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < (1 << n); i++)
    {
        cin >> e;

        a.insert(e);
    }

    while(a.size() > 1)
    {
        int mine = *++a.begin();

        ans.insert(mine);

        newa.clear();

        while(!a.empty())
        {
            auto it = a.begin();

            int nex = *it;

            int sum = nex + mine;

            a.erase(it);

            auto itsum = a.find(sum);

            if(itsum == a.end())
            {
                cout << "impossible" << endl;

                return 0;
            }

            a.erase(itsum);

            newa.insert(nex);
        }

        a = newa;
    }

    for(int j : ans)
    {
        cout << j << endl;
    }

    return 0;
}
