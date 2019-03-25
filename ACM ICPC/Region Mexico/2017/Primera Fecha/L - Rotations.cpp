#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n , num;

ll x;

set < int > ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    while(n--)
    {
        cin >> x;
        
        bitset < 36 > b(x);
        
        num = 0;
        
        for(int i = 32; i < 36; i++)
        {
            b[i] = b[i - 32];
        }
        
        for(int i = 0 , j = 1; i <= 4; i++ , j *= 2)
        {
            num += (b[i] * j);
        }
        
        for(int i = 5; i < 36; i++)
        {
            ans.insert(num);
            
            num >>= 1;
            
            num += (b[i] * 16);
        }
        
        ans.insert(num);
        
        if(ans.size() == 32)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        
        ans.clear();
        
    }
    
    return 0;
}
