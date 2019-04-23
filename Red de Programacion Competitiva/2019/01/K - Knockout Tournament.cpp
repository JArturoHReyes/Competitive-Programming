#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 5010
using namespace std;

int n;

int a[maxn];

vector < int > power;

double proba[15][maxn];

int twopower(int a)
{
    int ret = 1;

    while(ret < a)
    {
        ret <<= 1;
    }

    return ret;
}

double getproba(int pos)
{
    if(power[pos] == -1)
    {
        return 0.0;
    }

    return power[pos];
}

void go (int round , pair < int , int > &a , pair < int , int > &b)
{
    for(int i = a.first; i <= a.second; i++)
    {
        if(power[i] != -1)
        {
            double p = 0.0;

            for(int j = b.first; j <= b.second; j++)
            {
                if(power[j] != -1)
                {
                    p += proba[round - 1][j] * getproba(i) / (getproba(i) + getproba(j));
                }
            }

            proba[round][i] = p * proba[round - 1][i];
        }
    }
}

double solve(int round , vector < pair < int , int > > indexrounds)
{
    if(indexrounds.size() == 1)
    {
        return proba[round - 1][0];
    }

    vector < pair < int , int > > newindexrounds;

    for(int i = 0; i < indexrounds.size(); i += 2)
    {
        go(round , indexrounds[i] , indexrounds[i + 1]);

        go(round , indexrounds[i + 1] , indexrounds[i]);

        newindexrounds.emplace_back(indexrounds[i].first , indexrounds[i + 1].second);
    }

    return solve(round + 1 , newindexrounds);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1 , a + n);

    vector < pair < int ,int > > indexrounds;

    int sobran = twopower(n) - n;

    for(int i = 0; i < n; i++)
    {
        power.push_back(a[i]);

        if(sobran)
        {
            power.push_back(-1);

            sobran--;
        }
    }

    for(int i = 0; i < power.size(); i += 2)
    {
        double sum = getproba(i) + getproba(i + 1);

        proba[1][i] = getproba(i) / sum;

        proba[1][i + 1] = getproba(i + 1) / sum;

        indexrounds.emplace_back(i , i + 1);
    }

    cout << solve(2 , indexrounds) << endl;

    return 0;
}
