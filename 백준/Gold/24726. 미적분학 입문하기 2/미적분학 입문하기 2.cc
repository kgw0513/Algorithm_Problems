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

inline double truncated_cone(double r1, double r2, double h) {
	return PI * h * (r1 * r1 + r1 * r2 + r2 * r2);
}

bool sort_x(intint& a, intint& b) {
	if (a.fi == b.fi)return a.se < b.se;
	return a.fi < b.fi;
}

bool sort_y(intint& a, intint& b) {
	if (a.se == b.se)return a.fi < b.fi;
	return a.se < b.se;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	intint a, b, c;
	cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;

	vector<intint>x_array = { a,b,c };
	vector<intint>y_array = { a,b,c };

	sort(x_array.begin(), x_array.end(), sort_x);
	sort(y_array.begin(), y_array.end(), sort_y);

	//cout << x_array[0].fi << "," << x_array[0].se << " / " << x_array[1].fi << "," << x_array[1].se << " / " << x_array[2].fi << "," << x_array[2].se << "\n";

	double ans_x = 0, ans_y = 0;
	ans_x += truncated_cone(x_array[0].se, x_array[2].se, x_array[2].fi - x_array[0].fi);
	ans_x -= truncated_cone(x_array[1].se, x_array[2].se, x_array[2].fi - x_array[1].fi);
	ans_x -= truncated_cone(x_array[0].se, x_array[1].se, x_array[1].fi - x_array[0].fi);

	ans_y += truncated_cone(y_array[0].fi, y_array[2].fi, y_array[2].se - y_array[0].se);
	ans_y -= truncated_cone(y_array[1].fi, y_array[2].fi, y_array[2].se - y_array[1].se);
	ans_y -= truncated_cone(y_array[0].fi, y_array[1].fi, y_array[1].se - y_array[0].se);

	cout.precision(10);
	cout << abs(ans_x/3.0) << " " << abs(ans_y/3.0);
}