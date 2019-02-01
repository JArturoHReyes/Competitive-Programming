#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int prices[maxn] , n , k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    //freopen("in.txt" , "r" , stdin);

    while(cin >> n >> k)
    {
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> prices[i];

            sum += prices[i];
        }

        multiset < int > S;

        for(int i = 0; i < n; i++)
        {
            S.insert(prices[i]);

            int freenights = (i + 1) / (k + 1);

            while(S.size() > freenights)
            {
                S.erase(S.begin());
            }
        }

        cout << sum - accumulate(S.begin() , S.end() , 0) << endl;
    }

    return 0;

}
