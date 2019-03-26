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

int t , r , c , ans;

string square[35];

bool visited[35][35];

int dx[] = {1 , 0 , -1 , 0};

int dy[] = {0 , 1 , 0 , -1};

void bfs(int x , int y)
{
	ans++;

	for(int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];

		int yy = y + dy[i];

		if(min(xx , yy) >= 0 && xx < r && yy < c && square[xx][yy] == '0' && !visited[xx][yy])
		{
			visited[xx][yy] = true;

			bfs(xx , yy);
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

	while(t--)
	{
		cin >> r >> c;

		ans = 0;

		for(int i = 0; i < r; i++)
		{
			cin >> square[i];

			for(int j = 0; j < c; j++)
			{
				visited[i][j] = false;
			}
		}

		if(square[0][0] == '0')
		{
			visited[0][0] = true;
			
			bfs(0 , 0);
		}
		else
		{
			if(square[r - 1][0] == '0')
			{
				visited[r - 1][0] = true;

				bfs(r - 1 , 0);
			}
			else
			{
				if(square[0][c - 1] == '0')
				{
					visited[0][c - 1] = true;

					bfs(0 , c - 1);
				}
				else
				{
					if(square[r - 1][c - 1] == '0')
					{
						visited[r - 1][c - 1] = true;

						bfs(r - 1 , c - 1);
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
