#include<bits/stdc++.h>
#define endl '\n'
#define maxn 200010
using namespace std;

struct seg_tree
{
  int n;

  int t[2 * maxn];

  seg_tree(int _n) : n(_n) {}

  void clear()
  {
    memset(t , 0 , sizeof(t));
  }

  void build()
  {
    for (int i = n - 1; i > 0; --i)
    {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
  }

  void modify(int p, int value)
  {
    for (t[p += n] += value; p > 1; p >>= 1)
    {
        t[p >> 1] = t[p] + t[p ^ 1];
    }
  }

  int query(int l, int r)
  {
    int res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
      if (l & 1)
      {
          res += t[l++];
      }

      if (r & 1)
      {
          res += t[--r];
      }
    }

    return res;
  }
};

vector < int > maxprime(maxn);

int q;

void buildsieve()
{
    maxprime[0] = maxprime[1] = maxn + 100;

    for(int i = 2; i < maxprime.size(); i++)
    {
        if(maxprime[i] == 0)
        {
            maxprime[i] = i;

            for(int j = i + i; j < maxprime.size(); j += i)
            {
                maxprime[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    buildsieve();

    cin >> q;

    vector < pair < pair < int , int > , int > > queries(q);

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i].first.first >> queries[i].first.second;

        queries[i].second = i;
    }

    sort(queries.begin() , queries.end());

    seg_tree tree(maxprime.size());

    vector < int > ans(q);

    int lastnumber = 2;

    for(auto it : queries)
    {
        while(lastnumber <= it.first.first)
        {
            // Here we are adding 1 to the position of the max prime that this lastnumber has

            tree.modify(maxprime[lastnumber] , 1);

            lastnumber++;
        }

        // How many numbers have a max prime divisor <= k  [0 <= p <= it.first.second]

        ans[it.second] = tree.query(0 ,  it.first.second + 1);
    }

    for(int i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
