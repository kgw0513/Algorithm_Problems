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

int visit[100001];

ll ccw(ll_ll a, ll_ll b, ll_ll c) {
	return a.fi * b.se + b.fi * c.se + c.fi * a.se - (a.se * b.fi + b.se * c.fi + c.se * a.fi);
}
bool cmp(int2_int& a, int2_int& b) {
	ll h = ccw({ 0,0 }, a.fi, b.fi);
	if (h == 0) {
		return a.se > b.se;
	}
	return h > 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int2_int>arr;
	int n,m, a, b;
	cin >> n;
	for(int timer=1;timer<=n;timer++){
		cin >> a >> b;
		arr.push_back({ {a,b},timer });
		cin >> a >> b;
		arr.push_back({ {a,b},timer });
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr.push_back({ { a, b },-1 });
	}

	sort(arr.begin(), arr.end(), cmp);

	int ans = n;

	int now_collect = 0;
	int remove_collect = 0;
	intint last_p = { -1,-1 };
	int timer = 1;
	for (int2_int h : arr) {
		if (ccw({ 0,0 }, last_p, h.fi) != 0) {
			now_collect -= remove_collect;
			remove_collect = 0;
		}
		if (h.se == -1) {
			timer++;
			ans -= now_collect;
			now_collect = 0;
			remove_collect = 0;
		}
		else if (visit[h.se] == 0) {
			now_collect++;
			visit[h.se] = timer;
		}
		else if (visit[h.se] > 0) {
			if (visit[h.se] != timer)continue;
			remove_collect++;
		}
		last_p = h.fi;
	}
	cout << ans;
}