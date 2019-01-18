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
using namespace std;

int dp[11][100010] , n , e , q , l , r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(fopen("InputArturoC.txt" , "r")) freopen("InputArturoC.txt" , "r" , stdin);
	
	while(cin >> n)
	{
		memset(dp , 0 , sizeof(dp));
		
		for(int i = 1; i <= n; i++)
		{
			cin >> e;
			
			for(int j = 0; j < 10; j++)
			{
				if(e == j)
				{
					dp[j][i] = dp[j][i - 1] + 1;
				}
				else
				{
					dp[j][i] = dp[j][i - 1];
				}
			}
		}
		
		
		/*for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				cout << dp[j][i] << " ";
			}
			
			cout << endl;
		}*/
		
		cin >> q;
		
		while(q--)
		{
			cin >> l >> r;
			
			int ans = 0;
			
			for(int i = 0; i < 10; i++)
			{
				//ans += max(0 , dp[i][r] - dp[i][l - 1]);
				
				if(dp[i][r] - dp[i][l - 1] > 0)
				{
					ans++;
				}
			}
			
			cout << ans << endl;
		}
	}
	
	//cout << "fin" << endl;
	
	return 0;
}
