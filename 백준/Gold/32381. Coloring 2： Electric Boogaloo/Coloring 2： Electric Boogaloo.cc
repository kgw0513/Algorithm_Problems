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
#include <complex>
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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, w;
    cin >> n >> q;
    queue<ll>turn_row_not_use, turn_row_use;
    queue<ll>turn_col_not_use, turn_col_use;
    for (int i = 1; i <= min(q, n); i++) {
        turn_row_not_use.push(i);
        turn_col_not_use.push(i);
    }
    ll all_trun_state = 0;

    vector<string>ans;
    while (q--) {
        cin >> w;
        ll turn_row_num = n - turn_col_use.size();

        ll turn_col_num = n - turn_row_use.size();

        if (!turn_row_not_use.empty() && all_trun_state - ll(turn_col_use.size()) + turn_row_num == w) {
            all_trun_state = w;
            turn_row_use.push(turn_row_not_use.front());
            ans.push_back("R " + to_string(turn_row_not_use.front()));
            turn_row_not_use.pop();
            continue;
        }

        if (!turn_row_use.empty() && all_trun_state - turn_row_num + ll(turn_col_use.size()) == w) {
            all_trun_state = w;
            turn_row_not_use.push(turn_row_use.front());
            ans.push_back("R " + to_string(turn_row_use.front()));
            turn_row_use.pop();
            continue;
        }

        if (!turn_col_not_use.empty() && all_trun_state - ll(turn_row_use.size()) + turn_col_num == w) {
            all_trun_state = w;
            turn_col_use.push(turn_col_not_use.front());
            ans.push_back("C " + to_string(turn_col_not_use.front()));
            turn_col_not_use.pop();
            continue;
        }

        if (!turn_col_use.empty() && all_trun_state - turn_col_num + ll(turn_row_use.size()) == w) {
            all_trun_state = w;
            turn_col_not_use.push(turn_col_use.front());
            ans.push_back("C " + to_string(turn_col_use.front()));
            turn_col_use.pop();
            continue;
        }

        cout << -1;
        return 0;
    }

    for (string& h : ans) {
        cout << h << "\n";
    }
}