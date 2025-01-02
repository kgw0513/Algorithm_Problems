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

int counter[1001] = {};

int inputs[6];
int dist[6] = { 5,10,20,50,100,200 };

int ans;

void dfs(int p,int now_state,int counting) {
	if (p >= 6) {
		if (now_state > 0)return;
		int change_money = abs(now_state);
		if (change_money > 1000)return;
		//cout << counting << "+" << counter[change_money] << "(" << change_money << ")" << "발견.\n";
		ans = min(ans, counting + counter[change_money]);
		return;
	}
	if (inputs[p] > 0) {
		inputs[p]--;
		dfs(p, now_state - dist[p], counting + 1);
		inputs[p]++;
	}
	dfs(p + 1, now_state, counting);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill(counter, counter + 1001, INF);
	counter[0] = 0;

	for (int p = 1; p <= 1000; p++) {
		for (int i = 0; i < 6; i++) {
			int last_p = p - dist[i];
			if (last_p < 0)break;
			counter[p] = min(counter[last_p] + 1, counter[p]);
		}
	}

	while (1) {
		ans = INF;

		{
			int max_money = 0;
			for (int i = 0; i < 6; i++) {
				cin >> inputs[i];
				max_money = max(max_money, inputs[i]);
			}

			if (max_money == 0)
				break;
		}

		string w;
		cin >> w;
		int int_money = 0;
		{
			for (char c : w) {
				if (c == '.')continue;
				int_money *= 10;
				int_money += c - '0';
			}
		}
		
		dfs(0, int_money, 0);
		if (ans >= 100)cout << ans << "\n";
		else if (ans >= 10)cout << " " << ans << "\n";
		else cout << "  " << ans << "\n";
	}
}