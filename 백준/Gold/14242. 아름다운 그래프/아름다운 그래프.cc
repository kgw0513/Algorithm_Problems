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

// a 1 b 2 c 2 d
int n;
vector<int>brr;
ll ans = 0;

ll apown(ll a, ll n) {
	if (n == 0)return 1;
	if (n == 1)return a;
	ll h = apown(a, n / 2);
	h *= h;
	h %= MOD2;
	if (n % 2 == 1)h *= a;
	h %= MOD2;
	return h;
}
void setting(int p) {
	if (p >= n-1) {
		ll two_pow = 0;
		for (int i = 2; i < n; i++) {
			if (brr[i-1] == 2)continue;
			for (int j = i - 2; j >= 0; j--) {
				if (brr[j] == 2)break;
				two_pow++;
			}
		}
		ans += apown(2, two_pow);
		ans %= MOD2;
		return;
	}
	brr[p] = 1;
	setting(p + 1);
	brr[p] = 2;
	setting(p + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	brr.resize(n);
	setting(0);
	ll ans2 = 1;
	for (int i = 3; i <= n; i++) {
		ans2 *= i;
		ans2 %= MOD2;
	}
	//cout << "중간 : " << ans<<"*"<<ans2 << "\n";
	cout << (ans * ans2) % MOD2;
}