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

ll apown(ll a, ll n) {
    if (n <= 0)return 1;
    if (n == 1)return a;
    ll h = apown(a, n / 2);
    h *= h;
    h %= MOD1;
    if (n % 2 == 1) {
        h *= a;
        h %= MOD1;
    }
    return h;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)swap(a, b);

    ll left = a - 2;
    ll right = n - b;
    ll middle = b - a - 1;

    if (a + 1 == b) {
        ll left_ans = 0;
        ll right_ans = 0;
        //{a->b}로 가는 경우의 수
        if (left == 0) {
            for (ll i = 0; i <= right; i++) {
                left_ans += apown(2, right - i - 1);
            }
        }
        else {
            ll Left_comb_up = 1;
            ll Left_comb_down = 1;
            for (ll i = 1; i <= left; i++) {
                Left_comb_up *= i;
                Left_comb_up %= MOD1;
            }
            Left_comb_down = Left_comb_up;

            left_ans += ((Left_comb_up * apown(Left_comb_down, MOD1 - 2)) % MOD1) * apown(2, right - 1);
            left_ans %= MOD1;

            for (ll i = 1; i <= right; i++) {
                Left_comb_up *= apown(i, MOD1 - 2);
                Left_comb_up %= MOD1;
                Left_comb_up *= (left + i);
                Left_comb_up %= MOD1;

                left_ans += ((Left_comb_up * apown(Left_comb_down, MOD1 - 2)) % MOD1) * apown(2, right - 1 - i);
                left_ans %= MOD1;
            }
        }

        if (right == 0) {
            for (ll i = 0; i <= left; i++) {
                right_ans += apown(2, left - i - 1);
            }
        }
        else {
            ll Right_comb_up = 1;
            ll Right_comb_down = 1;
            for (ll i = 1; i <= right; i++) {
                Right_comb_up *= i;
                Right_comb_up %= MOD1;
            }
            Right_comb_down = Right_comb_up;

            right_ans += ((Right_comb_up * apown(Right_comb_down, MOD1 - 2)) % MOD1) * apown(2, left - 1);
            right_ans %= MOD1;

            for (ll i = 1; i <= left; i++) {
                Right_comb_up *= apown(i, MOD1 - 2);
                Right_comb_up %= MOD1;
                Right_comb_up *= (right + i);
                Right_comb_up %= MOD1;

                right_ans += ((Right_comb_up * apown(Right_comb_down, MOD1 - 2)) % MOD1) * apown(2, left - 1 - i);
                right_ans %= MOD1;
            }
        }

        //cout << left_ans << "+" << right_ans << "=\n";
        cout << (left_ans + right_ans) % MOD1;
        return 0;
    }

    ll h1 = 1;
    if (left != 0 && right != 0) {
        ll h2 = left + right;
        ll h3 = left;

        ll comb_up = 1;
        ll comb_down = 1;
        for (ll i = 1; i <= left; i++) {
            comb_up *= (left + right - i + 1);
            comb_up %= MOD1;

            comb_down *= i;
            comb_down %= MOD1;
        }

        h1 = comb_up * apown(comb_down, MOD1 - 2);
        h1 %= MOD1;
    }

    h1 *= 2;
    h1 %= MOD1;

    h1 *= apown(2, middle - 1);
    h1 %= MOD1;

    cout << h1;
}