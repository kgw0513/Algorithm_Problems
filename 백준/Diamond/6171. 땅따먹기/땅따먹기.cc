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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
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

//{{넓이,땅 값},교점}
pair<ll_ll,double> ans[50001];
int now_p = 0;

vector<ll_ll>inputs;
deque<ll_ll>arr;
bool cmp(ll_ll& a, ll_ll& b) {
	if (a.fi != b.fi)return a.fi > b.fi;
	return a.se > b.se;
}

double cross_point(ll_ll h1, ll_ll h2) {
	return double(h1.se - h2.se) / double(h2.fi - h1.fi);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		ll a, b;
		cin >> a >> b;
		inputs.push_back({ a,b });
	}

	sort(inputs.begin(), inputs.end(), cmp);
	ll max_h = 0;
	for (ll_ll& h : inputs) {
		if (h.se <= max_h)continue;
		max_h = h.se;
		arr.push_front(h);
	}

	ll lastprice = 0;
	for (int i = 0; i < arr.size(); i++) {
		pair<ll_ll, double>h = { {arr[i].se,lastprice},0};
		while (now_p >= 1) {
			h.se = cross_point(h.fi, ans[now_p-1].fi);
			if (h.se > ans[now_p - 1].se)break;
			now_p--;
		}
		ans[now_p++] = h;
		//cout << arr[i].fi << "," << arr[i].se << ":";
		//cout << h.se << "교점.\n";
		
		int s = 0, e = now_p - 1, ans_p = -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (ans[mid].se < arr[i].fi) {
				ans_p = mid;
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
		//cout << now_p << "/" << ans_p << "?\n";
		assert(ans_p != -1);
		lastprice = ans[ans_p].fi.fi * arr[i].fi + ans[ans_p].fi.se;
	}
	cout << lastprice;
}