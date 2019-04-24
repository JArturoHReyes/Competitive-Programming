#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

ll ans;

void dp(int e , int o , int i , ll n)
{
    if(e == 0 && o == 0)
    {
        ans += n;

        return;
    }

    if(e)
    {
        if(i)
        {
            // We can put five digits

            dp(e - 1 , o , i + 1 , n * 5ull);
        }
        else
        {
            // We can put four digits

            dp(e - 1 , o , i + 1 , n * 4ull);
        }
    }

    if(o)
    {
        dp(e , o - 1 , i + 1 , n * 5ull);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int e , o;

    while(cin >> e >> o && !(e == 0 && o == 0))
    {
        ans = 0;

        dp(e , o , 0 , 1ull);

        cout << ans * 2 + (e == 1 && o == 0) << endl;
    }


    return 0;
}
