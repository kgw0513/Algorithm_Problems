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

ll apown(ll a, ll n, ll mod) {
	if (n == 0)return 1;
	if (n == 1)return a;
	ll h = apown(a, n / 2, mod);
	h *= h;
	h %= mod;
	if (n % 2 == 1) {
		h *= a;
		h %= mod;
	}
	return h;
}

ll fact[666750] = { 1 };
ll div_fact[666750] = { 1 };
ll div_num[666750] = { 1 };
ll catal[666750] = { 1,1,2 };

ll ans[1000002] = { -1,-1,1,1,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll sum = 1;
	for (ll i = 1; i <= 333363*2; i++) {
		sum *= i;
		sum %= MOD3;
		fact[i] = sum;
		if (i <= 333363)div_fact[i] = apown(sum, MOD3 - 2, MOD3);
	}

	for (ll i = 1; i <= 333363; i++) {
		div_num[i] = apown(i, MOD3 - 2, MOD3);
	}

	for (ll i = 3; i <= 333342; i++) {
		catal[i] = div_num[i + 1];
		catal[i] *= fact[2 * i];
		catal[i] %= MOD3;
		catal[i] *= div_fact[i];
		catal[i] %= MOD3;
		catal[i] *= div_fact[i];
		catal[i] %= MOD3;
	}

	for (int i = 5; i <= 1000000; i++) {
		if (i % 3 == 1) {
			ans[i] = ans[i - 1] + ans[i - 2] - catal[i / 3] + MOD3;
		}
		else {
			ans[i] = ans[i - 1] + ans[i - 2];
		}
		ans[i] %= MOD3;
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << ans[n] << "\n";
	}
}