#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a , b;

int bi[100];

ll memo[100][2][100];

ll dp(int pos , int edge , int sum)
{
    if(pos == -1)
    {
        return sum;
    }
    
    if(memo[pos][edge][sum] != -1)
    {
        return memo[pos][edge][sum];
    }
    
    ll ret = 0;
    
    if(edge)
    {
        ret += dp(pos - 1 , edge , sum) + dp(pos - 1 , edge , sum + 1);
    }
    else
    {
        if(bi[pos] == 0)
        {
            ret += dp(pos - 1 , edge , sum);
        }
        else
        {
            ret += dp(pos - 1 , 0 , sum + 1) + dp(pos - 1 , 1 , sum);
        }
    }
    
    memo[pos][edge][sum] = ret;
    
    return ret;
}

ll f(ll x)
{
    int pos = 0;
    
    while(x)
    {
        bi[pos++] = x % 2;
        
        x /= 2;
    }
    
    memset(memo , -1 , sizeof(memo));
    
    return dp(pos - 1 , 0 , 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> a >> b)
    {
        cout << f(b) - f(a - 1) << endl;
    }
    
    return 0;
}
