#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < char , int > freq;

string x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    for(int i = 0; i < 5; i++)
    {
        cin >> x;

        freq[x[0]]++;
    }

    int ans = 0;

    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        ans = max(ans , it->second);
    }

    cout << ans << endl;

    return 0;
}
