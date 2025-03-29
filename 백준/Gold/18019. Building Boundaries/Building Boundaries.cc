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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		vector<ll_ll>arr;
		for (int i = 0; i < 3; i++) {
			cin >> a >> b;
			arr.push_back({ a,b });
		}

		ll ans = lINF;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (i == j || j == k || i == k)continue;

					for (int loop = 0; loop < 8; loop++) {
						ll_ll arr_i = arr[i];
						if ((loop & 1) != 0) {
							swap(arr_i.fi, arr_i.se);
						}
						ll_ll arr_j = arr[j];
						if ((loop & 2) != 0) {
							swap(arr_j.fi, arr_j.se);
						}
						ll_ll arr_k = arr[k];
						if ((loop & 4) != 0) {
							swap(arr_k.fi, arr_k.se);
						}
						ll_ll all_width = { arr_i.fi + arr_j.fi,max(arr_i.se,arr_j.se) };
						ll_ll left_width = { 0,arr_i.se - arr_j.se };
						
						{
							ll_ll h;
							h.fi = all_width.fi + max(0ll, arr_k.fi - all_width.fi);
							h.se = all_width.se + max(0ll, arr_k.se);

							ans = min(ans, h.fi * h.se);

							h.fi = all_width.fi + max(0ll, arr_k.fi);
							h.se = all_width.se + max(0ll, arr_k.se - all_width.se);

							ans = min(ans, h.fi * h.se);
						}

						if (left_width.se > 0) {
							left_width.fi = all_width.fi - arr_i.fi;
						}
						else if (left_width.se < 0) {
							left_width.se *= -1;
							left_width.fi = all_width.fi - arr_j.fi;
						}
						
						//cout << i << "," << j << "," << k << ":" << left_width.fi << "*" << left_width.se << "."<<loop<<"\n";
						all_width.fi += max(0ll, arr_k.fi - left_width.fi);
						all_width.se += max(0ll, arr_k.se - left_width.se);

						ans = min(ans, all_width.fi * all_width.se);
					}
				}
			}
		}
		cout << ans << "\n";
	}
}