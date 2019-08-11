#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100005
#define ll long long 
using namespace std;

set < pair < pair < ll , ll > , ll > > S;

ll L , C , N , P , A , B , X , M1 , M2, F , ans;

ll cnt[maxn];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> L >> C >> N;

	S.insert(make_pair( make_pair(0 , L - 1), 1)); // The whole device has color 1

	cnt[1] = L;

	while(N--)
	{
		cin >> P >> X >> A >> B;

		F = cnt[P];

		M1 = (A + F * F) % L;

		M2 = (A + (F + B) * (F + B)) % L;

		if(M1 > M2)
		{
			swap(M1 , M2);			
		}

		auto it = S.begin();

		it = S.lower_bound(make_pair( make_pair(M1 + 1 , 0) , 0));

		it--;

		vector < pair < pair < ll , ll > , ll > > ins , del;

		while(true)
		{
			if(it == S.end())
			{
				break;
			}

			auto T = *it;

			if(T.first.first > M2)
			{
				break;
			}	

			//cout << "before color " << T.second << " had " << cnt[T.second] << endl;

			cnt[T.second] -= (T.first.second - T.first.first + 1);

			//cout << "now color " << T.second << " has " << cnt[T.second] << endl;
			
			if(T.first.first < M1)
			{
				ins.push_back(make_pair( make_pair(T.first.first , M1 - 1) , T.second));

				//cout << "before color " << T.second << " had " << cnt[T.second] << endl;
				
				cnt[T.second] += M1 - 1 - T.first.first + 1;

				//cout << "now color " << T.second << " has " << cnt[T.second] << endl;
			}

			if(T.first.second > M2)
			{
				ins.push_back(make_pair( make_pair(M2 + 1, T.first.second), T.second));

				//cout << "before color " << T.second << " had " << cnt[T.second] << endl;
				
				cnt[T.second] += (T.first.second - (M2 + 1) + 1);

				//cout << "now color " << T.second << " has " << cnt[T.second] << endl;
			}

			del.push_back(T);

			//cout << "X before color " << X << " had " << cnt[X] << endl;
			
			cnt[X] += min(M2 , T.first.second) - max(M1, T.first.first) + 1;

			//cout << "X now color " << X << " has " << cnt[X] << endl;
			
			it++;
		}

		for(auto k : del)
		{
			S.erase(k);
		}

		for(auto k : ins)
		{
			S.insert(k);
		}

		S.insert(make_pair( make_pair(M1, M2) , X));
	}

	for(ll i = 1; i <= C; i++)
	{
		ans = max(ans , cnt[i]);
	}

	cout << ans << endl;

}
