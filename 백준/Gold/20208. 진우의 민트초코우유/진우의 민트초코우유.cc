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

inline int texi_geo(intint a, intint b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}
vector<intint>arr;
vector<int>brr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, h, w;
	intint start_p;
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w;
			if (w == 1)start_p = { i,j };
			else if (w == 2) {
				brr.push_back(arr.size());
				arr.push_back({ i,j });
			}
		}
	}

	int ans = 0;
	do {
		intint now_p = start_p;
		int now_h = m;
		for (int i = 0; i < brr.size(); i++) {
			int new_state = brr[i];
			intint new_p = arr[new_state];
			int dist = texi_geo(now_p, new_p);
			now_h -= dist;
			if (now_h < 0)break;
			now_h += h;
			now_p = new_p;
			int back_dist = texi_geo(now_p, start_p);
			if (now_h >= back_dist)ans = max(ans, i + 1);
		}
	} while (next_permutation(brr.begin(), brr.end()));

	cout << ans;
}