#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    //freopen("in.txt" , "r" , stdin);

    int n , c , s , k;

    while(cin >> n >> c >> s)
    {
        int pos = 1 , ans = 0;

        if(s == 1)
        {
            ans++;
        }

        while(c--)
        {
            cin >> k;

            if(k == 1)
            {
                pos++;
            }
            else
            {
                pos--;
            }

            if(pos > n)
            {
                pos = 1;
            }

            if(pos < 1)
            {
                pos = n;
            }

            if(pos == s)
            {
                ans++;
            }
        }


        cout << ans << endl;
    }

    return 0;

}
