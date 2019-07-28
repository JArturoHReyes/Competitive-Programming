#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


#define SIZE 1000000

bitset<SIZE> sieve;

void buildSieve() {
	sieve.set();
	sieve[0] = sieve[1] = 0;
	ll root = sqrt(SIZE);
	for (ll i=2; i < root+1; i++)
		if (sieve[i])
			for(ll j = i*i; j < SIZE; j+=i)
				sieve[j] = 0;
}

vector<ll> primesList;
void buildPrimesList() {
	if(!sieve[2]) {
		buildSieve();
	}
	primesList.reserve(SIZE/log(SIZE));
	for (ll i=2; i < SIZE+1; i++)
		if(sieve[i])
			primesList.push_back(i);
}

vector<pair<ll, ll> > primeFactorization(ll N) {
	vector<pair<ll, ll> > factors;
	ll idx = 0, pf = primesList[0];
	while(pf*pf <= N) {
		while(N%pf==0) {
			N /= pf;
			if(factors.size() && factors.back().first == pf) {
				factors.back().second++;
			} else {
				factors.push_back(make_pair(pf, 1));
			}
		}
		pf = primesList[++idx];
 	}
	if(N!=1) factors.push_back(make_pair(N, 1));
	return factors;
}

void getDivisors(vector<pair<ll,ll> > pf, ll d, ll index, vector<ll> &div) {
	if (index == pf.size()) {
		div.push_back(d);
		return;
	}
	for (ll i = 0; i <= pf[index].second; i++) {
		getDivisors(pf, d, index+1, div);
		d *= pf[index].first;
	}
	return;
}

vector<ll> divisors(ll N) {
    //cout << "HERE" << endl;
	vector<pair<ll,ll> > pf = primeFactorization(N);

    //cout << "HERE" << endl;
	vector<ll> div;
	getDivisors(pf, 1ll, 0, div);

    //cout << "HERE" << endl;
	sort(div.begin(), div.end());

    //cout << "HERE" << endl;
	return div;
}

int t;

ll x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextG.txt" , "r")) freopen("ArturoTextG.txt" , "r" , stdin);

    buildSieve();

    buildPrimesList();

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> x;

        vector < ll > divi = divisors(2 * x);

        ll ways = 0;

        for(int i = 1; i < divi.size(); i++)
        {
            ll n = divi[i];

            ll res = 2 * x / n;

            res++;

            res -= n;

            res /= 2;

            //cout << "d = " << res << endl;

            //cout << "n = " << n << endl;

            ways += (res > 0 && (res * n + ((n - 1) * n / 2)) == x);

            //cout << "ways = " << ways << endl;
        }

        cout << "case " << i << ": " << ways << endl;
    }

    return 0;
}
