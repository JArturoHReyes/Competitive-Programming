#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

string x;

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> x && x[0] != '0')
    {
        x.erase(x.length() - 1 , 1);
        
        int n = stoi(x);
        
        map < ll , int > freq;
        
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            
            freq[a[i]] = i + 1;
        }
        
        bool ok = true;
        
        for(int i = 0; i < n && ok; i++)
        {
            freq[a[i]] = 0;
            
            for(int j = 1; j <= n / 3 && ok; j++)
            {
                if(freq[a[i] + j] > (i + 1))
                {
                    if(freq[a[i] + j + j] > (freq[a[i] + j]))
                    {
                        ok = false;
                    }
                }
            }
        }
        
        if(ok)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
