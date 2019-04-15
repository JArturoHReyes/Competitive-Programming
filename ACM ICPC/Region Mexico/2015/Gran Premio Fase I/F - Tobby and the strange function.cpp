#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t;

ll n;

string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        n %= x.size();

        cout << x.substr(x.length() - n , n) << x.substr(0 , x.length() - n) << endl;
    }

    return 0;
}
