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

int check[101][101][101][101];
int all_check[101][101][101][101];
vector<int2_int2> all_play(intint upper, intint lower, int now_card,int now_time) {
	vector<int2_int2>ans;
	if (upper.fi < now_card || now_card + 10 == upper.fi) {
		intint h1 = upper;
		intint h2 = lower;
		h1.fi = now_card;

		if (h1.fi > h1.se)swap(h1.fi, h1.se);
		if (h2.fi > h2.se)swap(h2.fi, h2.se);
		if (check[h1.fi][h1.se][h2.fi][h2.se] != now_time) {
			check[h1.fi][h1.se][h2.fi][h2.se] = now_time;
			ans.push_back({ h1,h2 });
		}
	}
	if (upper.se < now_card || now_card + 10 == upper.se) {
		intint h1 = upper;
		intint h2 = lower;
		h1.se = now_card;

		if (h1.fi > h1.se)swap(h1.fi, h1.se);
		if (h2.fi > h2.se)swap(h2.fi, h2.se);
		if (check[h1.fi][h1.se][h2.fi][h2.se] != now_time) {
			check[h1.fi][h1.se][h2.fi][h2.se] = now_time;
			ans.push_back({ h1,h2 });
		}
	}
	if (lower.fi > now_card || now_card - 10 == lower.fi) {
		intint h1 = upper;
		intint h2 = lower;
		h2.fi = now_card;

		if (h1.fi > h1.se)swap(h1.fi, h1.se);
		if (h2.fi > h2.se)swap(h2.fi, h2.se);
		if (check[h1.fi][h1.se][h2.fi][h2.se] != now_time) {
			check[h1.fi][h1.se][h2.fi][h2.se] = now_time;
			ans.push_back({ h1,h2 });
		}
	}
	if (lower.se > now_card || now_card - 10 == lower.se) {
		intint h1 = upper;
		intint h2 = lower;
		h2.se = now_card;

		if (h1.fi > h1.se)swap(h1.fi, h1.se);
		if (h2.fi > h2.se)swap(h2.fi, h2.se);
		if (check[h1.fi][h1.se][h2.fi][h2.se] != now_time) {
			check[h1.fi][h1.se][h2.fi][h2.se] = now_time;
			ans.push_back({ h1,h2 });
		}
	}

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int timer = 0;
	int all_timer = 0;
	queue<int2_int2>arr;
	arr.push({ {0,0},{101,101} });
	for (int i = 0; i < n / 2; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		++all_timer;
		int size = arr.size();
		while (size--) {
			intint upper = arr.front().fi;
			intint lower = arr.front().se;
			arr.pop();
			vector<int2_int2> h1 = all_play(upper, lower, a,++timer);
			for (int2_int2 h : h1) {
				vector<int2_int2>h2 = all_play(h.fi, h.se, b, ++timer);
				for (int2_int2 h3 : h2) {
					if (all_check[h3.fi.fi][h3.fi.se][h3.se.fi][h3.se.se] != all_timer) {
						all_check[h3.fi.fi][h3.fi.se][h3.se.fi][h3.se.se] = all_timer;
						arr.push(h3);
					}
				}
			}

			h1 = all_play(upper, lower, b, ++timer);
			for (int2_int2 h : h1) {
				vector<int2_int2>h2 = all_play(h.fi, h.se, a, ++timer);
				for (int2_int2 h3 : h2) {
					if (all_check[h3.fi.fi][h3.fi.se][h3.se.fi][h3.se.se] != all_timer) {
						all_check[h3.fi.fi][h3.fi.se][h3.se.fi][h3.se.se] = all_timer;
						arr.push(h3);
					}
				}
			}
		}
		if (arr.empty()) {
			cout << "LOSE";
			return 0;
		}
	}
	if (arr.empty()) {
		cout << "LOSE";
		return 0;
	}
	cout << "WIN";
}