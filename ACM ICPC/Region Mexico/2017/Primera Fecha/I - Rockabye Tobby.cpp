#include <bits/stdc++.h>
#define endl '\n'
#define maxn 3010
using namespace std;

int t , x , y;

set < pair < int , pair < int , string > > > l;

string med;

int inc[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> x >> y;
        
        for(int i = 0; i < x; i++)
        {
            cin >> med >> inc[i];
            
            l.insert({inc[i],{i , med}});
        }
        
        for(int i = 0; i < y; i++)
        {
            auto t = *l.begin();
            
            l.erase(l.begin());
            
            cout << t.first << " " << t.second.second << endl;
            
            t.first += inc[t.second.first];
            
            l.insert(t);
        }
    }
    
    return 0;
}
