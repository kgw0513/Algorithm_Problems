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

const long long INF = 2147483647;
const long long lINF = 9000000000000000000;
const long long nlINF = lINF / 100;
const int nINF = 1007483647;
unsigned long long MOD1 = 1000000363;
unsigned long long MOD2 = 1000000007;
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

map<ll, set<ll>>arr;

ll apown(ll a, ll n) {
	if (n == 0)return 1;
	if (n == 1)return a;
	ll h = apown(a, n / 2);
	h *= h;
	h %= MOD2;
	if (n % 2 == 1)h *= a;
	h %= MOD2;
	return h;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll r, c, k, a, b;
	cin >> r >> c >> k;
	while (k--) {
		cin >> a >> b;
		arr[a].insert(b);
	}
	
	ll max_num = 0;
	ll ans = 1;
	for (auto h : arr) {
		ll now_r = h.fi;

		ll last_c = 0;
		for (int now_c : h.se) {
			int blank = (now_c - last_c - 1);
			max_num += blank / 2;
			if (blank % 2 == 1) {
				ans *= (blank / 2 + 1);
				ans %= MOD2;
			}

			last_c = now_c;
		}
		ll now_c = c + 1;
		ll blank = (now_c - last_c - 1);
		max_num += blank / 2;
		if (blank % 2 == 1) {
			ans *= (blank / 2 + 1);
			ans %= MOD2;
		}
	}

	ll left_r = r - arr.size();
	ll blank = c;
	max_num += (blank / 2) * left_r;

	if (blank % 2 == 1) {
		ans *= apown(blank / 2 + 1, left_r);
		ans %= MOD2;
	}
	cout << max_num << " " << ans;
}