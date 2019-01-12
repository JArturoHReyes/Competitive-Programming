#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , cout.precision(10);
#define in if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ll unsigned long long
using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)
#define N 100010
#define A 1000010
#define BLOCK 317
#define M 100010

int answer;

struct query
{
    int l , r , ind;
}Q[M];

vector < int > ans(M) , cnt(A) , a(N);

void add(int index)
{
    cnt[a[index]]++;
    if(cnt[a[index]]==1) answer++;
}

void remove(int index)
{
    cnt[a[index]]--;
    if(cnt[a[index]]==0) answer--;
}

bool cmp(query f ,query s)
{
    if((f.l/BLOCK)!=(s.l/BLOCK))
        return (f.l/BLOCK)<(s.l/BLOCK);
    else
        return f.r<s.r;
}


int main()
{
    opt;

    int n , q , t , cl , cr , left , right;

    scanf("%d" , &t);

    while(t--)
    {
        scanf("%d %d",&n ,&q);

        REP(i,0,n)
        {
            scanf("%d",&a[i]);
        }

        REP(i , 0 , q)
        {
            scanf("%d %d",&Q[i].l,&Q[i].r);
            Q[i].ind = i;
        }

        sort(Q , Q + q , cmp);

        cl = 0 , cr = 0;

        answer = 0;

        ans.assign(M , 0);
        cnt.assign(A , 0);

        REP(i , 0 , q)
        {
            left = Q[i].l , right = Q[i].r;

            while(cl<left)
                remove(cl),cl++;

            while(cl>left)
                add(cl-1),cl--;

            while(cr<=right)
                add(cr),cr++;

            while(cr>(right+1))
                remove(cr-1),cr--;

            ans[Q[i].ind] = answer;
        }

        REP(i,0,q)
        printf("%d\n",ans[i]);
    }


    return 0;

}
