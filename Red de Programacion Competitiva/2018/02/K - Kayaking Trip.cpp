#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , low , high , ans , mid , p , v , tfi , tse;

int t[3];

int r[3];

int s[3];

int c[maxn];

bool can(int minimum)
{
    for(int i = 0; i < 3; i++)
    {
        r[i] = t[i];
    }

    for(int i = 0; i < n; i++)
    {
        tfi = -1 , tse = -1;

        for(int fi = 0; fi < 3; fi++)
        {
            for(int se = fi; se < 3; se++)
            {
                p = 1;

                if(fi == se)
                {
                    p++;
                }

                v = c[i] * (s[fi] + s[se]);

                if(r[fi] >= p && r[se] >= p && v >= minimum)
                {
                    if(tfi == -1 or (s[fi] + s[se]) < (s[tfi] + s[tse]))
                    {
                        tfi = fi;

                        tse = se;
                    }
                }
            }
        }

        if(tfi == -1)
        {
            return false;
        }

        r[tfi]--;

        r[tse]--;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)
    {
        cin >> t[i];

        n += t[i];
    }

    for(int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    n /= 2;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c , c + n);

    low = 1 , high = 1e9, ans = -1, mid = 0;

    while(low <= high)
    {
        mid = (low + high) >> 1;

        if(can(mid))
        {
            ans = mid;

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
