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

ll gcd(ll a, ll b) {
	while (a % b != 0) {
		ll c = a % b;
		a = b;
		b = c;
	}
	return b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, p, w, ans1 = 0, ans2 = 0;
	cin >> n >> p;
	vector<ll>arr(n);
	vector<ll>brr(n);
	const ll now_ten = pow(10, p + 2);
	for (int i = 0; i < n; i++) {
		cin >> w;
		arr[i] = w;
		ll h = now_ten / gcd(w, now_ten);
		if (i == 0) {
			ans1 = h;
		}
		else {
			ll h2 = gcd(h, ans1);
			ans1 = ans1 / h2 * h;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> w;
		brr[i] = w;
		ll h = now_ten / gcd(w, now_ten);
		if (i == 0) {
			ans2 = h;
		}
		else {
			ll h2 = gcd(h, ans2);
			ans2 = ans2 / h2 * h;
		}
	}
	
	vector<ll>arr_people(n);
	for (int i = 0; i < n; i++) {
		arr_people[i] = ans1 * arr[i] / now_ten;
		//cout << arr_people[i] << ",";
	}
	//cout << "\n";

	ll s = 1, e = 9000000000000000000/ans2;
	ll mul_ans2 = -1;
	while (s <= e) {
		//cout << s << "~" << e << "상태.\n";
		ll mid = (s + e) / 2;
		bool is_can = true;
		ll now_check = mid * ans2;
		for (int i = 0; i < n; i++) {
			double h = double(brr[i]) * now_check / now_ten;
			//cout << h << "vs" << arr_people[i] << "\n";
			if (h < arr_people[i]) {
				is_can = false;
				break;
			}
		}
		if (is_can) {
			mul_ans2 = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	assert(mul_ans2 != -1);
	cout << ans1 << " " << ans2 * mul_ans2;
}