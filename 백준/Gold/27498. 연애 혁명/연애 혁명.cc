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

int Union[10001];

int find(int p) {
	if (Union[p] == p)return p;
	return Union[p] = find(Union[p]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int_int2>arr;
	int n, m, a, b, c, d, sum = 0, remove_sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		Union[i] = i;
	}
	while (m--) {
		cin >> a >> b >> c >> d;
		sum += c;
		if (d == 1) {
			remove_sum += c;
			a = find(a);
			b = find(b);
			if (a < b)swap(a, b);
			Union[b] = a;
			continue;
		}
		arr.push({ c,{a,b} });
	}

	while (arr.size()) {
		int cost = arr.top().fi;
		intint h = arr.top().se;
		arr.pop();
		h = { find(h.fi),find(h.se) };
		if (h.fi == h.se)continue;
		if (h.fi > h.se)swap(h.fi, h.se);
		Union[h.se] = h.fi;
		remove_sum += cost;
	}
	cout << sum - remove_sum;
}