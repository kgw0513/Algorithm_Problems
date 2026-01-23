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

int n;
//[중심x][중심y][가로로 있나?=0]
bool visit[54][54][2];
intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

char state[54][54];

bool can_go(int i,int j, int rotate) {
	if (i<1 || i>n || j<1 || j>n)return false;
	if (rotate == 1) {
		if (state[i - 1][j] == '1' || state[i][j] == '1' || state[i + 1][j] == '1')return false;
	}
	else {
		if (state[i][j - 1] == '1' || state[i][j] == '1' || state[i][j + 1] == '1')return false;
	}
	return true;
}

bool can_rotate(int i, int j, int rotate) {
	if (i<1 || i>n || j<1 || j>n)return false;
	if (!can_go(i, j, rotate))return false;
	if (rotate == 1) {
		for (int r_i = i - 1; r_i <= i + 1; r_i++) {
			for (int r_j = j - 1; r_j <= j + 1; r_j++) {
				if (r_j == j)continue;
				if (state[r_i][r_j] == '1')return false;
			}
		}
	}
	else {
		for (int r_i = i - 1; r_i <= i + 1; r_i++) {
			for (int r_j = j - 1; r_j <= j + 1; r_j++) {
				if (r_i == i)continue;
				if (state[r_i][r_j] == '1')return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 54; i++) {
		for (int j = 0; j < 54; j++) {
			state[i][j] = '1';
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> state[i][j];
		}
	}

	int2_int goal = { {-1,-1},-1 };
	queue<int2_int>arr;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (state[i - 1][j] == 'B'&& state[i][j] == 'B'&& state[i + 1][j] == 'B') {
				arr.push({ {i,j},1 });
				visit[i][j][1] = true;
			}
			if (state[i][j - 1] == 'B' && state[i][j] == 'B' && state[i][j + 1] == 'B') {
				arr.push({ {i,j},0 });
				visit[i][j][0] = true;
			}

			if (state[i - 1][j] == 'E' && state[i][j] == 'E' && state[i + 1][j] == 'E') {
				goal = { {i,j},1 };
			}
			if (state[i][j - 1] == 'E' && state[i][j] == 'E' && state[i][j + 1] == 'E') {
				goal = { {i,j},0};
			}
		}
	}

	for (int timer = 0; !arr.empty(); timer++) {
		int size = arr.size();
		while (size--) {
			intint p = arr.front().fi;
			int r = arr.front().se;
			arr.pop();
			//cout << timer << ":" << p.fi << "," << p.se << "/" << r << "\n";
			if (p == goal.fi && r == goal.se) {
				cout << timer;
				return 0;
			}

			//이동
			for (intint xy : dxdy) {
				intint new_p = { p.fi + xy.fi,p.se + xy.se };
				int nr = r;
				if (visit[new_p.fi][new_p.se][nr])continue;
				if (!can_go(new_p.fi, new_p.se, nr))continue;
				visit[new_p.fi][new_p.se][nr] = true;
				arr.push({ new_p,nr });
			}

			//회전
			intint new_p = p;
			int nr = (r == 1 ? 0 : 1);
			if (visit[new_p.fi][new_p.se][nr])continue;
			if (!can_rotate(new_p.fi, new_p.se, nr))continue;
			visit[new_p.fi][new_p.se][nr] = true;
			arr.push({ new_p,nr });
		}
	}

	cout << 0;
}