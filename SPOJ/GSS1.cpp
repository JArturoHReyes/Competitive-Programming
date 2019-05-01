#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define ll long long
#define maxn 50010
using namespace std;
using namespace __gnu_pbds;

typedef tree < int , null_type, less < int > , rb_tree_tag , tree_order_statistics_node_update > pbd_set;


struct node
{
    ll sum , prefixsum , suffixsum , maxsum;
};

node T[4 * maxn];

ll arr[maxn];

void build(int idx , int s , int e)
{
    if(s == e)
    {
        T[idx].sum = arr[s];
        
        T[idx].prefixsum = arr[s];
        
        T[idx].suffixsum = arr[s];
        
        T[idx].maxsum = arr[s];
    }
    else
    {
        int mid = (s + e) >> 1;
        
        build(2 * idx + 1 , s , mid);
        
        build(2 * idx + 2 , mid + 1 , e);
        
        T[idx].sum = T[2 * idx + 1].sum + T[2 * idx + 2].sum;
        
        T[idx].prefixsum = max(T[2 * idx + 1].prefixsum , T[2 * idx + 1].sum + T[2 * idx + 2].prefixsum);
        
        T[idx].suffixsum = max(T[2 * idx + 2].suffixsum , T[2 * idx + 2].sum + T[2 * idx + 1].suffixsum);
        
        T[idx].maxsum = max(T[idx].prefixsum , max(T[idx].suffixsum , max(T[2 * idx + 1].maxsum , max(T[2 * idx + 2].maxsum , T[2 * idx + 1].suffixsum + T[2 * idx + 2].prefixsum))));
    }
}

node query(int idx , int s , int e , int l , int r)
{
    node ret;
    
    ret.sum = LLONG_MIN;
    
    ret.prefixsum = LLONG_MIN;
    
    ret.suffixsum = LLONG_MIN;
    
    ret.maxsum = LLONG_MIN;
    
    if(r < s or l > e)
    {
        return ret;
    }
    
    if(l <= s and e <= r)
    {
        return T[idx];
    }
    
    int mid = (s + e) >> 1;
    
    if(l > mid)
    {
        return query(2 * idx + 2 , mid + 1 , e , l , r);
    }
    
    if(r <= mid)
    {
        return query(2 * idx + 1 , s , mid , l , r);
    }
    
    node nodeleft = query(2 * idx + 1 , s , mid , l , r);
    
    node noderight = query(2 * idx + 2 , mid + 1 , e , l , r);
    
    ret.sum = nodeleft.sum + noderight.sum;
   
    ret.prefixsum = max(nodeleft.prefixsum , nodeleft.sum + noderight.prefixsum);
    
    ret.suffixsum = max(noderight.suffixsum, noderight.sum + nodeleft.suffixsum);
    
    ret.maxsum = max(ret.prefixsum , max(ret.suffixsum , max(nodeleft.maxsum , max(noderight.maxsum , nodeleft.suffixsum + noderight.prefixsum))));
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n , m , x , y;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cin >> m;
    
    build(0 , 0 , n - 1);
    
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        
        cout << query(0 , 0 , n - 1 , x - 1 , y - 1).maxsum << endl;
    }
    
    
    return 0;
}
