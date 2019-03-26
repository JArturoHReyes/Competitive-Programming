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
#define maxn 500010
#define ll long long
using namespace std;

int n , i , j;

long double dist[maxn] , height[maxn] , distleft , distright;

ll diffdist , diffheight;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(4) << fixed;
	
	if(fopen("InputArturoF.txt" , "r")) freopen("InputArturoF.txt" , "r" , stdin);

	cin >> n;

	for(i = 0; i < n + 2; i++)
	{
		cin >> dist[i] >> height[i];
	}

	for(i = 1; i <= n; i++)
	{
		for(j = i - 1; j >= 0; j--)
		{
			if(height[j] > height[i])
			{
				diffdist = dist[i] - dist[j];

				diffheight = height[i] - height[j];
				
				distleft = sqrt(diffdist * diffdist + diffheight * diffheight);

				cout << j << " ";

				break;
			}
		}

		for(j = i + 1; j < n + 2; j++)
		{
			if(height[j] > height[i])
			{
				diffdist = dist[i] - dist[j];

				diffheight = height[i] - height[j];

				distright = sqrt(diffdist * diffdist + diffheight * diffheight);

				cout << j << " ";

				break;
			}
		}

		cout << distleft << " " << distright << endl;
	}

	return 0;
}
