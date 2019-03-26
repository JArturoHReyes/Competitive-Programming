#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int t , n , maxi;

int a[maxn] , lis[maxn] , lds[maxn];

void printlis()
{
    cout << "lis" << endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << lis[i] << " ";
    }
    
    cout << endl;
}

void printlds()
{
    cout << "lds" << endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << lds[i] << " ";
    }
    
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    
	    maxi = 1;
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	        
	        lis[i] = 1;
	        
	        lds[i] = 1;
	    }
	    
	    for(int i = 1; i < n; i++)
	    {
	        for(int j = 0; j < i; j++)
	        {
	            if(a[j] < a[i])
	            {
	                lis[i] = max(lis[i] , lis[j] + 1);
	            }
	        }
	    }
	    
	    for(int i = n - 2; i >= 0; i--)
	    {
	        for(int j = n - 1; j > i; j--)
	        {
	            if(a[j] < a[i])
	            {
	                lds[i] = max(lds[i] , lds[j] + 1);
	            }
	        }
	    }
	    
	    //printlis();
	    
	    //printlds();
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(maxi < (lds[i] + lis[i]))
	        {
	            maxi = lds[i] + lis[i];
	        }
	    }
	    
	    cout << maxi - 1 << endl;
	}
	
	return 0;
}
