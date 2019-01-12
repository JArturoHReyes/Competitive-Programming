#include<bits/stdc++.h>
 
#define endl '\n'
 
using namespace std;
 
int dx[] = {1 , -1 , 0 , 0}; int dy[] = {0 , 0 , 1 , -1};
 
int m , n;
 
bool vis[1000][1000][2][2];
 
vector < string > square;
 
int bfs(int a , int b) {
 
int xx , yy , s , cont , x , y , i , f , k;
 
queue < pair < int , pair < pair < int , int > , pair < int , int > > > > q;
 
q.push(make_pair(0 , make_pair(make_pair(a , b) , make_pair(0 , 0)))); // We start in the John's Position
 
vis[a][b][0][0] = 1;
 
while(!q.empty())
{
    cont = q.front().first;
 
    x = q.front().second.first.first;
 
    y = q.front().second.first.second;
 
    f = q.front().second.second.first;
 
    k = q.front().second.second.second;
 
    q.pop();
 
    if(square[x][y] == 'E' && f && k)
    {
        return cont; // We have visited at least the two stores and got to the exit
    }
 
    if(square[x][y] == 'F')
    {
        f=1;
    }
 
    if(square[x][y] == 'K')
    {
        k=1;
    }
 
    for(int i = 0; i < 4; i++) // in all directions on the grid
    {
        xx = x + dx[i];
        yy = y + dy[i];
 
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && square[xx][yy] != '#' && vis[xx][yy][f][k] == 0)
        {
 
            q.push(make_pair(cont + 1 , make_pair(make_pair(xx , yy) , make_pair(f , k))));
           
            vis[xx][yy][f][k] = 1;
        }
    }
}
 
return -1;
}
 
int main() {
 
ios_base::sync_with_stdio(false) , cin.tie(nullptr);
 
int t , a , b;
 
cin >> t;
 
while(t--)
{
    memset(vis,0,sizeof(vis));
   
    cin >> m >> n;
 
    square.resize(m);
 
    for(int i = 0; i < m; i++)
    {
        cin >> square[i];
 
        for(int j = 0; j < n; j++)
        {
            if(square[i][j] == 'J')
            {
                a = i , b = j;
            }
        }
    }
 
    cout << bfs(a , b) << endl;
}
 
 
return 0;
}
