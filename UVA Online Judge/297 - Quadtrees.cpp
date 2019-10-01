#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t;

string a , b;

struct qt
{
    vector < bool > tree;
    
    string str;
    
    qt(string &s)
    {
        tree.assign(1024 , 0);
        
        str = s;
        
        int idx = -1;
        
        bt(idx , 0 , 1024);
    }
    
    void bt(int &idx , int s , int e)
    {
        ++idx;
        
        if(str[idx] == 'p')
        {
            int chunk = (e - s) / 4;
            
            for(int i = 0; i < 4; i++)
            {
                bt(idx , s + i * chunk , s + (i + 1) * chunk);
            }
        }
        else
        {
            if(str[idx] == 'f')
            {
                for(int i = s; i < e; i++)
                {
                    tree[i] = true;
                }
            }
            else
            {
                return;
            }
        }
        
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
       cin >> a >> b;
       
       qt qa(a);
       qt qb(b);
       
       int ans = 0;
       
       for(int i = 0; i < 1024; i++)
       {
           ans += (qa.tree[i] | qb.tree[i]);
       }
       
       cout << "There are " << ans << " black pixels." << endl;
    }
    
    return 0;
}
