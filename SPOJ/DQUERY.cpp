#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1000010
using namespace std;

int bit[maxn];
	
int last_visit[maxn];
	
int ans[maxn];

int arr[maxn];

int n , q , x , y;

struct Query
{
    int l , r , idx;
};

Query queries[maxn];

bool cmp(Query x , Query y)
{
    return x.r < y.r;
}

void update(int idx , int val)
{
    for (; idx <= n; idx += idx &- idx)
    {
        bit[idx] += val;
    }
}

int query(int idx)
{
    int sum = 0;
    
    for (; idx > 0; idx -= idx &- idx)
    {
        sum += bit[idx];
    }
        
    return sum;
}
 
void answeringQueries()
{
    memset(last_visit, -1, sizeof(last_visit));
    
    int query_counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (last_visit[arr[i]] != -1)
        {
            update(last_visit[arr[i]] + 1 , -1);
        }
            
        last_visit[arr[i]] = i;
        
        update(i + 1 , 1);
        
        while (query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] = query(queries[query_counter].r + 1) - query(queries[query_counter].l);
            
            query_counter++;
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
	    cin >> arr[i];
	}
	
	cin >> q;
	
	for(int i = 0; i < q; i++)
	{
		cin >> x >> y;
		
		x-- , y--;
		
		queries[i].l = x;
		
		queries[i].r = y;
		
		queries[i].idx = i;
	}
	
	sort(queries , queries + q , cmp);
	
	answeringQueries();
	
    return 0;
}
