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

ll visit[1001][51];

struct cmp {
	bool operator()(ll_ll2& a, ll_ll2& b) {
		return a.fi > b.fi;
	}
};
//{현 비용,{현 위치, 특수능력 사용횟수}}
priority_queue<ll_ll2, vector<ll_ll2>, cmp>arr[1001];

vector<ll_ll>lines[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 51; j++) {
			visit[i][j] = INF;
		}
	}

	ll n, m, c, from, to, cost;
	cin >> n >> m >> c;
	while (m--) {
		cin >> from >> to >> cost;
		lines[from].push_back({ to,cost });
	}

	visit[0][1] = 0;
	arr[0].push({ 0,{1,0} });
	for (int loop = 0; loop <= c; loop++) {
		while (arr[loop].size()) {
			ll now_h = arr[loop].top().se.fi;
			ll now_cost = arr[loop].top().fi;
			ll now_power = arr[loop].top().se.se;
			arr[loop].pop();
			if (visit[now_power][now_h] != now_cost)continue;
			for (intint h : lines[now_h]) {
				ll new_h = h.fi;
				{//능력 안쓸때
					ll new_cost = now_cost + h.se;
					ll new_power = now_power;
					if (visit[new_power][new_h] > new_cost) {
						visit[new_power][new_h] = new_cost;
						arr[new_power].push({ new_cost,{new_h,new_power} });
					}
				}

				{//능력 쓸때
					ll new_cost = now_cost - h.se;
					ll new_power = now_power + 1;
					if (new_power <= c && visit[new_power][new_h] > new_cost) {
						visit[new_power][new_h] = new_cost;
						arr[new_power].push({ new_cost,{new_h,new_power} });
					}
				}
			}
		}
	}

	ll ans = visit[0][n];
	for (int i = 1; i <= c; i++) {
		ans = min(ans, visit[i][n]);
	}
	cout << ans;
}