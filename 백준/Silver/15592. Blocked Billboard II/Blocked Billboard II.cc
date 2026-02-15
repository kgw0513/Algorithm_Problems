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

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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
    ll_ll a, b, c, d;
    cin >> a.fi >> a.se >> b.fi >> b.se;
    cin >> c.fi >> c.se >> d.fi >> d.se;

    if (c.fi <= a.fi && b.fi <= d.fi) {
        if (c.se <= a.se && a.se <= d.se) {
            if (b.se <= d.se)cout << 0;
            else cout << (b.fi - a.fi) * (b.se - d.se);
        }
        else if (c.se <= b.se && b.se <= d.se) {
            if (c.se <= a.se)cout << 0;
            else cout << (b.fi - a.fi) * (c.se - a.se);
        }
        else cout << (b.fi - a.fi) * (b.se - a.se);
        return 0;
    }
    else if (c.se <= a.se && b.se <= d.se) {
        if (c.fi <= a.fi && a.fi <= d.fi) {
            if (b.fi <= d.fi)cout << 0;
            else cout << (b.fi - d.fi) * (b.se - a.se);
        }
        else if (c.fi <= b.fi && b.fi <= d.fi) {
            if (c.fi <= a.fi)cout << 0;
            else cout << (c.fi - a.fi) * (b.se - a.se);
        }
        else cout << (b.fi - a.fi) * (b.se - a.se);
        return 0;
    }

    cout << (b.fi - a.fi) * (b.se - a.se);
}