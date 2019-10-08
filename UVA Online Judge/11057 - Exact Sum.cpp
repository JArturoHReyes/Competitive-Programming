#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

int n;

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        sort(a , a + n);
        
        int m;
        
        cin >> m;
        
        int diff = 1e8;
        
        int a1 = a[0] , a2 = a[n - 1];
        
        int le = 0 , ri = n - 1 , b12 = abs(a[0] - a[n - 1]);
        
        while(le < ri)
        {
            int actual = a[le] + a[ri];
            
            int di = abs(m - actual);
            
            if(di < diff)
            {
                diff = di;
                
                a1 = a[le];
                
                a2 = a[ri];
                
                b12 = abs(a1 - a2);
            }
            else
            {
                if(diff == di)
                {
                    if(abs(a[le] - a[ri]) < b12)
                    {
                        a1 = a[le];
                        
                        a2 = a[ri];
                        
                        b12 = abs(a[le] - a[ri]);
                    }
                }
            }
            
            if(actual > m)
            {
                ri--;
            }
            else
            {
                if(actual < m)
                {
                    le++;
                }
                else
                {
                    ri--;
                }
            }
        }
        
        cout << "Peter should buy books whose prices are " << a1 << " and " << a2 << "." << endl << endl;
    }
    
    
    return 0;
}
