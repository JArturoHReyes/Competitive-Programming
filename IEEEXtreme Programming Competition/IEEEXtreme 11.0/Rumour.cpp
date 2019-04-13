#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t , cnt;

ll a , b;

map < ll , int > s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen("input.txt" , "r")) freopen("input.txt" , "r" , stdin);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        s.clear();

        cnt = 1;

        s[a] = 1;

        while(a != 1)
        {
            a /= 2;

            s[a] = ++cnt;
        }

        cnt = 0;

        while(s[b] == 0)
        {
            b /= 2;

            ++cnt;
        }

        cout << s[b] + cnt - 1 << endl;
    }

    return 0;
}
