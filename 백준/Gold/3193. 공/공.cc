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

intint dxdy[4] = { {1,0},{0,1},{-1,0},{0,-1} };

char state[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	intint p = { -1,-1 };
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (i == 0 || j == 0 || i == n + 1 || j == n + 1) {
				state[i][j] = 'X';
				continue;
			}
			cin >> state[i][j];
			if (state[i][j] == 'L') {
				state[i][j] = '.';
				p = { i,j };
			}
		}
	}

	int arrow = 0;
	while (k--) {
		char w;
		cin >> w;
		if (w == 'L')arrow--;
		else arrow++;

		arrow = (arrow + 4) % 4;
		while (state[p.fi + dxdy[arrow].fi][p.se + dxdy[arrow].se] == '.') {
			p = { p.fi + dxdy[arrow].fi ,p.se + dxdy[arrow].se };
		}
	}

	state[p.fi][p.se] = 'L';
	if (arrow == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << state[i][j];
			}
			cout << "\n";
		}
	}
	else if (arrow == 1) {
		for (int j = 1; j <= n; j++) {
			for (int i = n; i >= 1; i--) {
				cout << state[i][j];
			}
			cout << "\n";
		}
	}
	else if (arrow == 2) {
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				cout << state[i][j];
			}
			cout << "\n";
		}
	}
	else if (arrow == 3) {
		for (int j = n; j >= 1; j--) {
			for (int i = 1; i <= n; i++) {
				cout << state[i][j];
			}
			cout << "\n";
		}
	}
}