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

ll_ll sort_p;

ll pow_distance(ll_ll a, ll_ll b) {
	return (a.fi - b.fi) * (a.fi - b.fi) 
		+ (a.se - b.se) * (a.se - b.se);
}
bool cmp(ll_ll a, ll_ll b) {
	ll a_h = ccw({ a.fi - sort_p.fi,a.se - sort_p.se }
	, { b.fi - a.fi,b.se - a.se });
	if (a_h == 0) {
		return pow_distance(sort_p, a) < pow_distance(sort_p, b);
	}
	return a_h > 0;
}

double PI = 3.141592;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, l, a, b;
	deque<ll_ll>arr;

	cin >> n >> l;
	while (n--) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	sort_p = arr.front();
	arr.pop_front();
	sort(arr.begin(), arr.end(), cmp);

	deque<ll_ll>brr = { sort_p };

	while (arr.size()) {
		ll_ll p = arr.front();
		arr.pop_front();
		while (brr.size() >= 2) {
			ll_ll h2 = brr.back();
			brr.pop_back();
			ll_ll h1 = brr.back();
			brr.pop_back();
			ll h = ccw({ h2.fi - h1.fi,h2.se - h1.se },
				{ p.fi - h2.fi,p.se - h2.se });
			if (h <= 0) {
				brr.push_back(h1);
				continue;
			}
			else {
				brr.push_back(h1);
				brr.push_back(h2);
				break;
			}
		}
		brr.push_back(p);
	}

	{
		ll_ll p = brr.front();
		while (brr.size() >= 3) {
			ll_ll h2 = brr.back();
			brr.pop_back();
			ll_ll h1 = brr.back();
			brr.pop_back();
			ll h = ccw({ h2.fi - h1.fi,h2.se - h1.se },
				{ p.fi - h2.fi,p.se - h2.se });
			if (h <= 0) {
				brr.push_back(h1);
				continue;
			}
			else {
				brr.push_back(h1);
				brr.push_back(h2);
				break;
			}
		}
		brr.push_back(p);
	}

	double ans = 2 * PI * l;
	for (int i = 0; i<int(brr.size()) - 1; i++) {
		ll_ll h1 = brr[i];
		ll_ll h2 = brr[i + 1];
		ans += sqrt(pow_distance(h2, h1));
	}
	ll h = round(ans);
	cout << h;
}