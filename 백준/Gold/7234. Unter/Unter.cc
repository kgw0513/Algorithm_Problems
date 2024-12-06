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

vector<int>line[200001];

bool visit[200001];
int cycle[200001];
int cycle_line = 0;

intint back_track[200001];
pair<bool, int> dfs(int p, int last_p) {
	visit[p] = true;
	for (int new_p : line[p]) {
		if (new_p == last_p)continue;
		if (visit[new_p]) {
			cycle[p] = 1;
			cycle_line = 1;
			//cout << p << "에서 시작 : " << new_p << "\n";
			return { true,new_p };
		}
		pair<bool, int> h = dfs(new_p, p);
		if (h.fi) {
			if (h.se == -1)return { true,-1 };
			cycle[p] = cycle[new_p] + 1;
			cycle_line = cycle[p];
			if (h.se == p )return { true,-1 };
			//cout << p << "에서" << h.se << "반환중.\n";
			return h;
		}
	}
	return { false,-1 };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
	dfs(1, -1);

	fill(visit, visit + n + 1, false);
	queue<intint>arr;//{조상,현위치}
	for (int i = 1; i <= n; i++) {
		if (cycle[i]) {
			arr.push({i,i});
			visit[i] = true; 
			back_track[i] = { -1,0 };
		}
	}
	int timer = 0;
	while (arr.size()) {
		timer++;
		int size = arr.size();
		while (size--) {
			int now_p = arr.front().se;
			int ancestor = arr.front().fi;
			arr.pop();
			for (int new_p : line[now_p]) {
				if (visit[new_p])continue;
				visit[new_p] = true;
				back_track[new_p] = { ancestor,timer };
				arr.push({ ancestor,new_p });
			}
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		if (back_track[a].fi != -1) {
			ans += back_track[a].se;
			//cout << back_track[a].se << "?1\n";
			a = back_track[a].fi;
		}

		if (back_track[b].fi != -1) {
			ans += back_track[b].se;
			//cout << back_track[b].se << "?2\n";
			b = back_track[b].fi;
		}

		//cout << ans << "중간.\n";
		cout << ans + min({ abs(cycle[a] - cycle[b]),abs(cycle_line + cycle[a] - cycle[b]),abs(cycle[a] - cycle[b] - cycle_line) }) << "\n";
	}
}