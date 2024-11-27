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

ll Close_Middle[100001];

ll Union[100001];
ll find(ll p) {
	if (Union[p] == p)return p;
	return Union[p] = find(Union[p]);
}

vector<ll_ll>arr;
map<ll_ll, ll>brr;

ll_ll dxdy[8] = { {-1,-1},{-1,0} ,{-1,1},{0,-1},{0,1},
	{1,-1},{1,0},{1,1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll a, b;
		cin >> a >> b;

		Union[i] = i;
		Close_Middle[i] = abs(a) + abs(b);

		arr.push_back({ a,b });
		brr[{a, b}] = i;
		for (int j = 0; j < 8; j++) {
			intint p = { a + dxdy[j].fi,b + dxdy[j].se };
			if (brr.find(p) == brr.end())continue;
			ll h1 = find(i);
			ll h2 = find(brr[p]);
			if (h1 == h2)continue;
			if (h1 > h2)swap(h1, h2);
			Union[h1] = h2;
			Close_Middle[h2] = min(Close_Middle[h2], Close_Middle[h1]);
		}
	}

	ll max_len = 0;
	ll sum_len = 0;
	for (int i = 1; i <= n; i++) {
		ll h = find(i);
		if (Close_Middle[h] == -1)continue;
		sum_len += Close_Middle[h];
		max_len = max(max_len, Close_Middle[h]);
		Close_Middle[h] = -1;
	}
	cout << sum_len * 2 - max_len;
}