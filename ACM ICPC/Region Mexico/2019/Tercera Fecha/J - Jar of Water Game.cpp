#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , k , winner;

string cards;

int freq[20][20];

int dict[256];

int fifth[20];

int full(int x)
{
    for(int i = 1; i < 14; i++)
    {
        if(freq[x][i] == 4)
        {
            return i;
        }
    }
    
    return 0;
}

int pop(int x)
{
    for(int i = 1; i < 14; i++)
    {
        if(freq[x][i] == 1)
        {
            freq[x][i]--;
            
            return i;
        }
    }
    
    for(int i = 1; i < 14; i++)
    {
        if(freq[x][i] == 2)
        {
            freq[x][i]--;
            
            return i;
        }
    }
    
    for(int i = 1; i < 14; i++)
    {
        if(freq[x][i] == 4)
        {
            freq[x][i]--;
            
            return i;
        }
    }
}

void filldict()
{
    dict['A'] = 1;
    dict['2'] = 2;
    dict['3'] = 3;
    dict['4'] = 4;
    dict['5'] = 5;
    dict['6'] = 6;
    dict['7'] = 7;
    dict['8'] = 8;
    dict['9'] = 9;
    dict['D'] = 10;
    dict['Q'] = 11;
    dict['J'] = 12;
    dict['K'] = 13;
    dict['W'] = 14;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    filldict();
    
    winner = -1;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        cin >> cards;
        
        for(int j = 0; j < 4; j++)
        {
            freq[i][dict[cards[j]]]++;   
        }
    }
    
    k--;
    
    for(int i = 0; i < n; i++)
    {
        if(i != k)
        {
            if(full(i))
            {
                if(winner == -1)
                {
                    winner = i;
                }
                else
                {
                    if(full(i) < full(winner))
                    {
                        winner = i;
                    }
                }
            }
        }
    }
    
    if(winner != -1)
    {
        cout << winner + 1 << endl;
        
        return 0;
    }
    
    int actual = k;
    
    int poswild = k;
    
    fifth[actual] = 14;
    
    bool ok = true;
    
    while(ok)
    {
        freq[actual][fifth[actual]]++;
        
        if(poswild == actual && fifth[actual] != 14)
        {
            poswild = (poswild + 1) % n;
            
            fifth[poswild] = 14;
        }
        else
        {
            fifth[(actual + 1) % n] = pop(actual);
        }
        
        if(fifth[actual] != 14)
        {
            ok = (full(actual) == 0);
        }
        
        winner = actual;
        
        actual = (actual + 1) % n;
    }
    
    cout << winner + 1 << endl;
    
    return 0;
}
