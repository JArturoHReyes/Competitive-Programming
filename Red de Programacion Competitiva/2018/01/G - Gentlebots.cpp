#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct vec
{
    int x , y , z;

    bool operator ==(vec const &o) const{return x == o.x && y == o.y && z == o.z;}
    bool operator !=(vec const &o) const{return x != o.x or y != o.y or z != o.z;}
    vec operator +(vec const &o) const{return {x + o.x, y + o.y, z + o.z};}
    vec operator -(vec const &o) const{return {x - o.x, y - o.y, z - o.z};}
    bool operator <(vec const &o) const{return x != o.x? x < o.x : y != o.y? y < o.y : z < o.z;}

    int magnitude() const{return abs(x) + abs(y) + abs(z);}

    friend ostream& operator <<(ostream &s, vec const &o)
    {
        return s << "(" << o.x << " " << o.y << " " << o.z << ")";
    }
};

vec directions[] = {{1 , 0 , 0} , {-1 , 0 , 0} , {0 , 1 , 0} , {0 , -1 , 0} , {0 , 0 , 1} , {0 , 0 , -1} , {0 , 0 , 0}};

set < pair < vec , vec > > states;

stack < pair < vec, vec > > ans;

vec fe , le;

bool dfs(vec af , vec al)
{
    if(!states.count(make_pair(af , al)))
    {
        states.insert(make_pair(af , al));
    }
    else
    {
        return false;
    }

    if(af == fe && al == le)
    {
        return true;
    }

    vector < pair < vec , vec > > moves;

    for(auto const &u : directions)
    {
        for(auto const &v : directions)
        {
            moves.push_back(make_pair(u , v));
        }
    }

    sort(moves.begin() , moves.end() , [af, al](pair < vec , vec > const &u, pair < vec , vec > const &v)
    {
        return (af + u.first - fe).magnitude() + (al + u.second - le).magnitude() < (af + v.first - fe).magnitude() + (al + v.second - le).magnitude();
    });

    for(auto const &uv : moves)
    {
        auto const &u = uv.first;

        auto const &v = uv.second;

        if(af + u != al + v and (af + u != al or al + v != af) and dfs(af + u, al + v))
        {
            ans.push(make_pair(af + u, al + v));

            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vec fs , ls;

    cin >> fs.x >> fs.y >> fs.z;

    cin >> fe.x >> fe.y >> fe.z;

    cin >> ls.x >> ls.y >> ls.z;

    cin >> le.x >> le.y >> le.z;

    cout << fs << " " << ls << endl;

    dfs(fs, ls);
    
    while(!ans.empty())
    {
        cout << ans.top().first << " " << ans.top().second << endl;
        
        ans.pop();
    }

    return 0;
} 
