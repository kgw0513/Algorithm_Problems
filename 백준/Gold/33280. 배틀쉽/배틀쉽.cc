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

constexpr double PI = 3.1415926535;
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

typedef pair<int, char>inch;
typedef pair<intint, inch> int2_inch;
bool visit[502][502];
deque<int2_inch>ans;
char char_dxdy[4] = { 'U','D','L','R' };
intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
[[nodiscard]] int dfs(intint now_p, bool is_move, intint move_dxdy={-1,-1}) {
	if (is_move && !visit[now_p.fi+move_dxdy.fi][now_p.se+move_dxdy.se]) {
		return dfs({ now_p.fi + move_dxdy.fi,now_p.se + move_dxdy.se }, is_move, move_dxdy);
	}
	is_move = false;
	visit[now_p.fi][now_p.se] = true;

	int move_count = 0;
	for (int i = 0; i < 4; i++) {
		intint new_p = { now_p.fi + dxdy[i].fi,now_p.se + dxdy[i].se };
		if (visit[new_p.fi][new_p.se])
			continue;
		int h = dfs(new_p, true, dxdy[i]);
		assert(h > 0);
		ans.push_back({ now_p,{h,char_dxdy[i]} });
		move_count += h;
	}
	return move_count + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 502; i++) {
		for (int j = 0; j < 502; j++) {
			visit[i][j] = true;
		}
	}
	int n, m;
	cin >> n >> m;
	int need_visit = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char w;
			cin >> w;
			if (w == '.')visit[i][j] = false;
			else need_visit--;
		}
	}

	intint source;
	cin >> source.fi >> source.se;
	if (dfs(source, false)!=need_visit) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	while (ans.size()) {
		cout << ans.back().fi.fi << " " << ans.back().fi.se << " " << ans.back().se.fi << " " << ans.back().se.se << "\n";
		ans.pop_back();
	}
}