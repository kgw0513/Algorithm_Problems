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

/*
배치도
0 1
2 3
*/

//[방문 순서] ={위치};
int state[4] = { 0,1,3,2 };

//[위치]={{x축 이동값, y축 이동값}}
ll_ll give_value[4] = { {0,0},{1,0},{0,1},{1,1} };

ll_ll dfs(ll n, ll p) {
	if (n <= 0)return { 0,0 };

	ll h = pow(4, n - 1);
	ll plus = pow(2, n - 1);
	if (p < h) {
		swap(state[1], state[3]);
		ll_ll sum = give_value[state[0]];
		ll_ll h2 = dfs(n - 1, p);
		ll_ll h3 = { h2.fi + sum.fi * plus,h2.se + sum.se * plus };
		return h3;
	}

	p -= h;
	if (p < h) {
		ll_ll sum = give_value[state[1]];
		ll_ll h2 = dfs(n - 1, p);
		ll_ll h3 = { h2.fi + sum.fi * plus,h2.se + sum.se * plus };
		return h3;
	}

	p -= h;
	if (p < h) {
		ll_ll sum = give_value[state[2]];
		ll_ll h2 = dfs(n - 1, p);
		ll_ll h3 = { h2.fi + sum.fi * plus,h2.se + sum.se * plus };
		return h3;
	}

	p -= h;
	swap(state[0], state[2]);
	ll_ll sum = give_value[state[3]];
	ll_ll h2 = dfs(n - 1, p);
	ll_ll h3 = { h2.fi + sum.fi * plus,h2.se + sum.se * plus };
	return h3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		state[0] = 0;
		state[1] = 1;
		state[2] = 3;
		state[3] = 2;
		ll_ll h1 = dfs(n, a - 1);
		state[0] = 0;
		state[1] = 1;
		state[2] = 3;
		state[3] = 2;
		ll_ll h2 = dfs(n, b - 1);
		double h3 = (h2.fi - h1.fi) * 10;
		double h4 = (h2.se - h1.se) * 10;
		double h5 = h3 * h3 + h4 * h4;
		h5 = sqrt(h5);
		cout << round(h5) << "\n";
	}
}