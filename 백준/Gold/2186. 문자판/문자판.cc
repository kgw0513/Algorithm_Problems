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

int arr[82][102][102];
char state[102][102];
string find_s; 
int n, m, k;

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
void setting(int p) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int pos_move = 1; pos_move <= k; pos_move++) {
				for (int ind = 0; ind < 4; ind++) {
					intint check_p = { i + dxdy[ind].fi * pos_move,j + dxdy[ind].se * pos_move };
					if (check_p.fi<1 || check_p.se<1 || check_p.fi>n || check_p.se>m || state[check_p.fi][check_p.se]!=find_s[p])
						continue;
					arr[p][check_p.fi][check_p.se] += arr[p - 1][i][j];
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> state[i][j];
		}
	}
	cin >> find_s;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (state[i][j] == find_s[0]) {
				arr[0][i][j]++;
			}
		}
	}

	for (int p = 1; p < find_s.size(); p++) {
		setting(p);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum += arr[find_s.size() - 1][i][j];
		}
	}
	cout << sum;
}