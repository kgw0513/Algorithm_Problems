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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
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
		int n;
		string w;
		cin >> n >> w;
		int sum[10] = {};
		int ten_pow[10] = { 1,1,1,1,1,1,1,1,1,1 };
		for (int i = w.size() - 1; i >= 0; i--) {
			for (int j = 2; j < 10; j++) {
				sum[j] += (ten_pow[j] * (w[i] - '0'));
				sum[j] %= j;

				ten_pow[j] *= 10;
				ten_pow[j] %= j;
			}
		}

		vector<pair<string,int>>ans;

		set<string>check;

		for (int i = 0; i < 10; i++)ten_pow[i] = 1;
		
		for (int i = w.size() - 1; i >= 0 && ans.size() < n; i--) {
			for (int j = 2; j < 10 && ans.size() < n; j++) {
				for (char k = '0'; k <= '9' && ans.size() < n; k++) {
					if ((i == 0 && k == '0') || w[i] == k)continue;
					int h = sum[j];
					h -= (ten_pow[j] * (w[i] - '0'));
					h += (ten_pow[j] * (k-'0'));
					h %= j;
					h += j;
					h %= j;
					assert(h >= 0);
					if (h == 0) {
						string new_w = w;
						new_w[i] = k;
						if (check.find(new_w) != check.end())continue;
						if (new_w == "2")continue;
						check.insert(new_w);
						ans.push_back({ new_w,j });
					}
				}

				ten_pow[j] *= 10;
				ten_pow[j] %= j;
			}
		}

		assert(ans.size() == n);
		while (!ans.empty()) {
			cout << ans.back().fi << " " << ans.back().se << "\n";
			ans.pop_back();
		}
	}
}