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

ll trans_hub[201][20001];
vector<ll_ll>lines[20001];
ll hub_num[20001];

struct cmp {
	bool operator()(intint& a, intint& b) {
		return a.se > b.se;
	}
};
void Dijkstra(ll s) {
	ll s_trans = hub_num[s];
	fill(trans_hub[s_trans], trans_hub[s_trans] + 20001, lINF);
	priority_queue<intint>arr;
	arr.push({ s,0 });
	trans_hub[s_trans][s] = 0;
	while (arr.size()) {
		ll now_p = arr.top().fi;
		ll now_cost = arr.top().se;
		arr.pop();
		if (trans_hub[s_trans][now_p] != now_cost)continue;
		for (int i = 0; i < lines[now_p].size(); i++) {
			ll new_p = lines[now_p][i].fi;
			ll new_cost = now_cost + lines[now_p][i].se;
			if (trans_hub[s_trans][new_p] > new_cost) {
				trans_hub[s_trans][new_p] = new_cost;
				arr.push({ new_p,new_cost });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, q, a, b, c;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		lines[a].push_back({ b,c });
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		hub_num[a] = i + 1;
		Dijkstra(a);
	}

	ll ans = 0;
	ll sum = 0;
	while (q--) {
		cin >> a >> b;
		if (hub_num[a] != 0) {
			if (trans_hub[hub_num[a]][b] != lINF) {
				ans++;
				sum += trans_hub[hub_num[a]][b];
			}
			continue;
		}

		ll find_min = lINF;
		for (int i = 0; i < lines[a].size(); i++) {
			find_min = min(find_min, trans_hub[hub_num[lines[a][i].fi]][b] + lines[a][i].se);
		}
		if (find_min != lINF) {
			ans++;
			sum += find_min;
		}
	}
	cout << ans << "\n" << sum;
}