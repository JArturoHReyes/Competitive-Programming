#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int a , b , c , d , e , f;

    while(cin >> a >> b >> c >> d >> e >> f)
    {
        int ans = 0;
        if(d > a)
        {
            ans += (d - a);
        }
        if(e > b)
        {
            ans += (e - b);
        }
        if(f > c)
        {
            ans += (f - c);
        }

        cout << ans << endl;
    }

    return 0;
}
