#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int rocks , ponds;

int gcd[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    string x;

    cin >> x;

    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] == 'R')
        {
            rocks++;
        }
        else
        {
            ponds++;
        }
    }

    if(ponds == 0)
    {
        cout << rocks - 1 << endl;
        return 0;
    }

    // Let's get all the divisors of the size of the arena

    int n = x.length();

    vector < int > divisors;

    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            divisors.emplace_back(i);

            if(i * i == n)
            {
                break;
            }

            divisors.emplace_back(n / i);
        }
    }

    for(int i = 2; i < n; i++)
    {
        gcd[__gcd(i , n)]++;
    }

    int ans = 0;

    // We should jump from a divisor in divisor

    for(int i = 0; i < divisors.size(); i++)
    {
        bool ok = false;

        for(int j = 0; j < divisors[i]; j++)
        {
            bool nopond = true;

            for(int k = j; k < n; k += divisors[i])
            {
                if(x[k] == 'P')
                {
                    nopond = false;
                    break;
                }
            }

            if(nopond)
            {
                ok = true;
                break;
            }
        }

        if(ok)
        {
            ans += gcd[divisors[i]];
        }
    }

    cout << ans << endl;



    return 0;
}
