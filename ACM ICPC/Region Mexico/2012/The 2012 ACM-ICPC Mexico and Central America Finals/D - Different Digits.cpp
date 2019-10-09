#include<bits/stdc++.h>
#define endl '\n'
#define maxn 5010
using namespace std;

int a[maxn];

bool d[10];

int x , y;

int ok(int f)
{
    memset(d , 0 , sizeof(d));
    
    while(f)
    {
        if(d[f % 10])
        {
            return 0;
        }
        
        d[f % 10] = true;
        
        f /= 10;
    }
    
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 5000; i++)
    {
        a[i] = a[i - 1] + ok(i);
    }
    
    while(cin >> x >> y)
    {
        cout << a[y] - a[x - 1] << endl;
    }
    
    return 0;
}
