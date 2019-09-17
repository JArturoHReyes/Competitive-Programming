#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , p , k , c;

vector < int > adj[100010];

bool u[100010];

multiset < int > ans;

bool visited[100010];

int dfs(int actual)
{	
	int maxi = 0;
	
	//cout << "actual = " << actual << endl;
	
	for(int i = 0; i < adj[actual].size(); i++)
	{
		int v = dfs(adj[actual][i]);
		
		ans.insert(v);
		
		maxi = max(maxi , v);
	}
	
	multiset < int > :: iterator it = ans.find(maxi);
	
	if(it != ans.end())
	{				
		if(actual != 0)
		{
			ans.erase(it);
		}
		else
		{
			ans.erase(it);
			ans.insert(*it + 1);
			//cout << *it + 1 << endl;
		}
	}
	
	//cout << "actual = " << actual << "maxi = " << maxi + 1 << endl;
	
	return maxi + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextD.txt" , "r")) freopen("ArturoTextD.txt" , "r" , stdin);

	cin >> n >> k;
	
	for(int i = 1; i < n; i++)
	{
		cin >> p;
		
		adj[p - 1].push_back(i);
	}
	
	dfs(0);
	
	int i = 1;
	
	//cout << "ans size = " << ans.size() << endl;
	
	multiset < int > :: iterator it = ans.end();
	
	for(it--; ; it--)
	{
		if(i > k)
		{
			break;
		}
		
		//cout << "it = " << *it << endl;
		
		c += *it;
		
		i++;
		
		if(it == ans.begin())
		{
			break;
		}
	}
	
	cout << c << endl;
	
	/*int h = min(k , (int) ans.size()) , c = 0;
	
	sort(ans.rbegin() , ans.rend());
	
	for(int i = 0; i < h; i++)
	{
		c += ans[i];
	}
	
	cout << c << endl;*/

    return 0;
}
