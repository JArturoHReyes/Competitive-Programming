#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

ll cnt , ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextE.txt" , "r")) freopen("ArturoTextE.txt" , "r" , stdin);

    cin >> x;

    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] == '1')
        {
            cnt++;

            ans += cnt;
        }
    }

    cout << ans << endl;

    return 0;
}
