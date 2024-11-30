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

ll dist(ll_ll a, ll_ll b) {
	return ((a.fi - b.fi) * (a.fi - b.fi) +
		(a.se - b.se) * (a.se - b.se));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll_ll>arr(3);
	vector<ll_ll>brr(3);
	ll a, b;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		brr[i] = { a,b };
	}

	vector<int>crr = { 0,1,2 };

	do {
		ll h1u = dist(arr[0], arr[1]);
		ll h1d = dist(brr[crr[0]], brr[crr[1]]);
		
		ll h2u = dist(arr[1], arr[2]);
		ll h2d = dist(brr[crr[1]], brr[crr[2]]);

		ll h3u = dist(arr[2], arr[0]);
		ll h3d = dist(brr[crr[2]], brr[crr[0]]);

		if (h1u*h2d == h2u*h1d && h2u * h3d == h3u * h2d && h3u * h1d == h1u * h3d) {
			cout << sqrt(h1u) / sqrt(h1d);
			return 0;
		}
	} while (next_permutation(crr.begin(), crr.end()));
	cout << -1;
}