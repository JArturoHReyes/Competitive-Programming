#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , m , b , me , s , i , w , d , a , j , ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    while(m--)
    {
        cin >> b >> me;

        s = 0;

        for(int k = 1; k < n; k++)
        {
            cin >> i;

            s += i;
        }

        if(s > b)
        {
            continue;
        }

        w = 0;

        d = 1;

        a = 0;

        if(s + me <= b)
        {
            w = me;
        }

        j = 5;

        while(j--)
        {
            if(s + d <= b)
            {
                a = max(a , d);
            }

            d *= 10;
        }

        ans += (a - w);
    }

    cout << ans << endl;

    return 0;
}
