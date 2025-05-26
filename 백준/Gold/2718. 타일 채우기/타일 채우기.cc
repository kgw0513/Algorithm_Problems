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
const long long nlINF = lINF / 100;
const int nINF = 1007483647;
unsigned long long MOD = 1000000007;
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

ll arr[(1 << 4)]; //last
ll brr[(1 << 4)]; //now

ll rem[35][(1 << 4)];
ll n, m;

void dfs(ll last_state, const ll last_count, ll p, ll now_state) {
	if (p > n)return;

	if (p == n) {
		assert(now_state < (1LL << n));
		brr[now_state] += last_count;
		return;
	}
	ll now_p_block = (last_state & (1LL << p)); //같은 위치 이전 블럭 상태
	ll next_p_block = (last_state & (1LL << (p + 1))); //다음 위치 이전 블럭 상태

	//가로 놓기
	if (now_p_block == 0) {
		//가로로 놓으려면 이전에 설치한 블럭이 없어야함.
		dfs(last_state, last_count, p + 1, (now_state << 1) + 1);
	}

	//세로 놓기
	if (now_p_block != 0 && next_p_block != 0) {
		dfs(last_state, last_count, p + 2, (now_state << 2) + 3);
	}

	//안두기
	if (now_p_block != 0) {
		dfs(last_state, last_count, p + 1, (now_state << 1));
	}
}

void make_dfs(ll now_state, ll p, const ll max_p) {
	if (p > max_p)return;

	if (p == max_p) {
		arr[now_state]++;
		rem[1][now_state]++;
		//arr[now_state] %= MOD;
		return;
	}

	make_dfs(((now_state << 2) + 3), p + 2, max_p);
	make_dfs((now_state << 1), p + 1, max_p);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	n = 4;
	m = 35;

	make_dfs(0, 0, n);
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dfs(j, arr[j], 0, 0);
		}

		for (int j = 0; j < (1 << n); j++) {
			//cout << j << ":" << brr[j] << "\n";
			rem[i][j] = brr[j];
			arr[j] = brr[j];
			brr[j] = 0;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int w;
		cin >> w;
		cout << rem[w][(1 << n) - 1] << "\n";
	}
}