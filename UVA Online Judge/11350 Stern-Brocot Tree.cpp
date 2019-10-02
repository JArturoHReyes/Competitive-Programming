#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int t;

string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> x;
        
        ll ln = 0 , ld = 1;
        
        ll mn = 1 , md = 1;
        
        ll rn = 1 , rd = 0;
        
        for(char c : x)
        {
            if(c == 'R')
            {
                ln = mn , ld = md;
            }
            else
            {
                rn = mn , rd = md;
            }
            
            mn = (ln + rn);
                
            md = (ld + rd);
        }
        
        cout << mn << "/" << md << endl;
    }
    
    return 0;
}
