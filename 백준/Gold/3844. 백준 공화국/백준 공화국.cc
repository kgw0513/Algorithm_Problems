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

bool check[10000001] = { 1,1, };
vector<ll>sosu;
int ans[10000001] = { 0 ,1};
bool odd_sosu[10000001]= { 0,0,0,0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= sqrt(10000000); i++) {
		if (check[i])continue;
		for (int j = i * i; j < 10000001; j += i) {
			check[j] = true;
		}
	}
	for (int i = 2; i <= 10000000; i++) {
		if (check[i])continue;
		sosu.push_back(i);
	}
	
	ll now_ans = 1;
	for (int i = 2; i < 10000001; i++) {
		//if (i % 1000000==0)cout << i << ".\n";
		ll h = i;
		int p = 0;
		while (check[h]) {
			while (h % sosu[p] == 0 && check[h]) {
				h /= sosu[p];
				odd_sosu[sosu[p]] = !odd_sosu[sosu[p]];
				if (odd_sosu[sosu[p]] == false) {
					now_ans *= (sosu[p] * sosu[p])%MOD2;
					now_ans %= MOD2;
					//cout << sosu[p] << "들.\n";
				}
			}
			p++;
		}

		odd_sosu[h] = !odd_sosu[h];
		if (odd_sosu[h] == false) {
			now_ans *= (h * h)%MOD2;
			now_ans %= MOD2;
		}
		ans[i] = now_ans;
	}

	while (1) {
		ll w;
		cin >> w;
		if (w == 0)break;
		cout << ans[w] << "\n";
	}
}