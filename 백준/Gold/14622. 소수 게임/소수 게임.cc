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

bool sosu[5000001] = { 1,1, };
set<int>arr;
set<int>brr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= sqrt(5000000); i++) {
		if (sosu[i])continue;
		for (int j = i * i; j <= 5000000; j += i) {
			sosu[j] = true; 
		}
	}

	int n;
	ll a, ans_a = 0, ans_b = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		if (sosu[a]) {
			if (arr.size() < 3) {
				ans_b += 1000;
			}
			else {
				auto p = arr.begin();
				p++;
				p++;
				ans_b += -*p;
			}
		}
		else {
			if (arr.find(-a) != arr.end() || brr.find(-a) != brr.end()) {
				ans_a -= 1000;
			}
			else brr.insert(-a);
		}

		cin >> a;
		if (sosu[a]) {
			if (brr.size() < 3) {
				ans_a += 1000;
			}
			else {
				auto p = brr.begin();
				p++;
				p++;
				ans_a += -*p;
			}
		}
		else {
			if (arr.find(-a) != arr.end() || brr.find(-a) != brr.end()) {
				ans_b -= 1000;
			}
			else arr.insert(-a);
		}

		//cout << n << "번 남음 : " << ans_a << "vs" << ans_b << "\n";
	}

	//cout << ans_a << "vs" << ans_b << "?\n";
	if (ans_a == ans_b)cout << "우열을 가릴 수 없음";
	else cout << (ans_a > ans_b ? "소수의 신 갓대웅" : "소수 마스터 갓규성");
}
