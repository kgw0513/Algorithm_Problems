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

vector<intint>line[100001];

vector<int>all_dist[100001];

struct cmp {
	bool operator()(intint& a, intint& b) {
		return a.se > b.se;
	}
};
void cal(int n, int s, vector<int>& dist) {
	dist.resize(n, INF);
	dist[s] = 0;
	priority_queue<intint, vector<intint>, cmp>arr;
	arr.push({ s,0 });
	while (arr.size()) {
		intint now_h = arr.top();
		arr.pop();
		if (dist[now_h.fi] != now_h.se)continue;
		for (int i = 0; i < line[now_h.fi].size(); i++) {
			intint new_h = { line[now_h.fi][i].fi,
			now_h.se + line[now_h.fi][i].se };
			if (new_h.se >= dist[new_h.fi])continue;
			dist[new_h.fi] = new_h.se;
			arr.push(new_h);
		}
	}
}
ll ans() {
	int n, m, x, y, d;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		line[i].clear();
		all_dist[i].clear();
	}
	while (m--) {
		cin >> x >> y >> d;
		line[x].push_back({ y,d });
		line[y].push_back({ x,d });
	}
	int s, w;
	cin >> s;
	deque<int>inputs(s, 0);
	ll sum_min = lINF;

	cal(n, 0, all_dist[0]);
	for (int i = 0; i < s; i++) {
		cin >> inputs[i];
		cal(n, inputs[i], all_dist[inputs[i]]);
	}

	do {
		ll now_sum = 0;
		{
			now_sum += all_dist[0][inputs[0]];
		}
		for (int i = 0; i < s; i++) {
			if (i == s - 1)now_sum += all_dist[inputs[i]][0];
			else now_sum += all_dist[inputs[i]][inputs[i + 1]];
		}
		sum_min = min(sum_min, now_sum);
	} while (next_permutation(inputs.begin(), inputs.end()));

	return sum_min;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cout << ans() << "\n";
	}
}