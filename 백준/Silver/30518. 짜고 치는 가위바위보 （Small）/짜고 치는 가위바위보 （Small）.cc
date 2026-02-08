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
#include <complex>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

//a의 기준으로 판별
//0 : 비김, 1 : 짐, 2 : 이김
//[2][0][X]이 존재해서는 안된다.
//마지막 3개 숫자 의미 : R = 0, P =1, S =2
ll dp[4][3][3];

int chartoint(char a) {
	if (a == 'R')return 0;
	if (a == 'P')return 1;
	if (a == 'S')return 2;
	exit(-1);
}

char inttochar(int a) {
	if (a == 0)return 'R';
	if (a == 1)return 'P';
	if (a == 2)return 'S';
	exit(-1);
}
//a의 기준으로 판별
int cal(char a, char b) {
	if (a == b)return 0;

	if (a == 'R' && b == 'P')return 1;
	if (a == 'P' && b == 'S')return 1;
	if (a == 'S' && b == 'R')return 1;

	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.size(); i++) {
		ll dp2[3][3][3] = {};
		for (int h1 = 0; h1 < 3; h1++) {
			for (int h2 = 0; h2 < 3; h2++) {
				for (int h3 = 0; h3 < 3; h3++) {
					dp2[h1][h2][h3] = dp[h1][h2][h3];
				}
			}
		}

		//이게 첫번째로 가위바위보 할때
		{
			int h1 = cal(a[0], b[i]);
			dp2[0][h1][chartoint(b[i])] += 1;
			dp2[0][h1][chartoint(b[i])] %= MOD1;
		}

		for (int h1 = 0; h1 < 3; h1++) { //i-2번째 판 상태
			for (int h2 = 0; h2 < 3; h2++) { //i-1번째 판 상태
				for (int h3 = 0; h3 < 3; h3++) { //i-1번째에서 낸 정보

					//i번째 판 상태를 적용할려 할때

					//이미 하고 있던 가위바위보가 있을때
					int h4 = cal(inttochar(h3), b[i]);
					dp2[h2][h4][chartoint(b[i])] += dp[h1][h2][h3];
					dp2[h2][h4][chartoint(b[i])] %= MOD1;
				}
			}
		}

		for (int h1 = 0; h1 < 3; h1++) {
			for (int h2 = 0; h2 < 3; h2++) {
				if (h1 == 2 && h2 == 0)continue;
				for (int h3 = 0; h3 < 3; h3++) {
					dp[h1][h2][h3] = dp2[h1][h2][h3];
				}
			}
		}
	}

	ll ans = 0;
	for (int h1 = 0; h1 < 3; h1++) {
		for (int h2 = 0; h2 < 3; h2++) {
			for (int h3 = 0; h3 < 3; h3++) {
				ans += dp[h1][h2][h3];
				ans %= MOD1;
			}
		}
	}

	cout << ans;
}