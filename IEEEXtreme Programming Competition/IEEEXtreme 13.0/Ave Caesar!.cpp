#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string filename = "t.txt";

int n;

string x , actual;

bool ok()
{
    vector < map < char , int > > trie;

    trie.resize(1);

    actual = "";

    for(char c : x)
    {
        if(actual.empty() || actual.back() <= c)
        {
            actual.push_back(c);
        }
        else
        {
            int curr = 0;

            for(char cc : actual)
            {
                if(trie[curr].upper_bound(cc) != trie[curr].end())
                {
                    return false;
                }

                if(trie[curr].find(cc) == trie[curr].end())
                {
                    trie[curr][cc] = trie.size();

                    trie.resize(trie.size() + 1); 
                }

                curr = trie[curr][cc];
            }

            if(trie[curr].size() > 0)
            {
                return false;
            }

            actual = "";

            actual.push_back(c);
        }
    }

    int curr = 0;

    for(char cc : actual)
    {
        if(trie[curr].upper_bound(cc) != trie[curr].end())
        {
            return false;
        }

        if(trie[curr].find(cc) == trie[curr].end())
        {
            trie[curr][cc] = trie.size();

            trie.resize(trie.size() + 1); 
        }

        curr = trie[curr][cc];
    }

    if(trie[curr].size() > 0)
    {
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;

        putchar('0' + ok());
    }

    putchar(endl);

    return 0;
}
