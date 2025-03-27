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

char state[102][102];
int n, m;

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
bool is_one() {
	bool check[102][102] = {};
	bool check_one = false;
	queue<intint>arr;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (state[i][j] == '0' || state[i][j]=='X' || check[i][j])continue;
			if (check_one)return false;
			check[i][j] = true;
			check_one = true;

			arr.push({ i,j });
			while (arr.size())
			{
				intint now_h = arr.front();
				arr.pop();
				for (intint new_h : dxdy) 
				{
					new_h = { new_h.fi + now_h.fi,new_h.se + now_h.se };
					if (state[new_h.fi][new_h.se] == '0' || state[new_h.fi][new_h.se] == 'X' || check[new_h.fi][new_h.se])continue;
					check[new_h.fi][new_h.se] = true;
					arr.push(new_h);
				}
			}
		}
	}
	return true;
}

void spread() {
	char new_state[102][102] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			new_state[i][j] = state[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (state[i][j] == '0' || state[i][j] == 'X')continue;

			int spread_band = state[i][j] - '0';

			for (int check_i = max(1, i - spread_band); check_i <= min(n, i + spread_band); check_i++)
			{
				for (int check_j = max(1, j - spread_band); check_j <= min(m, j + spread_band); check_j++)
				{
					new_state[check_i][check_j] = max(new_state[check_i][check_j], state[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			state[i][j] = new_state[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			state[i][j] = 'X';
		}
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> state[i][j];
		}
	}

	for (int timer = 0;; timer++) {
		assert(timer <= 1000);
		if (is_one()) {
			cout << timer;
			return 0;
		}
		spread();
	}
}