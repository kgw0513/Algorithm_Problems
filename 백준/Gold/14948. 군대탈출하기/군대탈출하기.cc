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

int state[102][102];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int dp[102][102][2];

struct cmp {
	bool operator()(int2_int2& a, int2_int2& b) {
		return a.se.se > b.se.se;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> state[i][j];
		}
	}
    
    dp[1][1][0] = state[1][1];
	priority_queue<int2_int2, vector<int2_int2>, cmp>arr;
	arr.push({ {1,1},{0,state[1][1]}});
    
	while (!arr.empty()) {
		intint p = arr.top().fi;
		int jump = arr.top().se.fi;
		int score = arr.top().se.se;
		arr.pop();
		if (dp[p.fi][p.se][jump] != score)continue;

		for (intint xy : dxdy) {
			{ //타일 무시 안하기
				intint new_p = { p.fi + xy.fi,p.se + xy.se };
				if (new_p.fi >= 1 && new_p.fi <= n &&
					new_p.se >= 1 && new_p.se <= m) {
					int new_jump = jump;
					int new_score = max(score, state[new_p.fi][new_p.se]);
					if (dp[new_p.fi][new_p.se][new_jump] > new_score) {
						dp[new_p.fi][new_p.se][new_jump] = new_score;
						arr.push({ new_p,{new_jump,new_score} });
					}
				}
			}

			if (jump == 0) {
				intint new_p = { p.fi + xy.fi*2,p.se + xy.se*2 };
				if (new_p.fi >= 1 && new_p.fi <= n &&
					new_p.se >= 1 && new_p.se <= m) {
					int new_jump = 1;
					int new_score = max(score, state[new_p.fi][new_p.se]);
					if (dp[new_p.fi][new_p.se][new_jump] > new_score) {
						dp[new_p.fi][new_p.se][new_jump] = new_score;
						arr.push({ new_p,{new_jump,new_score} });
					}
				}
			}
		}

	}
	cout << min(dp[n][m][0], dp[n][m][1]);
}