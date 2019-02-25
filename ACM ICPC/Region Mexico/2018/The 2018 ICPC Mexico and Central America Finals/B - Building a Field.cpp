#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n , arco[maxn] , totalsum , middle , cnt , actualsum;

set < int > prefixsum;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arco[i];
        
        totalsum += arco[i];
        
        prefixsum.insert(totalsum);
    }
    
    if(totalsum & 1)
    {
        cout << 'N' << endl;
        
        return 0;
    }
    
    prefixsum.erase(totalsum);
    
    prefixsum.insert(0);
    
    middle = totalsum / 2;
    
    for(int i = 0; i < n; i++)
    {
        actualsum += arco[i];
        
        if(prefixsum.find((actualsum + middle) % totalsum) != prefixsum.end())
        {
            cnt++;
        }
    }
    
    if(cnt > 3)
    {
        cout << 'Y' << endl;
    }
    else
    {
        cout << 'N' << endl;
    }
    
    return 0;
}
