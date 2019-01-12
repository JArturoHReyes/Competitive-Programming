#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define pii pair < int , int >
using namespace std;

int n , m , ngive , nhave , cost, figure , allgive , allhave;

bool give[12]; 

vector < int > freefigures;

vector < pair < int , int > > info[1 << 12];

void clean()
{
    memset(give , 0 , sizeof(give));
    
    freefigures.clear();
    
    allgive = 0;
    
    allhave = 0;
}

void dijkstra(int source , int dest)
{
    vector < int > dist(1 << n , 1e9);
    
    dist[source] = 0;
    
    priority_queue < pii  , vector < pii > , greater < pii > > Q;
    
    Q.push(pii(0 , source));
    
    while(!Q.empty())
    {
        pii pairactual = Q.top();
        
        Q.pop();
        
        int actualdist = pairactual.first , actual = pairactual.second;
        
        if(actualdist > dist[actual])
        {
            continue;
        }
        
        for(int i = 0; i < info[actual].size(); i++)
        {
            pii pairadj = info[actual][i];
            
            if(dist[actual] + pairadj.second < dist[pairadj.first])
            {
                dist[pairadj.first] = dist[actual] + pairadj.second;
                
                Q.push(pii(dist[pairadj.first] , pairadj.first));
            }
        }
    }
    
    if(dist[(1 << n) - 1] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[(1 << n) - 1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextA.txt" , "r")) freopen("ArturoTextA.txt" , "r" , stdin);

    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        cin >> ngive >> nhave >> cost;
        
        clean();
        
        for(int j = 0; j < ngive; j++)
        {
            cin >> figure;
            
            figure--;
            
            allgive |= (1 << figure);
            
            give[figure] = true;
        }
        
        for(int j = 0; j < n; j++)
        {
            if(!give[j])
            {
                freefigures.emplace_back(j);
            }
        }
        
        for(int j = 0; j < nhave; j++)
        {
            cin >> figure;
        
            figure--;
            
            allhave |= (1 << figure);
        }
        
        for(int j = 0; j < (1 << freefigures.size()); j++)
        {
            int z = 0;
            
            for(int k = 0; k < freefigures.size(); k++)
            {
                if(j & (1 << k))
                {
                    allgive |= (1 << freefigures[k]);
                    z |= (1 << freefigures[k]);
                }
            }
            
            info[allgive].emplace_back(z | allhave , cost);
            
            for(int k = 0; k < freefigures.size(); k++)
            {
                if(j & (1 << k))
                {
                    allgive -= (1 << freefigures[k]);
                }
            }
        }
    }
    
    dijkstra(0 , 1 << n);

    return 0;
}
