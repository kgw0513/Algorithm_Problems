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
#define f first
#define s second
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

ll len_num(ll n,ll r) {
	ll sum = 0;
	ll ten_pow = 10;
	ll pow_count = 1;
	while (n >= ten_pow) {
		ll s = (ten_pow / 10);
		ll e = ten_pow - 1;
		sum += (e / r - s / r)*pow_count;
		if (r == 1 || (r == 5 && s >= 10))sum += pow_count;

		pow_count++;
		ten_pow *= 10;
	}
	//cout << sum << "개.\n";
	ll s = ten_pow / 10;
	ll e = n; 
	sum += (e / r - s / r) * pow_count;
	if (r == 1 ||(r== 5&&s>=10))sum += pow_count;
	return sum;
}
ll cal(ll n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	if (n == 3)return 6;
	if (n == 4)return 7;
	if (n == 5)return 11;
	ll sum = len_num(n, 1);
	//cout << sum << "개.\n";
	//cout << len_num(n, 3) << "겹침.1\n";
	//cout << len_num(n, 5) << "겹침.2\n";
	sum -= len_num(n, 3);
	sum -= len_num(n, 5);
	sum += len_num(n, 15);

	sum += (n / 3) * 4 + (n / 5) * 4;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	//cout << cal(22) << "개,\n";
	//return 0;
	cin >> n;
	//return 0;
	ll s = 0, e = 100000000000000000;
	ll ans = 0;
	ll ans_value = 0;
	n--;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll h = cal(mid);
		if (h > n) {
			e = mid - 1;
		}
		else {
			ans = mid;
			ans_value = h;
			s = mid + 1;
		}
	}
	n -= ans_value;
	ans++;
	//cout << ans << "위치.\n";
	string s_ans = "";
	for (ll check = ans; s_ans.size() < 40; check++) {
		if (check % 3 == 0 && check % 5 == 0) {
			s_ans += "FizzBuzz";
		}
		else if (check % 3 == 0) {
			s_ans += "Fizz";
		}
		else if (check % 5 == 0) {
			s_ans += "Buzz";
		}
		else s_ans += to_string(check);
	}
	
	for (int i = 0; i < 20; i++) {
		int p = n + i;
		cout << s_ans[p];
	}
}