// A C program to implement Manacher’s Algorithm
#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
using namespace std;


string text;

void findLongestPalindromicString()
{
    int N = text.length();
    if(N == 0)
        return;
    N = 2*N + 1; //Position count
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int expand = -1;
    int diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;

    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (i = 2; i < N; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        //Reset expand - means no expansion required
        expand = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0)
        {
            if(L[iMirror] < diff) // Case 1
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i == N-1) // Case 2
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i < N-1)  // Case 3
            {
                    L[i] = L[iMirror];
                    expand = 1;  // expansion required
            }
            else if(L[iMirror] > diff)  // Case 4
            {
                L[i] = diff;
                expand = 1;  // expansion required
            }
        }
        else
        {
            L[i] = 0;
            expand = 1;  // expansion required
        }

        if (expand == 1)
        {
            //Attempt to expand palindrome centered at currentRightPosition i
            //Here for odd positions, we compare characters and
            //if match then increment LPS Length by ONE
            //If even position, we just increment LPS by ONE without
            //any character comparison
            while (((i + L[i]) < N && (i - L[i]) > 0) &&
                ( ((i + L[i] + 1) % 2 == 0) ||
                (text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] )))
            {
                L[i]++;
            }
        }

        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        // If palindrome centered at currentRightPosition i
        // expand beyond centerRightPosition R,
        // adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    /*//printf("start: %d end: %d\n", start, end);
    printf("LPS of string is %s : ", text);
    for(i=start; i<=end; i++)
        printf("%c", text[i]);
    printf("\n");

    printf("start = %d  end = %d\n" , start , end);*/
    printf("%d\n" , end - start + 1);
}


int main(int argc, char *argv[])
{

    int t;

    cin >> t;

    while(t--)
    {
        cin >> text;

        findLongestPalindromicString();
    }

    return 0;
}
