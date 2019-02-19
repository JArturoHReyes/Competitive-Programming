#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

double a[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextK.txt" , "r")) freopen("ArturoTextK.txt" , "r" , stdin);

    double sum = 0.0 , actualsum , toget , prove;

    double ans = 0.0;

    for(int i = 0; i < 6; i++)
    {
        cin >> a[i];

        sum += ((i + 1) * a[i]);

        //cout << a[i] << endl;
    }

    if(sum != 3.5)
    {
        ans = 1e15;

        for(int i = 0; i < 6; i++)
        {
            //cout << "i = " << i << endl;

            actualsum = sum;
            actualsum -= ((i + 1) * a[i]);
            //cout << "actualsum = " << actualsum << endl;

            toget = 3.5 - actualsum;

            //cout << "toget = " << toget << endl;

            prove = toget / a[i];

            //cout << "prove = " << prove << endl;

            double g = (double) (i + 1);

            ans = min(ans , abs(g - prove));

            //cout << "ans = " << ans << endl;
        }
        //cout << "hi" << endl;
        cout << ans << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}
