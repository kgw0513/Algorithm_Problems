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

int arr[1400][1400];
int ar, ac, tr, tc;
intint first_land;

int check[101][101];

char world_map[1400][1400];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

void set_arr() {
	for (int i = 150; i < min(ar+250,1400); i++) {
		for (int j = 150; j < min(ac+250,1400); j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			if (150 <= i && i < ar + 150 && 150 <= j && j < ac + 150)arr[i][j] += (world_map[i][j] == 'X' ? 1 : 0);
		}
	}
}

bool find_arr(intint start_p, intint end_p) {
	//cout << start_p.fi << "," << start_p.se << "~" << end_p.fi << "," << end_p.se << "\n";
	return (arr[end_p.fi][end_p.se] - arr[end_p.fi][start_p.se - 1] - arr[start_p.fi - 1][end_p.se] + arr[start_p.fi - 1][start_p.se - 1]) > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> ar >> ac >> tr >> tc) {

		first_land = { -1,-1 };

		for (int i = 150; i < ar + 150; i++) {
			for (int j = 150; j < ac + 150; j++) {
				cin >> world_map[i][j];
				if (world_map[i][j] == 'X' && first_land.fi == -1) {
					first_land = { i,j };
				}
			}
		}

		if (first_land.fi == -1) {
			cout << "0\n";
			continue;
		}

		set_arr();

		int ans = INF;

		for (int i = 1; i <= tr; i++) {
			for (int j = 1; j <= tc; j++) {
				int sum = 0;
				for (int x = ((150 - i) / tr) * tr + i; x < ar+150; x+=tr) {
					for (int y = ((150 - j) / tc) * tc + j; y < ac+150; y+=tc) {
						if (find_arr({ x,y }, { x + tr - 1,y + tc - 1 }))
							sum++;
					}
				}
				ans = min(ans, sum);
			}
		}

		cout << ans << "\n";
	}
}