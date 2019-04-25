#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 5010
using namespace std;

int prime[720];

ll memo[maxn][maxn];

ll divisors[maxn];

const ll z = 1e9 + 7;

int t;

ll pascal(int i , int j)
{
    if(j == 0 || j == i)
    {
        return 1;
    }

    if(memo[i][j] != 0)
    {
        return memo[i][j];
    }

    return memo[i][j] = (pascal(i - 1 , j - 1) + pascal(i - 1 , j)) % z;
}

void sieve()
{
    bitset < 5010 > primes;

    int pf_idx = 0;

    for(int i = 2; i <= 5000; i++)
    {
        if(!primes[i])
        {
            for(int j = i * i; j <= 5000; j += i)
            {
                primes[j] = 1;
            }

            prime[pf_idx++] = i;
        }
    }
}


void precal()
{
    for(int i = 2; i <= 5000; i++)
    {
        int aux = i , divs = 1 , sum = 0 , j = 0;

        while(aux != 1)
        {
            sum = 1;

            while(aux % prime[j] == 0)
            {
                aux /= prime[j];

                sum++;
            }

            j++;

            divs = ((divs % z) * (sum % z)) % z;
        }

        divisors[i] = divs;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    precal();

    cin >> t;

    int n , k;

    while(t--)
    {
        cin >> n >> k;

        int sum = 0;

        int cnt = 1;

        int div_actual;

        for(int i = 2; i <= n; i++)
        {
            if(divisors[i] > k)
            {
                div_actual = k;
            }
            else
            {
                div_actual = divisors[i] - 1;
            }

            sum = ((sum % z) + ((div_actual) % z)) % z;

            if(divisors[i] - 1 > k)
            {
                cnt = ((cnt % z) * (pascal(divisors[i] - 1 , k) % z)) % z;
            }
        }

        cout << sum << " " << cnt << endl;
    }



    return 0;
}
