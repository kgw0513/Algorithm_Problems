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

vector<ll>arr[10001];
vector<ll>helper;
vector<vector<ll>>crr[2];
vector<ll>brr[2];

void setting(int s, const int e, const int brr_in, ll now_sum) {
	if (s >= e) {
		if (now_sum == lINF)return;
		brr[brr_in].push_back(now_sum);
		return;
	}
	for (ll h : crr[brr_in][s]) {
		setting(s + 1, e, brr_in, (now_sum == lINF ? h : now_sum + h));
	}
	setting(s + 1, e, brr_in, now_sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		helper.push_back(w);
	}
	for (int i = 0; i < n; i++) {
		cin >> w;
		arr[w].push_back(helper[i] * (w - 5000));
	}

	int count_number = 0;
	for (int i = 0; i < 10001; i++) {
		if (arr[i].empty())
			continue;
		count_number++;
	}

	int rem_count = 0;
	for (int i = 0; i < 10001; i++) {
		if (arr[i].empty())
			continue;
		int set_number = 0;
		if (rem_count < count_number/2)set_number = 0;
		else set_number = 1;
		rem_count++;
		crr[set_number].push_back(vector<ll>());
		for (ll h : arr[i]) {
			crr[set_number].back().push_back(h);
		}
	}

	setting(0, crr[0].size(), 0, lINF);
	setting(0, crr[1].size(), 1, lINF);

	sort(brr[0].begin(), brr[0].end());
	sort(brr[1].begin(), brr[1].end(), greater<ll>());

	int brr_a = 0, brr_b = 0;
	ll ans = 0;
	while (brr_a < brr[0].size() && brr_b < brr[1].size()) {
		ll h = brr[0][brr_a] + brr[1][brr_b];
		if (h <= 0) {
			if (h == 0) {
				ll brr_a_sum = 1;
				ll brr_b_sum = 1;
				while (brr_a + 1 < brr[0].size() && brr[0][brr_a] == brr[0][brr_a + 1]) {
					brr_a_sum++;
					brr_a++;
				}
				while (brr_b + 1 < brr[1].size() && brr[1][brr_b] == brr[1][brr_b + 1]) {
					brr_b_sum++;
					brr_b++;
				}
				//cout << "+" << brr_a_sum << "*" << brr_b_sum << "\n";
				ans += brr_a_sum * brr_b_sum;
			}
			brr_a++;
			continue;
		}
		brr_b++;
	}
	for (int i = 0; i < brr[0].size(); i++) {
		if (brr[0][i] == 0)ans++;
	}
	for (int i = 0; i < brr[1].size(); i++) {
		if (brr[1][i] == 0)ans++;
	}
	cout << ans;
}