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
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    intint s, e;
    int n, t, l;
    cin >> s.fi >> s.se >> e.fi >> e.se >> n >> t >> l;
    vector<int_int2>move_wind(n);
    for (int_int2& h : move_wind) {
        cin >> h.fi >> h.se.fi >> h.se.se;
    }

    intint state = s;
    intint now_wind = { 0,0 };
    int p = 0;
    for (int i = 0; i < t; i++) {
        if (p < n && move_wind[p].fi == i) {
            now_wind = move_wind[p].se;
            p++;
        }
        state.fi += now_wind.fi;
        state.se += now_wind.se;
    }
    //cout << state.fi << "," << state.se << "감.\n";
    state = { e.fi - state.fi,e.se - state.se };
    //cout << state.fi << "," << state.se << "더 가야함.\n";
    dd move_each = { state.fi / double(t),state.se / double(t) };
    //cout << move_each.fi << "," << move_each.se << " 1개씩 가면 된다.\n";
    
    if (move_each.fi * move_each.fi + move_each.se * move_each.se>l*l) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    dd new_state = s;
    dd new_wind = { 0,0 };
    p = 0;
    for (int i = 0; i < t; i++) {
        if (p < n && move_wind[p].fi == i) {
            new_wind = move_wind[p].se;
            p++;
        }
        new_state.fi += move_each.fi;
        new_state.se += move_each.se;
        new_state.fi += new_wind.fi;
        new_state.se += new_wind.se;
        cout.precision(12);
        cout << new_state.fi << " " << new_state.se << "\n";
    }
}