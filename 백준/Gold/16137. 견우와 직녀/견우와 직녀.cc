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
#include <complex>
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
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

int dp[12][12][2];
int state[12][12];

//{위치,{비용,새로 짓는건가?=>1}}
vector<int2_int2>lines[12][12];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

struct cmp {
	bool operator()(int2_int2& a, int2_int2& b) {
		return a.se.se > b.se.se;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = nINF;
			}
		}
	}
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> state[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			intint p = { i,j };
			if (state[p.fi][p.se] == 0) {
				for (int hp1 = 0; hp1 < 4; hp1++) {
					for (int hp2 = hp1 + 1; hp2 < 4; hp2++) {
						intint h1 = dxdy[hp1];
						intint h2 = dxdy[hp2];
						if (state[p.fi + h1.fi][p.se + h1.se] == 1 &&
							state[p.fi + h2.fi][p.se + h2.se] == 1) {
							lines[p.fi + h1.fi][p.se + h1.se].push_back({ {p.fi + h2.fi,p.se + h2.se},{t,1} });
							lines[p.fi + h2.fi][p.se + h2.se].push_back({ {p.fi + h1.fi,p.se + h1.se},{t,1} });
						}
					}
				}
				continue;
			}
			if (state[p.fi][p.se] == 1) {
				for (intint xy : dxdy) {
					intint new_p = { p.fi + xy.fi,p.se + xy.se };
					if (state[new_p.fi][new_p.se] != 1)continue;
					lines[p.fi][p.se].push_back({ new_p,{1,0} });
					lines[new_p.fi][new_p.se].push_back({ p,{1,0} });
				}
				continue;
			}
			for (int hp1 = 0; hp1 < 4; hp1++) {
				for (int hp2 = hp1 + 1; hp2 < 4; hp2++) {
					intint h1 = dxdy[hp1];
					intint h2 = dxdy[hp2];
					if (state[p.fi + h1.fi][p.se + h1.se] == 1 &&
						state[p.fi + h2.fi][p.se + h2.se] == 1) {
						lines[p.fi + h1.fi][p.se + h1.se].push_back({ {p.fi + h2.fi,p.se + h2.se},{state[p.fi][p.se],0} });
						lines[p.fi + h2.fi][p.se + h2.se].push_back({ {p.fi + h1.fi,p.se + h1.se},{state[p.fi][p.se],0} });
					}
				}
			}
		}
	}

	priority_queue<int2_int2, vector<int2_int2>, cmp>arr;
	arr.push({ {1,1},{0,0} });
	dp[1][1][0] = 0;
	while (!arr.empty()) {
		intint p = arr.top().fi;
		int cost = arr.top().se.fi;
		int creating = arr.top().se.se;
		arr.pop();
		if (dp[p.fi][p.se][creating] != cost)continue;

		for (int2_int2 h : lines[p.fi][p.se]) {
			intint new_p = h.fi;
			if (h.se.fi == 1) { //어차피 새로 짓는 경우는 안들어오기에 그냥 처리
				int new_cost = cost + h.se.fi;
				int new_creating = creating;
				if (dp[new_p.fi][new_p.se][new_creating] <= new_cost)continue;
				dp[new_p.fi][new_p.se][new_creating] = new_cost;
				arr.push({ new_p,{new_cost,new_creating} });
			}
			else {
				if (h.se.se == 1 && creating == 1)continue;
				int new_cost = (cost + h.se.fi) / h.se.fi;
				new_cost *= h.se.fi;
				new_cost += 1;
				int new_creating = max(h.se.se, creating);
				if (dp[new_p.fi][new_p.se][new_creating] <= new_cost)continue;
				dp[new_p.fi][new_p.se][new_creating] = new_cost;
				arr.push({ new_p,{new_cost,new_creating} });
			}
		}
	}

	assert(min(dp[n][n][0], dp[n][n][1]) != INF);
	cout << min(dp[n][n][0], dp[n][n][1]);
}