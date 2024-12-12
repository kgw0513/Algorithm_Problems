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
const long long nlINF = lINF / 10000;
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

intint dxdy[8] = { {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}, {-1,0} };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int2_int>inputs(n);
	for (int2_int& h : inputs) {
		cin >> h.fi.fi >> h.fi.se >> h.se;
		h.se--;
	}

	intint ans = { INF,-1 };
	//{시간,마릿수}
	for (int i = 0; i < n; i++) {
		map<int, int>arr;
		int2_int a = inputs[i];
		for (int j = 0; j < n; j++) {
			int2_int b = inputs[j];
			if (i == j || a.se == b.se)continue;

			int all_x = abs(a.fi.fi - b.fi.fi);
			int all_y = abs(a.fi.se - b.fi.se);

			int dist = max(all_x, all_y);
			intint new_a_p = { a.fi.fi + dxdy[a.se].fi * dist,a.fi.second + dxdy[a.se].se * dist };
			intint new_b_p = { b.fi.fi + dxdy[b.se].fi * dist,b.fi.second + dxdy[b.se].se * dist };

			if (new_a_p.fi != new_b_p.fi || new_a_p.se != new_b_p.se) {
				if (dist % 2 != 0)continue;
				new_a_p = { a.fi.fi + dxdy[a.se].fi * (dist / 2),a.fi.second + dxdy[a.se].se * (dist / 2) };
				new_b_p = { b.fi.fi + dxdy[b.se].fi * (dist / 2),b.fi.second + dxdy[b.se].se * (dist / 2) };

				if (new_a_p.fi != new_b_p.fi || new_a_p.se != new_b_p.se)continue;
				arr[dist/2]++;
			}
			else arr[dist]++;
		}

		for (auto h : arr) {
			//cout << h.fi << "," << h.se << "옴.\n";
			if (ans.se < h.se)ans = { h.fi,h.se };
			else if (ans.se == h.se && ans.fi > h.fi)ans = { h.fi,h.se };
		}
	}
	cout << ans.se+1 << "\n" << ans.fi;
}