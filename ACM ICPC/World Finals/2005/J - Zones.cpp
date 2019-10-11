#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , b , m , k, perm , t , ans , ansperm , c;

int p[25];

map < int , int > inter;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    while(n)
    {
       cin >> b;
       
       for(int i = 0; i < n; i++)
       {
           cin >> p[i];
       }
       
       inter.clear();
       
       ans = -1;
       
       cin >> m;
       
       for(int i = 0; i < m; i++)
       {
           cin >> k;
           
           perm = 0;
           
           for(int j = 0; j < k; j++)
           {
               cin >> t;
               
               t--;
               
               perm |= (1 << t);
           }
           
           cin >> k;
           
           inter[perm] = k;
       }
       
       for(int i = 0; i < (1 << n); i++)
       {
           if(__builtin_popcount(i) == b)
           {
               int actual = 0;
               
               for(int j = 0; j < n; j++)
               {
                   if(i & (1 << j))
                   {
                       actual += p[j];
                   }
               }
               
               for(auto it = inter.begin(); it != inter.end(); it++)
               {
                   int actualinter = (it->first) & i;
                   
                   int interp = __builtin_popcount(actualinter);
                   
                   if(interp > 1)
                   {
                       actual -= (interp - 1) * it->second;
                   }
               }
               
               if(ans < actual)
               {
                   ans = actual;
                   
                   ansperm = i;
               }
           }
       }
       
       cout << "Case Number  " << ++c << endl;
       
       cout << "Number of Customers: " << ans << endl;
       
       cout << "Locations recommended: ";
       
       int u = 0;
       
       for(int i = 0; i < n; i++)
       {
           if(ansperm & (1 << i))
           {
               u++;
               
               cout << i + 1;
               
               if(u != b)
               {
                   cout << " ";
               }
           }
       }
       
       cin >> n;
       
       cout << endl << endl;
    }
    
    return 0;
}
