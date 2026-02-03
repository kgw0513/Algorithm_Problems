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

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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

//{이전 위치,값}
ll2_ll dp[1002][1002];

inline ll dist_cal(ll_ll lp, ll_ll p) {
	return abs(lp.fi - p.fi) + abs(lp.se - p.se);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			dp[i][j] = { {INF,INF},INF };
		}
	}
	dp[0][0] = { {-1,-1},0 };

	vector<ll_ll>track = { {-1,-1} };
	ll n, w, a, b;
	cin >> n >> w;
	for (int t = 1; t <= w; t++) {
		cin >> a >> b;

		//마지막으로 움직인게 1번 경찰차일때
		{
			//1번 경찰차를 움직일때
			for (int j = 0; j < t; j++) {
				if (t - 1 == 0) {
					ll cal = dist_cal({ 1,1 }, { a,b }) + dp[t - 1][j].se;
					if (dp[t][j].se > cal) {
						dp[t][j] = { {t - 1,j},cal };
					}
					continue;
				}
				ll cal = dist_cal(track[t - 1], { a,b }) + dp[t - 1][j].se;
				if (dp[t][j].se > cal) {
					dp[t][j] = { {t - 1,j},cal };
				}
			}

			//2번 경찰차를 움직일때
			for (int j = 0; j < t; j++) {
				if (j == 0) {
					ll cal = dist_cal({ n,n }, { a,b }) + dp[t - 1][j].se;
					if (dp[t - 1][t].se > cal) {
						dp[t - 1][t] = { {t - 1,j},cal };
					}
					continue;
				}
				ll cal = dist_cal(track[j], { a,b }) + dp[t - 1][j].se;
				if (dp[t - 1][t].se > cal) {
					dp[t - 1][t] = { {t - 1,j},cal };
				}
			}
		}

		//마지막으로 움직인게 2번 경찰차일때
		{
			//1번 경찰차를 움직일때
			for (int j = 0; j < t; j++) {
				if (j == 0) {
					ll cal = dist_cal({ 1,1 }, { a,b }) + dp[j][t - 1].se;
					if (dp[t][t - 1].se > cal) {
						dp[t][t - 1] = { {j,t - 1},cal };
					}
					continue;
				}
				ll cal = dist_cal(track[j], { a,b }) + dp[j][t - 1].se;
				if (dp[t][t - 1].se > cal) {
					dp[t][t - 1] = { {j,t - 1},cal };
				}
			}

			//2번 경찰차를 움직일때
			for (int j = 0; j < t; j++) {
				if (t - 1 == 0) {
					ll cal = dist_cal({ n,n }, { a,b }) + dp[j][t - 1].se;
					if (dp[j][t].se > cal) {
						dp[j][t] = { {j,t - 1},cal };
					}
					continue;
				}
				ll cal = dist_cal(track[t - 1], { a,b }) + dp[j][t - 1].se;
				if (dp[j][t].se > cal) {
					dp[j][t] = { {j,t - 1},cal };
				}
			}
		}
		track.push_back({ a,b });
	}

	ll ans = INF;
	ll_ll p = { -1,-1 };
	for (int i = 0; i <= w; i++) {
		if (ans > dp[w][i].se) {
			ans = dp[w][i].se;
			p = { w,i };
		}
		if (ans > dp[i][w].se) {
			ans = dp[i][w].se;
			p = { i,w };
		}
	}
	assert(ans != INF);
	cout << ans << "\n";
	stack<int>arr;
	while (dp[p.fi][p.se].fi.fi!=-1) {
		ll_ll lp = dp[p.fi][p.se].fi;
		//cout << p.fi << "," << p.se << "<=>" << lp.fi << "," << lp.se << "?\n";
		if (lp.fi == p.fi)arr.push(2);
		else arr.push(1);
		p = lp;
	}
	while (!arr.empty()) {
		cout << arr.top() << "\n";
		arr.pop();
	}
}