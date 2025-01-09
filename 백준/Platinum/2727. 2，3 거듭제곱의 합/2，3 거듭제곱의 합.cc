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

ll three_pow[20] = { 1, };

bool dfs(ll left_sum, ll three_count,ll insert_count , ll last_two) {
	if (left_sum < 0)return false;

	if (left_sum == 0) {
		cout << insert_count << "\n";
		return true;
	}

	for (ll new_three = three_count; new_three <= 19; new_three++) {
		ll h = three_pow[new_three];
		if (h > left_sum)break;
		ll now_two = log2(left_sum / h);
		now_two = min(now_two, last_two - 1);
		for (ll new_two = max(0ll,now_two-1); new_two <= now_two; new_two++) {
			if (dfs(left_sum - (1ll << new_two) * h, new_three + 1, insert_count + 1, new_two)) {
				cout << new_two << " " << new_three << "\n";
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 19; i++) {
		three_pow[i] = three_pow[i - 1] * 3ll;
	}
	int t;
	cin >> t;
	while (t--) {
		ll w;
		cin >> w;
		assert(dfs(w, 0, 0, INF));
	}
}