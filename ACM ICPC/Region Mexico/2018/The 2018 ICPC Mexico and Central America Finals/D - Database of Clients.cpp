#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n;

set < string > info;

string x;

string cleaner(string a)
{
    string ret = "";
    
    bool arroba = false;
    
    bool read = true;
    
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == '+')
        {
            read = false;
            
            continue;
        }
        
        if(a[i] == '@')
        {
            read = true;
            
            arroba = true;
            
            continue;
        }
        
        if(a[i] != '.' && read)
        {
            ret += a[i];
            
            continue;
        }
        
        if(a[i] == '.' && arroba)
        {
            ret += a[i];
        }
    }
    
    //cout << "ret = " << ret << endl;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(8) << fixed;
    
    cin >> n;
    
    while(n--)
    {
        cin >> x;
        
        info.insert(cleaner(x));
    }
    
    cout << info.size() << endl;
    
    return 0;
}
