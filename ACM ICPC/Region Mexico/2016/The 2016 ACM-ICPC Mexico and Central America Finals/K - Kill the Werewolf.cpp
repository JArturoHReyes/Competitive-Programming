#include<bits/stdc++.h>
#define endl '\n'
#define maxn 55
#define maxv 110
using namespace std;

int a[maxn] , b[maxn];

int residual[maxv][maxv];

int sink , source;

bool visited1[maxn];

bool visited2[maxv];

int from[maxv];

int find_path()
{
    memset(visited2 , 0 , sizeof(visited2));
    
    memset(from , -1 , sizeof(from));

    queue < int > Q;

    Q.push(source);
    
    visited2[source] = true;

    int where;

    while(!Q.empty())
    {
        where = Q.front();
        
        Q.pop();

        if(where == sink)
        {
            break;
        }

        for(int i = 0; i < maxv; i++)
        {
            if(residual[where][i] > 0 && !visited2[i])
            {
                Q.push(i);
                
                visited2[i] = true;
                
                from[i] = where;
            }
        }
    }

    int path_cap = 1 << 30;

    where = sink;

    while(from[where] > -1)
    {
        int prev = from[where];
        
        path_cap = min(path_cap , residual[prev][where]);
        
        where = prev;
    }

    where = sink;

    while(from[where] > -1)
    {
        int prev = from[where];
        
        residual[prev][where] -= path_cap;
        
        residual[where][prev] += path_cap;
        
        where = prev;
    }

    if(path_cap == 1 << 30)
    {
        return 0;
    }

    return path_cap;
}

int max_flow()
{
    int flow = 0;

    while(true)
    {
        int path_cap = find_path();

        if(!path_cap)
        {
            break;
        }
        else
        {
            flow += path_cap;
        }
    }

    return flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt" , "r" , stdin);

    int n;

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];

            a[i]-- , b[i]--;
        }

        int ans = 0;

        // Asumir que la persona i sera el werewolf

        for(int i = 0; i < n; i++)
        {
            memset(residual , 0 , sizeof(residual));

            source = 0;

            sink = 101;

            memset(visited1 , 0 , sizeof(visited1));

            visited1[i] = true;

            int kill = 0;

            // Vamos a preguntar cuantos jugadores lo quieren matar

            for(int j = 0; j < n; j++)
            {
                if(a[j] == i || b[j] == i)
                {
                    visited1[j] = true;
                    kill++;
                }
            }

            // N por lo menos sera 3 así que el lobo solo tiene un voto de cualquier manera se salva xd

            if(kill <= 1)
            {
                ans++;
                continue;
            }

            // Construir grafo

            for(int j = 0; j < n; j++)
            {
                residual[source][j + 1] = kill - 1;

                // Si queremos que el lobo i se salve las demas personas deben recibir cuanto mucho k - 1 votos

                if(a[i] == j || b[i] == j)
                {

                    // Pero si el lobo vota por la persona j entonces esa persona debe recibir cuanto mucho k - 2 votos

                    residual[source][j + 1] = kill - 2;
                }
            }

            // Debemos comparar el numero de personas que no mataron al lobo i con el flujo maximo del grafo

            int notvisited1 = 0;

            for(int j = 0; j < n; j++)
            {
                if(!visited1[j])
                {
                    residual[a[j] + 1][n + j + 1] = 1;
                    
                    residual[b[j] + 1][n + j + 1] = 1;
                    
                    residual[n + j + 1][sink] = 1;
                    
                    notvisited1++;
                }
            }

            if(max_flow() != notvisited1)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
