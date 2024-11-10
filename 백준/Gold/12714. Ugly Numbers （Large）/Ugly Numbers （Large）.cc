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

ll arr[51][210];
bool visit[51];
void dfs(int p,string &w) {
	if (visit[p])return;
	visit[p] = true;
	string now_s = "";
	for (int i = p; i < w.size(); i++) {
		now_s += w[i];
		if (w.size() != i + 1) {
			//마지막인 경우 제외
			 
			//i까지 붙였다 할때 그 다음 독립적으로 생각
			dfs(i + 1, w);

			//현재까지 이어붙인 값 숫자로 변환
			string new_s = now_s;
			reverse(new_s.begin(), new_s.end());
			ll ten_pow = 1;
			ll h = 0;
			for (int pi = 0; pi < new_s.size(); pi++) {
				h += ((new_s[pi] - '0') * ten_pow % 210);
				ten_pow *= 10;
                ten_pow%=210;
			}

			//현재까지 이어붙인 뒤 뒤에 -를 붙일때
			for (int j = 0; j < 210; j++) {
				arr[p][(h - j + 210) % 210] += arr[i + 1][j];
			}

			//현재까지 이어붙인 뒤 뒤에 +를 붙일때
			for (int j = 0; j < 210; j++) {
				arr[p][(h + j) % 210] += arr[i + 1][j];
			}
		}
		else {
			//마지막까지 붙였을때
			string new_s = now_s;
			reverse(new_s.begin(), new_s.end());
			ll ten_pow = 1;
			ll h = 0;
			for (int pi = 0; pi < new_s.size(); pi++) {
				h += ((new_s[pi] - '0') * ten_pow % 210);
				ten_pow *= 10;
                ten_pow%=210;
			}
			arr[p][h%210]++;
			return;
		}
	}
}

vector<ll> sosu_div = { 2,3,5,7,-6,-10,-14,-15,-21,-35,30,42,70,105,-210 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int test=1;test<=t;test++){
		string w;
		cin >> w;
		for (int i = 0; i < 41; i++) {
			visit[i] = false;
			for (int j = 0; j < 210; j++) {
				arr[i][j] = 0;
			}
		}
		assert(w.size() <= 40);
		dfs(0, w);

		ll ans = 0;
		for (ll div : sosu_div) {
			ll abs_div = abs(div);
			for (int i = 0; i < 210; i+=abs_div) {
				if(div>0)ans += arr[0][i];
				else ans -= arr[0][i];
			}
		}
		cout << "Case #" << test << ": ";
		cout << ans << "\n";
	}
}