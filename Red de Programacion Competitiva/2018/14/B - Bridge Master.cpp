#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextB.txt" , "r")) freopen("ArturoTextB.txt" , "r" , stdin);

    int t , n , k , l;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        n -= 2;

        multiset  < int > num;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];

            num.insert(a[i]);
        }

        cin >> l;

        int mypoints = k + l;

        int myrank = 1;

        while(true && num.size() > 0)
        {
            auto high = --num.end();

            auto low = num.begin();

            //cout << "high = " << *high << endl;

            //cout << "low = " << *low << endl;

            if((*high + *low) >= mypoints)
            {
                num.erase(--num.end());
                num.erase(--num.end());

                myrank++;

                /*cout << "first" << endl;

                for(int g : num)
                {
                    cout << g << endl;
                }*/
            }
            else
            {
                while((*low + *high) < mypoints && low != high)
                {
                    low++;
                }

                low--;

                num.erase(low);
                num.erase(high);

                /*cout << "second" << endl;

                for(int g : num)
                {
                    cout << g << endl;
                }*/
            }
        }

        cout << myrank << endl;
    }

    return 0;
}
