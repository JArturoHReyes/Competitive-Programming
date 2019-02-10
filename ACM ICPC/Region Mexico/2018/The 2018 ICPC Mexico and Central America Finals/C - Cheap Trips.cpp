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
#define maxn 10010
using namespace std;

int n , duration[maxn] , actualduration;

double dp[maxn] , cost[maxn] , sumcosts;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(2) << fixed;
	
	if(fopen("InputArturoC.txt" , "r")) freopen("InputArturoC.txt" , "r" , stdin);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> duration[i] >> cost[i];
		
		dp[i] = 1e15;
	}
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = min(dp[i] , dp[i - 1] + cost[i]);
		
		actualduration = duration[i];
		
		if(actualduration < 120)
		{
			dp[i + 1] = min(dp[i + 1] , dp[i - 1] + cost[i] + 0.5 * cost[i + 1]);
		}
		
		sumcosts = 0;
		
		for(int j = 1; j <= 4; j++)
		{
			actualduration += duration[i + j];
			
			sumcosts += cost[i + j + 1];
			
			if(actualduration < 120)
			{
				dp[i + j + 1] = min(dp[i + j + 1] , dp[i - 1] + cost[i] + 0.5 * cost[i + 1] + 0.25 * sumcosts);
			}
		}
	}
	
	cout << dp[n] << endl;
	
	
	return 0;
}
