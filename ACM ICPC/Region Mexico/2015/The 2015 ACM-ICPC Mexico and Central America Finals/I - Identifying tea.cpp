#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int t , x , ans , j = 5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(j--)
    {
        cin >> x;

        if(t == x)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
