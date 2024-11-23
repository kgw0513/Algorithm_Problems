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

vector<intint>lines[1001];
int cost[1001][1001];

struct cmp {
	bool operator()(intint& a, intint& b) {
		return a.fi < b.fi;
	}
};
void min_move(int p) {
	cost[p][p] = INF;
	priority_queue<intint,vector<intint>,cmp>arr;
	arr.push({ INF ,p});
	while (arr.size()) {
		int now_min = arr.top().fi;
		int now_p = arr.top().se;
		arr.pop();
		if (cost[p][now_p] != now_min)continue;
		for (intint h : lines[now_p]) {
			int new_p = h.fi;
			int new_min = min(h.se, now_min);
			if (cost[p][new_p] < new_min) {
				cost[p][new_p] = new_min;
				arr.push({ new_min,new_p });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	while (m--) {
		cin >> a >> b >> c;
		lines[a].push_back({ b,c });
		lines[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		min_move(i);
	}
	while (k--) {
		cin >> a >> b;
		cout << cost[a][b] << "\n";
	}
}