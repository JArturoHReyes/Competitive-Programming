#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll z = 188888881;

int t;

bool noperiod;

map < ll , ll > idres;

vector < ll > acumul , periods;

ll start;

ll fpow(ll b , ll e)
{
    ll ret = 1;

    while(e)
    {
        if(e & 1)
        {
            ret = (ret * b) % z;
        }

        b = (b * b) % z;

        e >>= 1;
    }

    return ret;
}

void findperiod(ll a , ll b)
{
    idres.clear();

    acumul.clear();

    periods.clear();

    ll res = a % b;

    ll id = 0;

    start = 0;

    while(res != 0 && (idres.find(res) == idres.end()))
    {
        idres[res] = id;

        res *= 10;

        ll partialres = res / b;

        if(partialres == 0)
        {
            partialres = 1;
        }

        periods.push_back(partialres % z);

        if(acumul.empty())
        {
            acumul.push_back(partialres % z);
        }
        else
        {
            acumul.push_back((partialres * acumul[acumul.size()  - 1]) % z);
        }

        res = res % b;

        if(res == 0)
        {
            noperiod = true;
        }

        id++;
    }

    start = idres[res];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a , b , n;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> n;

        noperiod = false;

        findperiod(a , b);

        ll ndecimals = acumul.size();

        ll high = (n - start) % (ndecimals - start);

        ll partial = (n - start) / (ndecimals - start);

        if(!noperiod && n > ndecimals)
        {
            ll before , between , after;

            if(start > 0)
            {
                before = acumul[start - 1];
            }
            else
            {
                before = 1;
            }

            if(high == 0)
            {
                after = 1;
            }
            else
            {
                after = (acumul[high + start - 1] * fpow(before , z - 2) % z);
            }

            between = fpow(((acumul[ndecimals - 1]) * fpow(before , z - 2)) % z , partial);

            ll ans = (before * between * after) % z;

            cout << (ans + z) % z << endl;
        }
        else
        {
            if(!noperiod && n < ndecimals)
            {
                cout << acumul[n - 1] % z << endl;
            }
            else
            {
                if(n < ndecimals)
                {
                    cout << acumul[n - 1] % z << endl;
                }
                else
                {
                    cout << acumul[ndecimals - 1] % z << endl;
                }
            }
        }
    }

    return 0;
}
