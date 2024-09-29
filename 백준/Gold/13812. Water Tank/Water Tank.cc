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

const ll upper = 1000000000;
const ll daytime = 86400;
ll use_water[86400];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		ll n, m;
		scanf("%lld %lld", &n, &m);
		if (n == 0 && m == 0)break;

		fill(use_water, use_water + 86400, 0);
		ll a, b, c;
		ll need_water = 0;
		while (n--) {
			scanf("%lld %lld %lld", &a, &b, &c);
			c *= upper;
			need_water = max(need_water, c);
			for (int i = a; i < b; i++) {
				use_water[i] += c;
			}

		}

		ll s = 0, e = need_water;
		ll ans = -1;
		while (s <= e) {
			//cout << s << "~" << e << "=>";
			ll mid = (s + e) / 2;
			//cout << mid << "\n";
			ll now_state = m * upper;
			bool is_failed = false;
			ll first_set = -1;
			for (int timer = 0; timer < daytime; timer++) {
				now_state = min(now_state - use_water[timer] + mid, m * upper);
				if (now_state < 0) {
					is_failed = true;
					break;
				}
				if (timer == daytime-1) {
					first_set = now_state;
					break;
				}
			}
			if (!is_failed) {
				for (int timer = 0; timer < daytime; timer++) {
					now_state = min(now_state - use_water[timer] + mid, m * upper);
					if (now_state < 0) {
						is_failed = true;
						break;
					}
					if (timer == daytime-1) {
						if (now_state < first_set) {
							is_failed = true;
						}
						break;
					}
				}
			}

			if (is_failed) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
				ans = mid;
			}
		}
		assert(ans != -1);

		printf("%.10lf\n", double(ans) / upper);
	}
}