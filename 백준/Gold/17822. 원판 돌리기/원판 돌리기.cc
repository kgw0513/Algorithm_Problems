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

deque<deque<int>>arr;

void plate_update() {
	deque<deque<int>>brr = arr;
	bool find_close = false;
	int n = brr.size();
	ll sum = 0;
	ll counting = 0;
	for (int i = 0; i < brr.size(); i++) {
		int m = brr[i].size();
		for (int j = 0; j < brr[i].size(); j++) {
			int now_num = brr[i][j];
			if (now_num == -1)continue; //이미 제거
			sum += now_num;
			counting++;
			if (now_num == brr[i][(j - 1 + m) % m]) {
				arr[i][(j - 1 + m) % m] = -1;
				arr[i][j] = -1;
				find_close = true;
			}
			if (now_num == brr[i][(j + 1) % m]) {
				arr[i][(j + 1) % m] = -1;
				arr[i][j] = -1;
				find_close = true;
			}
			if (i > 0 && now_num == brr[i - 1][j]) {
				arr[i - 1][j] = -1;
				arr[i][j] = -1;
				find_close = true;
			}
			if (i + 1 < n && now_num == brr[i + 1][j]) {
				arr[i + 1][j] = -1;
				arr[i][j] = -1;
				find_close = true;
			}
		}
	}

	if (find_close || counting==0)return;

	for (int i = 0; i < arr.size(); i++) {
		int m = arr[i].size();
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == -1)continue; //이미 제거

			if (arr[i][j] * counting > sum) {
				arr[i][j]--;
			}
			else if (arr[i][j] * counting < sum) {
				arr[i][j]++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	arr.resize(n, deque<int>());
	for (int i = 0; i < n; i++) {
		arr[i].resize(m, 0);
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b == 1) {
			c = m - c;
		}
		for (int i = a - 1; i < n; i += a) {
			int h = c;
			while (h--) {
				arr[i].push_front(arr[i].back());
				arr[i].pop_back();
			}
		}

		plate_update();
	}

	ll sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		int m = arr[i].size();
		for (int j = 0; j < arr[i].size(); j++) {
			int now_num = arr[i][j];
			if (now_num == -1)continue; //이미 제거
			sum += now_num;
		}
	}
	cout << sum;
}