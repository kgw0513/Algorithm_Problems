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

//[건너간 상태][망토가 기숙사에 있으면 1]
ll dp[1 << 15][2];

struct cmp {
	bool operator()(ll2_ll& a, ll2_ll& b) {
		return a.se > b.se;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> arr(n);
	for (ll& w : arr) {
		cin >> w;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < (1 << 15); i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = nlINF;
		}
	}

	dp[0][0] = 0;

	priority_queue<ll2_ll,vector<ll2_ll>,cmp>brr;
	brr.push({ { 0,0 },0 });

	while (!brr.empty()) {
		ll_ll p = brr.top().fi;
		ll cost = brr.top().se;
		brr.pop();

		if (dp[p.fi][p.se] != cost)continue;

		//망토가 정문에 있을때
		if (p.se == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((((p.fi & (1ll << i)) == 0) && ((p.fi & (1ll << j))) == 0)) {
						//건너가지 않은 애들중 2명 고르기
						ll_ll new_p = { (p.fi | (1ll << i) | (1ll << j)) ,1 };
						ll new_cost = cost + arr[j];
						if (dp[new_p.fi][new_p.se] > new_cost) {
							dp[new_p.fi][new_p.se] = new_cost;
							brr.push({ new_p,new_cost });
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if ((p.fi & (1ll << i)) == 0) {
					//건너가지 않은 애들중 1명 고르기
					ll_ll new_p = { (p.fi | (1ll << i)) ,1 };
					ll new_cost = cost + arr[i];
					if (dp[new_p.fi][new_p.se] > new_cost) {
						dp[new_p.fi][new_p.se] = new_cost;
						brr.push({ new_p,new_cost });
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((((p.fi & (1ll << i)) != 0) && ((p.fi & (1ll << j))) != 0)) {
						//건너간 애들중 2명 고르기 (근데 2명 돌려보내면 별로일거 같지만 일단 ㄱㄱ)
						ll_ll new_p = { (p.fi ^ (1ll << i) ^ (1ll << j)) ,0 };
						ll new_cost = cost + arr[j];
						if (dp[new_p.fi][new_p.se] > new_cost) {
							dp[new_p.fi][new_p.se] = new_cost;
							brr.push({ new_p,new_cost });
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if ((p.fi & (1ll << i)) != 0) {
					//건너간 애들중 1명 고르기
					ll_ll new_p = { (p.fi ^ (1ll << i)) ,0 };
					ll new_cost = cost + arr[i];
					if (dp[new_p.fi][new_p.se] > new_cost) {
						dp[new_p.fi][new_p.se] = new_cost;
						brr.push({ new_p,new_cost });
					}
				}
			}
		}
	}

	cout << dp[(1 << n) - 1][1];
}