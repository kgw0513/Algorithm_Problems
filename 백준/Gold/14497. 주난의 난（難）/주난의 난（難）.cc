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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
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

char state[302][302];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	intint p1, p2;
	cin >> n >> m >> p1.fi >> p1.se >> p2.fi >> p2.se;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> state[i][j];
		}
	}

	deque<intint>arr;
	arr.push_back(p2);

	for (int timer = 1; arr.size(); timer++) {
		int size = arr.size();
		while (size--) {
			intint now_p = arr.front();
			arr.pop_front();
			for (int i = 0; i < 4; i++) {
				intint new_p = { now_p.fi + dxdy[i].fi,now_p.se + dxdy[i].se };
				char h = state[new_p.fi][new_p.se];
				if (h == 0 ||h == '#')continue;
				if (h == '*') {
					cout << timer;
					return 0;
				}
				state[new_p.fi][new_p.se] = '#';
				if (h == '0') {
					arr.push_front(new_p);
					size++;
					continue;
				}
				arr.push_back(new_p);
			}
		}
	}

	return -1;
}