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
const int nINF = 1007483647;
unsigned long long MOD = 1000000007;
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

int has[2000005];
queue<int>arr;
vector<int>line[2000005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, r, w;
	cin >> n >> k >> r;
	while (k--) {
		cin >> w;
		has[w] = -1;
		arr.push(w);
	}
	for (int i = 1; i <= r; i++) {
		int t;
		cin >> t;
		int node = n + i;
		has[node] = t;
		while (t--) {
			cin >> w;
			line[w].push_back(node);
		}
		cin >> t;
		while (t--) {
			cin >> w;
			line[node].push_back(w);
		}
	}
	int ans = 0;
	while (arr.size()) {
		int h = arr.front();
		arr.pop();
		for (int visit_h : line[h]) {
			has[visit_h]--;
			if (has[visit_h] > 0)continue;
			has[visit_h] = -1;
			for (int new_h : line[visit_h]) {
				if (has[new_h] == -1)continue;
				has[new_h] = -1;
				arr.push(new_h);
				ans++;
			}
		}
	}
	cout << ans;
}