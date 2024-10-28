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

short arr[100001][201];
int sum[201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, e;
	cin >> n;
	cin >> s >> e;

	for (int i = 0; i <= 200; i++) {
		if (s <= i && i <= e) {
			arr[1][i] = -1;
			sum[i] = 0;
		}
		else {
			arr[1][i] = -1;
			sum[i] = nINF;
		}
	}
	for (int timer = 2; timer <= n; timer++) {
		cin >> s >> e;
		int new_sum[201];
		for (int i = 0; i <= 200; i++) {
			arr[timer][i] = -1;
			new_sum[i] = nINF;
		}
		for (int i = s; i <= e; i++) {
			for (int j = 0; j <= 200; j++) {
				if (new_sum[i] > sum[j] + abs(i - j)) {
					new_sum[i] = sum[j] + abs(i - j);
					arr[timer][i] = j;
				}
			}
		}
		for (int i = 0; i <= 200; i++) {
			sum[i] = new_sum[i];
		}
	}
	int find_i = 0;
	int ans = sum[0];
	int track = arr[n][0];
	for (int i = 0; i <= 200; i++) {
		if (ans > sum[i]) {
			ans = sum[i];
			find_i = i;
			track = arr[n][i];
		}
	}
	cout << ans << "\n";
	stack<int>rem;
	rem.push(find_i);
	while (track != -1) {
		rem.push(track);
		n--;
		track = arr[n][track];
	}
	while (rem.size()) {
		cout << rem.top() << "\n";
		rem.pop();
	}
}