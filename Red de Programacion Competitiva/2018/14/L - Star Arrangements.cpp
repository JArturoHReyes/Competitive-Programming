#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextL.txt" , "r")) freopen("ArturoTextL.txt" , "r" , stdin);

    int s , f;

    cin >> s;

    f = (s + 1) / 2;

    cout << s << ":" << endl;

    for(int i = 2; i <= f; i++)
    {
        for(int j = i - 1; j <= i; j++)
        {
            int howmanytimes = s / (i + j);

            if((howmanytimes * i + howmanytimes * j) == s)
            {
                cout << i << "," << j << endl;
            }
            else
            {
                if(((howmanytimes + 1) * i + howmanytimes * j) == s)
                {
                    cout << i << "," << j << endl;
                }
                /*else
                {
                    howmanytimes++;

                    if(((howmanytimes * i + howmanytimes * j) == s))
                    {
                        cout << i << "," << j << endl;
                    }
                }*/
            }
        }
    }

    return 0;
}
