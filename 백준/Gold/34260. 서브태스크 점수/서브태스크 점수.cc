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

//[문제][냅색]={경우의수}
ll arr[31][3001];

//[문제][섭테]={섭테별 필요 조건}
ll need_solve[31][11];

bool visit_time[31][4097];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	arr[0][0] = 1;

	ll p;
	cin >> p;
	for (int prob = 1; prob <= p; prob++) {
		bool bit_comp[2048] = {};
		vector<ll>brr;
		for (int i = 0; i <= 3000; i++) {
			arr[prob][i] = arr[prob - 1][i];
		}

		int n, m;
		cin >> n >> m;

		vector<ll>prob_score;
		for (int i = 1; i <= n; i++) {
			ll w;
			cin >> w;
			prob_score.push_back(w);
		}

		for (int t = 1; t <= m; t++) {
			int a, b;
			cin >> a >> b;
			need_solve[prob][b-1] |= (1ll << (a-1));
		}

		for (ll now_state = 0; now_state < (1ll<<n); now_state++) {
			bool is_can = true;
			for (int test = 0; test < n; test++) {
				if (((now_state & (1ll << test)) != 0) && ((need_solve[prob][test] & now_state) != need_solve[prob][test])) {
					is_can = false;
					break;
				}
			}
			if (!is_can)continue;
			brr.push_back(now_state);
		}

		for (ll h : brr) {
			ll now_score = 0;
			//cout << h << "들.\n";
			for (int test = 0; test < n; test++) {
				if ((h & (1ll << test)) == 0)continue;
				//cout << test << "통과.\n";
				now_score += prob_score[test];
			}
			//cout << h << "가능! =>" << now_score << "?\n";
			if (now_score == 0)continue;
			for (int state = p * 100 - now_score; state >= 0; state--) {
				arr[prob][state + now_score] += arr[prob - 1][state];
				arr[prob][state + now_score] %= MOD3;
			}
		}
		//for (int state = 0; state <= p * 100; state += 100) {
		//	cout << arr[prob][state] << ",";
		//}
		//cout << " 중.\n";
	}
	ll ans = 0;
	for (int state = 0; state <= p * 100; state++) {
		ans += arr[p][state] * state;
		ans %= MOD3;
	}
	cout << ans % MOD3;
}