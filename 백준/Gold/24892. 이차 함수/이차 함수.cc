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

ll n;
ll a, b;

inline ll_ll pq(ll x) {
    //cout << x << ":" << a << "*" << n << "+(" << b << "-" << a << ") *" << x << " / " << n << " ??\n";
    return { a * n + (b - a) * x,n };
}

inline ll_ll fx(ll_ll pos) {
    return { (abs(pos.fi * pos.fi - (a + b) * pos.fi * pos.se + a * b * pos.se * pos.se)) % MOD1,(pos.se * pos.se) % MOD1 };
}

inline ll apown(ll a, ll n) {
    if (n == 0)return 1;
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
    cin >> n >> a >> b;
    ll_ll ans = { 0,0 };
    for (int i = 0; i < n; i++) {
        ll_ll s = pq(i);
        ll_ll e = pq(i + 1);

        ll_ll gap = { (s.se * e.fi - e.se * s.fi) % MOD1,(s.se * e.se) % MOD1 };

        ll_ll s_height = fx(s);
        ll_ll e_height = fx(e);

        ll_ll h = { (s_height.fi * e_height.se + e_height.fi * s_height.se) % MOD1,(s_height.se * e_height.se) % MOD1 };

        gap.se *= 2;
        gap.se %= MOD1;

        h.fi *= gap.fi;
        h.se *= gap.se;
        h.fi %= MOD1;
        h.se %= MOD1;

        //cout << s.fi << "/" << s.se << "~" << e.fi << "/" << e.se << "\n";
        //cout << "gap : " << gap.fi << "/" << gap.se << "\n";
        //cout << s_height.fi << "/" << s_height.se << " | " << e_height.fi << "/" << e_height.se << "\n";
        //cout << "=>" << h.fi << "/" << h.se << "\n";

        if (i == 0) {
            ans = h;

            //cout << " ans : " << ans.fi << "/" << ans.se << "\n";
            continue;
        }
        ll_ll cal = { (ans.fi * h.se + h.fi * ans.se) % MOD1,(ans.se * h.se) % MOD1 };

        ans = cal;
        //cout << " ans : " << ans.fi << "/" << ans.se << "\n";
    }

    ll h = apown(ans.se, MOD1 - 2);
    h *= ans.fi;
    h %= MOD1;
    cout << h;
}