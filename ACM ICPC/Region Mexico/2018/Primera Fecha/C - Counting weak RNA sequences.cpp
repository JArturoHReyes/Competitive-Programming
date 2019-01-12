#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ull unsigned long long
using namespace std;

bool is_valid(string a)
{
    bool lettera = false , lettert = false;

    for(int i = 0; i < 10; i++)
    {
        if(a[i] == 'A')
        {
            lettera = true;
            continue;
        }

        if(a[i] == 'T')
        {
            lettert = true;
            continue;
        }

        return false;
    }

    if(lettera && lettert)
    {
        return true;
    }

    return false;
}

int change(string a)
{
    for(int i = 0; i < 10; i++)
    {
        if(a[i] == 'A')
        {
            a[i] = '0';
        }
        else
        {
            a[i] = '1';
        }
    }

    bitset < 10 > r(a);

    return r.to_ulong();
}


int main()
{
    opt;

    int t; string x , sub;

    cin >> t;

    while(t--)
    {
      cin >> x;

      int ans = 0;

      if(x.length() > 9)
      {
          map < int , int > hashes;

          int e = 9; vector < int > check(4 , 0);

          sub = x.substr(0 , e);

          for(int i = 0; i < 9; i++)
          {
              if(sub[i] == 'A')
              {
                  check[0]++;
                  continue;
              }

              if(sub[i] == 'T')
              {
                  check[1]++;
                  continue;
              }

              if(sub[i] == 'C')
              {
                  check[2]++;
                  continue;
              }

              if(sub[i] == 'G')
              {
                  check[3]++;
                  continue;
              }
          }

          while(e < x.length())
          {
              sub += x[e++];

              if(sub[9] == 'A')
              {
                  check[0]++;
              }

              if(sub[9] == 'T')
              {
                  check[1]++;
              }

              if(sub[9] == 'C')
              {
                  check[2]++;
              }

              if(sub[9] == 'G')
              {
                  check[3]++;
              }

              if(check[0] && check[1] && !check[2] && !check[3])
              {
                  hashes[change(sub)]++;
              }

              if(sub[0] == 'A')
              {
                  check[0]--;
              }

              if(sub[0] == 'T')
              {
                  check[1]--;
              }

              if(sub[0] == 'C')
              {
                  check[2]--;
              }

              if(sub[0] == 'G')
              {
                  check[3]--;
              }

              sub.erase(0 , 1);
          }

          for(auto it = hashes.begin(); it != hashes.end(); it++)
          {
            if(it->second > 0 && hashes[( (~it->first) & 1023 )] > 0)
            {
                ans += (it->second);
            }
          }
      }

      cout << ans << endl;

    }

    return 0;

}
