#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define maxn 110
#define ll long long
using namespace std;

int t , n , m , u , v , w , mini;

vector < pair < int , int > > adj[maxn];

bool visited[maxn];

priority_queue < pair < int , int > > pq;

void process(int actual)
{
	visited[actual] = true;

	for(int i = 0; i < adj[actual].size(); i++)
	{
		auto t = adj[actual][i];

		if(!visited[t.first])
		{
			pq.push(make_pair(t.second , t.first));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(4) << fixed;
	
	if(fopen("InputArturoF.txt" , "r")) freopen("InputArturoF.txt" , "r" , stdin);

	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		cin >> n >> m;

		mini = 1010;

		for(int j = 0; j < n; j++)
		{
			visited[j] = false;

			adj[j].clear();
		}

		while(m--)
		{
			cin >> u >> v >> w;

			adj[u].push_back(make_pair(v , w));

			adj[v].push_back(make_pair(u , w));
		}

		process(0);

		while(!pq.empty())
		{
			auto t = pq.top();

			pq.pop();

			if(!visited[t.second])
			{
				if(mini > t.first)
				{
					mini = t.first;
				}

				process(t.second);
			}
		}

		cout << "Case #" << i << ": " << mini << endl;
	}

	return 0;
}
