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

ll aPown(ll a, ll n, const ll MOD) {
    if (n == 0)return 1;
    if (n == 1)return a;
    ll h = aPown(a, n / 2, MOD);
    h *= h;
    h %= MOD;
    if (n % 2 == 1) {
        h *= a;
        h %= MOD;
    }
    return h;
}
ll NCM(ll n, ll m, const ll MOD) {
    ll n_sum = 1;
    ll m_sum = 1;
    for (ll i = 1; i <= m; i++) {
        n_sum *= (n - i + 1);
        n_sum %= MOD;

        m_sum *= i;
        m_sum %= MOD;
    }
    return (n_sum * aPown(m_sum, MOD - 2, MOD)) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans = 1, w, k;
    cin >> k >> w;
    k--;
    ll now_n = w;
    while (k--) {
        cin >> w;
        //cout << w << ":" << now_n + w - 1 <<","<<w - 1 << "\n";
        ans *= NCM(now_n + w - 1, w - 1, MOD1);
        ans %= MOD1;
        now_n += w;
    }
    cout << ans;
}