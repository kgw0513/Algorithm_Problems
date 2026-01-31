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

int virus_count = 0;
intint virus_p[10];
char state[52][52];
char new_state[52][52];
int ans = nINF;
vector<int>select_virus;
int n;

bool bIsFill() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (new_state[i][j] == '0')return false;
		}
	}
	return true;
}

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
void bfs() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			new_state[i][j] = state[i][j];
		}
	}
	queue<intint>arr;
	for (int& p : select_virus) {
		arr.push(virus_p[p]);
		new_state[virus_p[p].fi][virus_p[p].se] = '1';
	}

	int timer = -1;
	while (!arr.empty()) {
		int size = arr.size();
		while (size--) {
			intint p = arr.front();
			arr.pop();
			for (intint xy : dxdy) {
				intint new_p = { p.fi + xy.fi,p.se + xy.se };
				if (new_state[new_p.fi][new_p.se] != '0')continue;
				new_state[new_p.fi][new_p.se] = '1';
				arr.push(new_p);
			}
		}
		timer++;
	}

	if (!bIsFill())return;

	ans = min(ans, timer);
}

void cal(int p, int left) {
	if (left == 0) {
		bfs();
		return;
	}
	for (int i = p; i < virus_count; i++) {
		select_virus.push_back(i);
		cal(i + 1, left - 1);
		select_virus.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> state[i][j];
			if (state[i][j] == '2') {
				state[i][j] = '0';
				virus_p[virus_count++] = { i,j };
			}
		}
	}

	cal(0, m);

	cout << (ans == nINF ? -1 : ans);
}