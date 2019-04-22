#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

int t , n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        vector < int > a(26 , 0);

        for(int i = 0; i < n; i++)
        {
            a[x[i] - 'A']++;
        }

        string ans = "";

        char middle = '0';

        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < a[i] / 2; j++)
            {
                ans += char(i + 'A');
            }

            a[i] = a[i] & 1;
        }

        for(int i = 0; i < 26; i++)
        {
            if(a[i])
            {
                middle = char(i + 'A');

                break;
            }
        }

        cout << ans;

        if(middle != '0')
        {
            cout << middle;
        }

        reverse(ans.begin() , ans.end());

        cout << ans << endl;
    }

    return 0;
}
