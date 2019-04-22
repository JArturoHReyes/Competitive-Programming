#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t , n , ta , d;

int pos[15] , tab[110] , dice[1010];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> ta >> d;

        for(int i = 0; i < n; i++)
        {
            pos[i] = 0;
        }

        for(int i = 0; i < ta; i++)
        {
            cin >> tab[i];
        }

        for(int i = 0; i < d; i++)
        {
            cin >> dice[i];
        }

        vector < int > ans;

        int actualpos = 0;

        for(int i = 0; i < d; i++)
        {
            int newpos = pos[actualpos] + dice[i];

            newpos += tab[newpos];

            pos[actualpos] = newpos;

            /*cout << "i = " << i << endl;

            cout << "newpos = " << newpos << endl;

            cout << "person = " << actualpos << endl;*/

            int cnt = 0;

            if(pos[actualpos] == ta - 1)
            {
                ans.push_back(actualpos + 1);
            }

            actualpos++;

            actualpos %= n;

            while(pos[actualpos] == ta - 1 && cnt <= n)
            {
                actualpos++;

                actualpos %= n;

                cnt++;
            }

            if(cnt > n)
            {
                break;
            }
        }

        if(ans.size())
        {
            for(int i = 0; i < ans.size() - 1; i++)
            {
                cout << ans[i] << " ";
            }

            cout << ans[ans.size() - 1];
        }
        else
        {
            cout << -1;
        }

        cout << endl;
    }

    return 0;
}
