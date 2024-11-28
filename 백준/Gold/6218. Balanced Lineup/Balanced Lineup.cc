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

struct seg {
	int state_num;
	seg* left_seg = nullptr;
	seg* right_seg = nullptr;

	seg(int s,int e,const bool min_seg) {
		if (min_seg)state_num = INF;
		else state_num = -1;

		if (s == e)return;

		left_seg = new seg(s, (s + e) / 2, min_seg);
		right_seg = new seg((s + e) / 2 + 1, e, min_seg);
	}

	void insert_num(int seg_s, int seg_e, const int p, const int num,const bool min_seg) {
		if (p < seg_s || seg_e < p)return;

		if (min_seg) {
			state_num = min(state_num, num);
		}
		else {
			state_num = max(state_num, num);
		}

		if (seg_s == seg_e)return;

		left_seg->insert_num(seg_s, (seg_s + seg_e) / 2, p, num, min_seg);
		right_seg->insert_num((seg_s + seg_e) / 2 + 1, seg_e, p, num, min_seg);
	}

	int get_num(int seg_s, int seg_e, const int find_s,const int find_e,const bool min_seg) {
		if (find_e < seg_s || seg_e < find_s) {
			if (min_seg)return INF;
			return -1;
		}

		if (find_s <= seg_s && seg_e <= find_e)return state_num;

		int state_find = -1;
		if (min_seg)state_find = INF;
		int h = left_seg->get_num(seg_s, (seg_s + seg_e) / 2, find_s, find_e,min_seg);
		
		if (min_seg) {
			state_find = min(state_find, h);
		}
		else {
			state_find = max(state_find, h);
		}
		h = right_seg->get_num((seg_s + seg_e) / 2 + 1, seg_e, find_s, find_e,min_seg);
		if (min_seg) {
			state_find = min(state_find, h);
		}
		else {
			state_find = max(state_find, h);
		}
		return state_find;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	seg* min_seg = new seg(1, n, true);
	seg* max_seg = new seg(1, n, false);
	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		min_seg->insert_num(1, n, i, w, true);
		max_seg->insert_num(1, n, i, w, false);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		int h1 = min_seg->get_num(1, n, a, b,true);
		int h2 = max_seg->get_num(1, n, a, b,false);
		cout << h2 - h1 << "\n";
	}
}