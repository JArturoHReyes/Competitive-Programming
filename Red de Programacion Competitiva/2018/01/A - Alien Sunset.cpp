#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1825010
using namespace std;

int sch[25] , st[25] , en[25] , maxi , active;

int n;

int freq[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> sch[i] >> st[i] >> en[i];

        st[i]++;

        if(st[i] > en[i])
        {
            st[i] -= sch[i];
        }

        maxi = max(maxi , sch[i]);
    }

    maxi *= 1825;

    for(int i = 0; i < n; i++)
    {
        for(int j = st[i]; j < maxi; j += sch[i])
        {
            freq[max(0 , j)]++;
        }

        for(int j = en[i]; j < maxi; j += sch[i])
        {
            freq[j]--;
        }
    }

    for(int i = 0; i < maxi; i++)
    {
        active += freq[i];

        if(!active)
        {
            cout << i << endl;

            return 0;
        }
    }

    cout << "impossible" << endl;

    return 0;
}
