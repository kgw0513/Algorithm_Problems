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

constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

int2_int2 state[16];

bool is_in_circle(intint a, intint b, int r) {
	return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se) <= r * r;
}
int ans() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> state[i].fi.fi >> state[i].fi.se >>
			state[i].se.fi >> state[i].se.se;
	}

	int max_ans = 0;
	for (int upgrade_state = 0; upgrade_state < (1 << n); upgrade_state++) {
		int now_sum = 0;
		bool is_can = true;
		for (int now_p = 0; now_p < n; now_p++) {
			if ((upgrade_state & (1 << now_p)) == 0)continue;
			now_sum += state[now_p].se.se;
			for (int radius_p = 0; radius_p < n; radius_p++) {
				if (is_in_circle(state[now_p].fi, state[radius_p].fi, state[now_p].se.fi) &&
					(upgrade_state & (1 << radius_p)) == 0) {
					is_can = false;
					break;
				}
			}
		}
		if (!is_can)continue;
		max_ans = max(max_ans, now_sum);
	}

	return max_ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cout << "Case #" << test << ": " << ans() << "\n";
	}
}