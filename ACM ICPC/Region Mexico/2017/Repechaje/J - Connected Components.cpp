#include<bits/stdc++.h>
#define endl '\n'
#define opt ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;

int matriz[26][26];

void limpiar()
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }
}

void llenarvacios(int n)
{
    for(int i = 0; i < n; i++)
    {
        vector < int > conocidos;

        for(int j = 0; j < n; j++)
        {
           if(matriz[i][j] && i != j)
           {
               conocidos.push_back(j);
           }
        }

        if(conocidos.size() >= 1)
        {
          for(int j = 0; j < conocidos.size(); j++)
          {
              for(int k = 0; k < n; k++)
              {
                  if(!matriz[conocidos[j]][k])
                  {
                    matriz[conocidos[j]][k] = matriz[i][k];
                  }

              }
          }
        }
    }
}

int maxsubconnects(int n)
{
    set < int >  visitados;

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visitados.count(i))
        {
           for(int j = 0; j < n; j++)
           {
               if(matriz[i][j])
               {
                   visitados.insert(j);
               }
           }

           res++;
        }
    }

    return res;
}

int main()
{
    opt;
    vector < string > words;
    string actualword;
    int ans = 0;
    int limit = 0;

    while(cin >> actualword)
    {
        words.push_back(actualword);
    }

    for(int i = 0; i < words.size(); i++)
    {
        if(words[i].size() == 1)
        {

            if(ans)
            cout << ans << endl;
            limpiar();
            ans = words[i][0] - 'A' + 1;
            limit = ans;
        }
        if(words[i].size() == 2)
        {
            matriz[words[i][0] - 'A'][words[i][1] - 'A'] = 1;
            matriz[words[i][1] - 'A'][words[i][0] - 'A'] = 1;
            llenarvacios(limit);
            ans = maxsubconnects(limit);
        }
    }

        cout << ans << endl;

    return 0;
}
