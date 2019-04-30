#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

typedef tree < int , null_type, less < int > , rb_tree_tag , tree_order_statistics_node_update > pbd_set;

int q;

char t;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    pbd_set s;
    
    cin >> q;
    
    while(q--)
    {
        cin >> t >> n;
        
        if(t == 'I')
        {
            s.insert(n);
        }
        
        if(t == 'D')
        {
            s.erase(n);
        }
        
        if(t == 'K')
        {
            if(s.find_by_order(n - 1) != s.end())
            {
                cout << *s.find_by_order(n - 1) << endl;
            }
            else
            {
                cout << "invalid" << endl;
            }
        }
        
        if(t == 'C')
        {
            cout << s.order_of_key(n) << endl;
        }
    }
    
    
    return 0;
}
