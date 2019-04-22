#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoGIn.txt" , "r")) freopen("ArturoGIn.txt" , "r" , stdin);

    string tobby , nae;

    long long tb , ne;

    while(cin >> tobby)
    {
        cin >> tb >> nae >> ne;

        if(tobby == "Cruisers")
        {
            if(nae == "Cruisers")
            {
                if(tb > ne)
                {
                    cout << "Tobby" << endl;
                }
                else
                {
                    if(tb == ne)
                    {
                        cout << "Draw" << endl;
                    }
                    else
                    {
                        cout << "Naebbirac" << endl;
                    }
                }
            }
            else
            {
                if(nae == "Battleships")
                {
                    if(ne >= (2 * tb))
                    {
                        cout << "Naebbirac" << endl;
                    }
                    else
                    {
                        cout << "Tobby" << endl;
                    }
                }
                else
                {
                    if(tb >= (2 * ne))
                    {
                        cout << "Tobby" << endl;
                    }
                    else
                    {
                        cout << "Naebbirac" << endl;
                    }
                }
            }
        }
        else
        {
            if(tobby == "Battleships")
            {
                if(nae == "Battleships")
                {
                    if(tb > ne)
                    {
                        cout << "Tobby" << endl;
                    }
                    else
                    {
                        if(tb == ne)
                        {
                            cout << "Draw" << endl;
                        }
                        else
                        {
                            cout << "Naebbirac" << endl;
                        }
                    }
                }
                else
                {
                    if(nae == "Cruisers")
                    {
                        if(tb >= (2 * ne))
                        {
                            cout << "Tobby" << endl;
                        }
                        else
                        {
                            cout << "Naebbirac" << endl;
                        }
                    }
                    else
                    {
                        if(ne >= (2 * tb))
                        {
                            cout << "Naebbirac" << endl;
                        }
                        else
                        {
                            cout << "Tobby" << endl;
                        }
                    }
                }
            }
            else
            {
                if(nae == "Destroyers")
                {
                    if(tb > ne)
                    {
                        cout << "Tobby" << endl;
                    }
                    else
                    {
                        if(tb == ne)
                        {
                            cout << "Draw" << endl;
                        }
                        else
                        {
                            cout << "Naebbirac" << endl;
                        }
                    }
                }
                else
                {
                    if(nae == "Cruisers")
                    {
                        if(ne >= (2 * tb))
                        {
                            cout << "Naebbirac" << endl;
                        }
                        else
                        {
                            cout << "Tobby" << endl;
                        }
                    }
                    else
                    {
                        if(tb >= (2 * ne))
                        {
                            cout << "Tobby" << endl;
                        }
                        else
                        {
                            cout << "Naebbirac" << endl;
                        }
                    }
                }
            }
        }

    }



	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
