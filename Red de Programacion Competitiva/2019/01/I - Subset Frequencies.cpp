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
#define maxn 1000010
using namespace std;

int a[maxn];

int q[maxn];

int n , k;

vector < pair < int , int > > answers;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(fopen("InputArturoI.txt" , "r")) freopen("InputArturoI.txt" , "r" , stdin);

	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a , a + n);

	for(int i = 0; i < k; i++)
	{
		cin >> q[i];
	}

	for(int actualquery = 0; actualquery < k; actualquery++)
	{
		int j = n - 1 , cnt = 0;

		for(int i = 0; i < n; i++)
		{
			while(j >= 0 && a[i] + a[j] > q[actualquery])
			{
				j--;
			}

			if(j <= i)
			{
				break;
			}

			if(a[i] + a[j] == q[actualquery])
			{
				cnt++;
			}
		}

		answers.push_back(make_pair(-cnt , q[actualquery]));
	}

	sort(answers.begin() , answers.end());

	for(int i = 0; i < k; i++)
	{
		cout << answers[i].second << " " << -answers[i].first << endl;
	}
	
	return 0;
}
