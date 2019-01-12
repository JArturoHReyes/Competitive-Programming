#include<bits/stdc++.h>
#define endl '\n'
#define ll long double
#define maxn 200010
using namespace std;

int a , b , c , d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(2) << fixed;
    
    scanf("%d.%d.%d.%d" , &a , &b , &c , &d);
    
    bitset < 8 > e(a);
    
    bitset < 8 > f(b);
    
    bitset < 8 > g(c);
    
    bitset < 8 > h(d);
    
    cout << e << f << g << h << endl;  
    
    return 0;
}
