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
#define ll long long
#define maxn 20005
using namespace std;

unordered_map < ll , ll > positions;

unordered_map < ll , ll > freq;

ll a[maxn];

int t , n , i;

ll s;

bool ok;

pair < ll , ll >answers;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while(--t)
	{
		cin >> s >> n;

		for(i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}

		ok = false;

		for(i = n - 1; i > 0; i--)
		{
			freq[a[i]]--;

			if(freq[s - a[i]])
			{
				answers.first = s - a[i];

				answers.second = a[i];

				ok = true;
			}
		}

		if(ok)
		{
			cout << min(answers.first , answers.second) << " " << max(answers.first , answers.second) << endl;
		}
		else
		{
			cout << "!OK" << endl;
		}

		freq.clear();

		positions.clear();


	}

	cin >> s >> n;

		for(i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}

		ok = false;

		for(i = n - 1; i > 0; i--)
		{
			freq[a[i]]--;

			if(freq[s - a[i]])
			{
				answers.first = s - a[i];

				answers.second = a[i];

				ok = true;
			}
		}

		if(ok)
		{
			cout << min(answers.first , answers.second) << " " << max(answers.first , answers.second) << endl;
		}
		else
		{
			cout << "!OK" << endl;
		}

	return 0;
}
