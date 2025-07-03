#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;
/*
rope c++
#include <ext/rope>
using namespace __gnu_cxx;
*/

/*
pbds c++ set전용
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset을 쓰고 싶으면 위의 코드에서 마지막 줄만 아래 코드로 변경.(대신 erase가 정상작동 되지 않는다.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

이외에 범위를 늘리고 싶으면 타입변경하면 된다.
ex. int->ll, less_equal<ll>
*/

constexpr double PI = 3.1415926535;
constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
constexpr unsigned long long MOD3 = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<double, double> dd;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<ll_ll, ll>ll2_ll;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;

bool visit[200][200];

//dxdy[2]는 홀짝에 따라 이동이 바뀐다.
//홀이면 y*-1
//짝이면 y
intint dxdy[3] = { {-1,0},{1,0},{0,1} };
//vector<intint>check;
ll dfs(intint p, int n,intint cant_p) {
    if (n <= 0) {
        if (visit[p.fi][p.se]) {
            //cout << p.fi << "," << p.se << "방문.\n";
            /*for (int i = 0; i < check.size(); i++) {
                cout << check[i].fi << "," << check[i].se << " <=> ";
            }
            cout << "\n";*/
            return 1;
        }
        return 0;
    }
    if (visit[p.fi][p.se])return 0;
    visit[p.fi][p.se] = true;
    ll ans = 0;
    intint new_p = { p.fi + dxdy[0].fi,p.se + dxdy[0].se };
    //check.push_back(new_p);
    if (!(new_p.fi == cant_p.fi && new_p.se == cant_p.se))ans += dfs(new_p, n - 1, p);
    //check.pop_back();

    new_p = { p.fi + dxdy[1].fi,p.se + dxdy[1].se };
    //check.push_back(new_p);
    if (!(new_p.fi == cant_p.fi && new_p.se == cant_p.se))ans += dfs({ p.fi + dxdy[1].fi,p.se + dxdy[1].se }, n - 1, p);
    //check.pop_back();

    new_p = { p.fi + dxdy[2].fi,p.se + dxdy[2].se * ((p.fi + p.se) % 2 == 0 ? 1 : -1) };
    //check.push_back(new_p);
    if (!(new_p.fi == cant_p.fi && new_p.se == cant_p.se))ans += dfs(new_p, n - 1, p);
    //check.pop_back();

    visit[p.fi][p.se] = false;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    visit[100][101] = true;
    cout << dfs({ 100,100 }, n, { 100,101 });
    //check.push_back({ 100,100 });
    /*for (int test = 1; test <= 22; test++) {
        cout << test << ":" << dfs({ 100,100 }, test, { 100,101 }) << "\n";
    }*/
}