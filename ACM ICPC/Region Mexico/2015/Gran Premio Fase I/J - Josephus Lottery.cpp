#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , m , s , pos , i;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	while (cin >> n >> m && n)
    {
		s = 0;

		for (i = 1; i <= n; i++)
        {
			pos = m % i;

			if (s == 0)
            {
                s = pos;
            }
			else
            {
                if (s < pos)
                {
                    s = (pos - 1 - s) % i;
                }
                else
                {
                    s = (i - 1 - (s - pos)) % i;
                }
            }
        }

        cout << s + 1 << endl;
    }

	return 0;
}
