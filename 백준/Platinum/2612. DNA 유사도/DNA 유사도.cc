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

int2_int dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string w1, w2;
	cin >> w1 >> w1 >> w2 >> w2;
	w1 = "X" + w1;
	w2 = "X" + w2;
	for (int i = 0; i < 1002; i++) {
		dp[i][0] = { { -nINF,-nINF },-nINF };
		dp[0][i] = { { -nINF,-nINF },-nINF };
	}

	int2_int ans = { {-100,-100},-nINF };
	for (int p = 1; p < min(w1.size(), w2.size()); p++) {
		//cout << p << "번째.\n";
		for (int i = p; i < w1.size(); i++) {
			//[i][p]
			dp[i][p] = { {-1,-1},(w1[i] == w2[p] ? 3 : -2) };

			int h = dp[i - 1][p - 1].se + (w1[i] == w2[p] ? 3 : -2);

			if (h > dp[i][p].se) {
				dp[i][p] = { {i - 1,p - 1},dp[i - 1][p - 1].se + (w1[i] == w2[p] ? 3 : -2) };
			}

			h = dp[i][p - 1].se - 2;
			if (h > dp[i][p].se) {
				dp[i][p] = { {i,p - 1},h };
			}

			h = dp[i - 1][p].se - 2;
			if (h > dp[i][p].se) {
				dp[i][p] = { {i - 1,p},h };
			}

			if (ans.se < dp[i][p].se)ans = { { i,p },dp[i][p].se };
		}
		for (int j = p; j < w2.size(); j++) {
			//[p][j]

			if (p == j) {
				int h = (w1[p] == w2[j] ? 3 : -2);
				if (h > dp[p][j].se)dp[p][j] = { {-1,-1},h };
			}
			else dp[p][j] = { {-1,-1},(w1[p] == w2[j] ? 3 : -2) };

			int h = dp[p - 1][j - 1].se + (w1[p] == w2[j] ? 3 : -2);
			if (h > dp[p][j].se) {
				dp[p][j] = { {p - 1,j - 1},dp[p - 1][j - 1].se + (w1[p] == w2[j] ? 3 : -2) };
			}

			h = dp[p - 1][j].se - 2;
			if (h > dp[p][j].se) {
				dp[p][j] = { {p - 1,j},h };
			}

			h = dp[p][j - 1].se - 2;
			if (h > dp[p][j].se) {
				dp[p][j] = { {p,j - 1},h };
			}

			if (ans.se < dp[p][j].se)ans = { {p,j},dp[p][j].se };
		}
	}

	cout << ans.se << "\n";

	string a = "";
	string b = "";

	while (ans.fi.fi != -1) {
		//cout << ans.fi.fi << "," << ans.fi.se << "이동.\n";

		if (dp[ans.fi.fi][ans.fi.se].fi.fi != ans.fi.fi)a += w1[ans.fi.fi];
		if (dp[ans.fi.fi][ans.fi.se].fi.se != ans.fi.se)b += w2[ans.fi.se];
		ans.fi = dp[ans.fi.fi][ans.fi.se].fi;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	cout << a << "\n" << b;
}