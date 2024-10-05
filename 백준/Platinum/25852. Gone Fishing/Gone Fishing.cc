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

ll ccw(ll_ll a, ll_ll b) {
	return a.fi * b.se - a.se * b.fi;
}

double dist(ll_ll a, ll_ll b) {
	return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

double d_dist(dd a, dd b) {
	return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

dd Point(ll_ll a, ll_ll b, ll_ll c,bool& is_can) {
	dd h1 = { b.fi - a.fi,b.se - a.se };
	dd h2 = { c.fi - b.fi,c.se - b.se };
	ll div = ccw(h1, h2);
	if (div == 0) {
		is_can = false;
		return { -1,-1 };
	}

	dd h3 = { h2.se,-h1.se };
	dd h4 = { -h2.fi,h1.fi };
	h1 = h3;
	h2 = h4;

	h1.fi *= 1 / double(div);
	h1.se *= 1 / double(div);
	h2.fi *= 1 / double(div);
	h2.se *= 1 / double(div);
	h1.fi *= 1 / 2.0;
	h1.se *= 1 / 2.0;
	h2.fi *= 1 / 2.0;
	h2.se *= 1 / 2.0;
	double h_x = b.fi * b.fi - a.fi * a.fi + b.se * b.se - a.se * a.se;
	double h_y = c.fi * c.fi - b.fi * b.fi + c.se * c.se - b.se * b.se;

	double x = h1.fi * h_x + h1.se * h_y;
	double y = h2.fi * h_x + h2.se * h_y;
	return { x,y };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll r,n;
	cin >> r >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<ll_ll>inputs(n);
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		inputs[i] = { a,b };
	}

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dd p = { (double(inputs[i].fi) + double(inputs[j].fi)) / 2.0,
			(double(inputs[i].se) + double(inputs[j].se)) / 2.0 };

			ll count = 0;
			for (ll_ll re_p : inputs) {
				double h = d_dist(p, re_p);
				if (h <= r) {
					count++;
				}
			}
			ans = max(ans, count);
		}
	}

	if (n == 2) {
		cout << ans;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				bool is_can = true;
				dd p = Point(inputs[i], inputs[j], inputs[k], is_can);
				if (!is_can)continue;
				ll count = 0;
				for (ll_ll re_p : inputs) {
					double h = d_dist(p, re_p);
					if (h <= r) {
						count++;
					}
				}
				ans = max(ans, count);
			}
		}
	}
	cout << ans;
}