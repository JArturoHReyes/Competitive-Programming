#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1000001
using namespace std;

int n;

vector < string > x;

bool terminal[maxn];

int trie[maxn][26];

int mask[maxn];

int idx;

void add_trie(string a)
{
    int p = 0;
    
    for(char c : a)
    {
        mask[p] |= (1 << (c - 'a'));
        
        if(trie[p][c - 'a'] == 0)
        {
            p = trie[p][c - 'a'] = ++idx; // how many words have been here
        }
        else
        {
            p = trie[p][c - 'a'];
        }
    }
    
    terminal[p] = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;
    
    while(cin >> n)
    {
        idx = 0;
        
        memset(terminal , 0 , sizeof(terminal));
        
        memset(trie , 0 , sizeof(trie));
        
        memset(mask , 0 , sizeof(mask));
        
        x.resize(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
            
            add_trie(x[i]);
        }
        
        int cont = 0;
        
        for(int i = 0; i < n; i++)
        {
            int p = trie[0][x[i][0] - 'a'];
            
            cont++;
            
            for(int j = 1; j < x[i].length(); j++)
            {
                if(__builtin_popcount(mask[p]) > 1 || terminal[p])
                {
                    cont++;
                }
                
                p = trie[p][x[i][j] - 'a'];
            }
        }
        
        cout << (double) cont / (double) n << endl;
        
    }
    
    return 0;
}
