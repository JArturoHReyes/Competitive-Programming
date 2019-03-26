#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 15
using namespace std;

int n , m , color[maxn] , a;

bool adj[maxn][maxn];

pair < int , int > degree[maxn];

bool cmp(pair < int , int > a , pair < int , int > b)
{
    return a.first > b.first;
}

void clean()
{
    for(int i = 0; i < n; i++)
    {
        color[i] = 0;
        
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while(cin >> n)
	{
	    if(n == 0)
	    {
	        cout << 0 << endl;
	    }
	    else
	    {
	        clean();
	    
            for(int i = 0; i < n; i++)
            {
                cin >> m;
                
                while(m--)
                {
                    cin >> a;
                    
                    adj[i][a - 1] = adj[a - 1][i] = 1;
                }
            }
            
            for(int i = 0; i < n; i++)
            {
                degree[i].first = 0;
                
                degree[i].second = i;
                
                for(int j = 0; j < n; j++)
                {
                    if(adj[i][j])
                    {
                        degree[i].first++;
                    }
                }
            }
            
            sort(degree, degree + n, cmp);
            
            int nextcolor = 1;
            
            for(int i = 0; i < n; i++)
            {
                int actual = degree[i].second;
                
                if(color[actual])
                {
                    continue;
                }
                
                color[actual] = nextcolor++;
                
                for(int j = i + 1; j < n; j++)
                {
                    if(!color[j] && !adj[i][j])
                    {
                        color[j] = color[actual];
                    }
                }
            }
            
            cout << nextcolor - 1 << endl;
	    }
	}
	
	return 0;
}
