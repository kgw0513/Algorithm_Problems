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

int find(vector<int>& Union, int p) {
	if (Union[p] == p)return p;
	return Union[p] = find(Union, Union[p]);
}
struct cmp {
	bool operator()(int_int2& a, int_int2& b) {
		return a.fi > b.fi;
	}
};
void cal() {
	int n, m, p, q, u, v, w;
	cin >> n >> m >> p >> q;
	if (p > q)swap(p, q);
	vector<int>Union(n + 1);
	for (int i = 1; i <= n; i++) {
		Union[i] = i;
	}
	priority_queue<int_int2, vector<int_int2>, cmp>arr;
	while (m--) {
		cin >> u >> v >> w;
		if (u > v)swap(u, v);
		arr.push({ w,{u,v} });
	}
	while (arr.size()) {
		u = arr.top().se.fi;
		v = arr.top().se.se;
		int a = u;
		int b = v;
		arr.pop();
		u = find(Union, u);
		v = find(Union, v);
		if (u == v)continue;
		if (u > v)swap(u, v);
		Union[v] = u;
		if (p == a && q == b) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cal();
	}
}