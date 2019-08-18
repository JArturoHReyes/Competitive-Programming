#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int last[26];

string x;

int n , e;

int kmp(const vector < int > & sss, const vector < int > & kkk)
{
	int ret = 0 , nnn = sss.size() , mmm = kkk.size();

	vector < int > ttt(mmm + 1);

	int j = ttt[0] = -1;

	for(int i = 0; i < mmm; i++)
	{
		while(~j && kkk[i] != kkk[j] && (kkk[j] or kkk[i] <= j))
		{
			j = ttt[j];
		} 

		ttt[i + 1] = ++j;
	}

	j = 0;

	for(int i = 0; i < nnn; i++)
	{
		while(~j && sss[i] != kkk[j] && (kkk[j] || sss[i] <= j))
		{
			j = ttt[j];
		}

        ++j;

        if(j == mmm)
        {
        	ret++ , j = ttt[j];
        }
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(10) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> x;

	memset(last , -1 , sizeof(last));

	vector < int > s(x.length());

	for(int i = 0; i < x.length(); i++)
	{
		int letter = x[i] - 'a';

		if(last[letter] == -1)
		{
			s[i] = 0;
		}
		else
		{
			s[i] = i - last[letter];
		}

		last[letter] = i;
	}

	memset(last , -1 , sizeof(last));

	cin >> n;

	vector < int > t(n);

	for(int i = 0; i < n; i++)
	{
		cin >> e;

		e--;

		if(last[e] == -1)
		{
			t[i] = 0;
		}
		else
		{
			t[i] = i - last[e];
		}

		last[e] = i;
	}

	cout << kmp(s , t) << endl;


	return 0;
}
