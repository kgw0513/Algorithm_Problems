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
    ll a, b, c;
    cin >> a >> b >> c;
    if (c % b == 0 || c % a == 0) {
        cout << 1;
        return 0;
    }
    for (ll check = 1; check <= sqrt(c); check++) {
        if (c % check != 0)continue;
        ll alpha = check;
        ll beta = c / check;

        if ((alpha <= a && beta <= b) || (alpha <= b && beta <= a)) {
            cout << 2;
            return 0;
        }
    }

    for (ll cut_a = 1; cut_a < a && cut_a*b<=c; cut_a++) {
        ll left_a = a - cut_a;
        ll left_c = c - cut_a * b;
        if (left_c % left_a != 0)continue;
        ll counting_a = left_c / left_a;
        if (counting_a > b)continue;
        cout << 2;
        return 0;
    }

    for (ll cut_b = 1; cut_b < a && cut_b * a <= c; cut_b++) {
        ll left_b = b - cut_b;
        ll left_c = c - cut_b * a;
        if (left_c % left_b != 0)continue;
        ll counting_b = left_c / left_b;
        if (counting_b > a)continue;
        cout << 2;
        return 0;
    }

    cout << 3;
}