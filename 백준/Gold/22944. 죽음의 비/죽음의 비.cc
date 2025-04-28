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

intint pos[12];

int xy_dist(intint a, intint b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char w;
	int n, h, d;
	int give_num = 0;
	intint end_pos = { -1,-1 };
	cin >> n >> h >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if (w == 'S') {
				pos[0] = { i,j };
			}
			else if (w == 'E') {
				end_pos = { i,j };
			}
			else if (w == 'U') {
				pos[++give_num] = { i,j };
			}
		}
	}

	pos[give_num + 1] = end_pos;

	vector<int>arr;
	for (int i = 1; i <= give_num + 1; i++) {
		arr.push_back(i);
	}

	int ans = INF;
	do {
		int now_hp = h;
		int bonus_hp = 0;
		intint now_pos = pos[0];
		bool is_failed = false;
		int move_dist = 0;
		for (int i = 0; i < arr.size(); i++) {
			int p = arr[i];

			int dist = xy_dist(now_pos, pos[p]);
			move_dist += dist;

			int damage = dist;
			int h = min(bonus_hp, damage);
			bonus_hp -= h;
			damage -= h;

			now_hp -= damage;
			if (now_hp < 0) {
				is_failed = true;
				break;
			}

			if (p == give_num + 1)break;
			
			bonus_hp = d;
			now_pos = pos[p];
		}

		if (is_failed)continue;

		ans = min(ans, move_dist);
	} while (next_permutation(arr.begin(), arr.end()));

	cout << (ans == INF ? -1 : ans);
}