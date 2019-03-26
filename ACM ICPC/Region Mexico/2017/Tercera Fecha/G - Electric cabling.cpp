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

int t;

string x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(4) << fixed;
	
	if(fopen("InputArturoF.txt" , "r")) freopen("InputArturoF.txt" , "r" , stdin);

	cin >> t;

	getline(cin , x);

	while(t--)
	{
		getline(cin , x);

		vector < int > poles;

		int num = 0 , maxi = 0 , ans = 0;

		for(int i = 0; i < x.length(); i++)
		{
			if(x[i] == ' ')
			{
				poles.push_back(num);

				maxi = max(maxi , num);

				num = 0;
			}
			else
			{
				num *= 10;

				num += (x[i] - '0');
			}
		}

		poles.push_back(num);

		maxi = max(maxi , num);

		bool tall = false;

		for(int i = 0; i < poles.size(); i++)
		{
			if(tall && poles[i] == maxi)
			{
				ans++;

				tall = false;
			}
			else
			{
				if(tall)
				{
					ans++;
				}
				else
				{
					if(poles[i] == maxi)
					{
						tall = true;

						ans++;
					}
				}
				
			}
		}

		cout << ans << endl;

	}

	return 0;
}
