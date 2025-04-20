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

ll ans[300001];
vector<ll>arr;

void dfs(int s, int e) {
	if (s > e)return;

	ll2_ll max_ans = { {s,s},arr[s]};
	int sum = arr[s];
	int now_p = s;
	for (int i = s+1; i <= e; i++) {
		int w = arr[i];
		if (sum + w < w) {
			now_p = i;
		}
		sum = max(sum + w, w);
		if (sum > max_ans.se) {
			max_ans = { {now_p,i},sum };
		}
	}
	for (int i = max_ans.fi.fi; i <= max_ans.fi.se; i++) {
		ans[i] = max_ans.se;
	}
	if (s <= max_ans.fi.fi - 1) {
		arr[max_ans.fi.fi - 1] = max(arr[max_ans.fi.fi - 1], arr[max_ans.fi.fi - 1] + max_ans.se);
		dfs(s, max_ans.fi.fi - 1);
	}
	if (max_ans.fi.se + 1 <= e) {
		arr[max_ans.fi.se + 1] = max(arr[max_ans.fi.se + 1], arr[max_ans.fi.se + 1] + max_ans.se);
		dfs(max_ans.fi.se + 1, e);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//{2,-100,1,100} 3 3 101 101
	//{2,-100,1,100,-100,2} 3 3 101 101 3 3
	//{1 -10 100 -10 1 -5 1} 91 91 100 91 91 87 87
	//{5 -2 1 -100 50 -100 3 -1 4} 5 4 4 -46 50 -44 6 6 6
	int n, w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		arr.push_back(w);
	}

	dfs(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}