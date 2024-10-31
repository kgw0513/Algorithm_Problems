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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<ll_ll>inputs(3);
	for (int i = 0; i < 3; i++) {
		cin >> inputs[i].fi >> inputs[i].se;
	}
	sort(inputs.begin(), inputs.end());

	ll a1, a2, b1, b2, c1, c2;
	a1 = inputs[0].fi;
	a2 = inputs[0].se;
	b1 = inputs[1].fi;
	b2 = inputs[1].se;
	c1 = inputs[2].fi;
	c2 = inputs[2].se;

	if (a1 == b1 && b1 == c1) {
		cout << "1\n";
		cout << a1 << " " << min({ a2,b2,c2 }) << " "
			<< a1 << " " << max({ a2,b2,c2 }) << "\n";
		return 0;
	}

	if (a2 == b2 && b2 == c2) {
		cout << "1\n";
		cout << min({ a1,b1,c1 }) << " " << a2 << " "
			<< max({ a1,b1,c1 }) << " " << a2 << "\n";
		return 0;
	}

	if (a1 == b1) {
		cout << "2\n";
		cout << a1 << " " << min({ a2,b2,c2 }) << " "
			<< a1 << " " << max({ a2,b2,c2 }) << "\n";
		cout << a1 << " " << c2 << " " << c1 << " " << c2 << "\n";
		return 0;
	}

	if (a1 == c1) {
		cout << "2\n";
		cout << a1 << " " << min({ a2,b2,c2 }) << " "
			<< a1 << " " << max({ a2,b2,c2 }) << "\n";
		cout << a1 << " " << b2 << " " << b1 << " " << b2 << "\n";
		return 0;
	}

	if (b1 == c1) {
		cout << "2\n";
		cout << b1 << " " << min({ a2,b2,c2 }) << " "
			<< b1 << " " << max({ a2,b2,c2 }) << "\n";
		cout << b1 << " " << a2 << " " << a1 << " " << a2 << "\n";
		return 0;
	}

	if (a2 == b2) {
		cout << "2\n";
		cout << min({ a1,b1,c1 }) << " " << a2 << " "
			<< max({ a1,b1,c1 }) << " " << a2 << "\n";
		cout << c1 << " " << a2 << " " << c1 << " " << c2 << "\n";
		return 0;
	}

	if (a2 == c2) {
		cout << "2\n";
		cout << min({ a1,b1,c1 }) << " " << a2 << " "
			<< max({ a1,b1,c1 }) << " " << a2 << "\n";
		cout << b1 << " " << a2 << " " << b1 << " " << b2 << "\n";
		return 0;
	}

	if (b2 == c2) {
		cout << "2\n";
		cout << min({ a1,b1,c1 }) << " " << b2 << " "
			<< max({ a1,b1,c1 }) << " " << b2 << "\n";
		cout << a1 << " " << b2 << " " << a1 << " " << a2 << "\n";
		return 0;
	}

	cout << "3\n";
	cout << b1 << " " << min({ a2,b2,c2 }) << " "
		<< b1 << " " << max({ a2,b2,c2 }) << "\n";
	cout << b1 << " " << a2 << " " << a1 << " " << a2 << "\n";
	cout << b1 << " " << c2 << " " << c1 << " " << c2 << "\n";
}