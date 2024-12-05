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

set<ll_ll>arr;

const static ll mul = 10003;
ll2_ll2 trans_num(string w) {
	ll_ll ans = {};
	for (int i = 0; i < w.size(); i++) {
		ans.fi = ((ans.fi * mul) + w[i]) % MOD1;
		ans.se = ((ans.se * mul) + w[i]) % MOD2;
	}

	ll_ll remove_num = { 1,1 };
	for (int i = 0; i < w.size(); i++) {
		remove_num.fi = (remove_num.fi * mul) % MOD1;
		remove_num.se = (remove_num.se * mul) % MOD2;
	}
	return { ans,remove_num };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string w, a, b;
	cin >> w >> a >> b;

	ll2_ll2 h = trans_num(b);
	ll_ll b_check = h.fi;
	ll_ll b_remove = h.se;

	
	for (int i = 0; i <= int(w.size())-int(a.size()); i++) {
		string h = w.substr(i, a.size());
		if (h != a)continue;
		ll_ll check_num = {};
		ll_ll sum_num = {};
		for (int j = i; j < w.size(); j++) {
			int p = j - i;
			check_num = { (check_num.fi * mul + w[j]) % MOD1,(check_num.se * mul + w[j]) % MOD2 };
			sum_num = { (sum_num.fi * mul + w[j]) % MOD1,(sum_num.se * mul + w[j]) % MOD2 };
			if (p >= b.size()) {
				check_num = { (check_num.fi - (b_remove.fi * w[j - b.size()]) % MOD1 + MOD1) % MOD1,
							  (check_num.fi - (b_remove.se * w[j - b.size()]) % MOD2 + MOD2) % MOD2, };
			}

			/*cout << check_num.fi << "vs" << b_check.fi << "and \n";
			cout << check_num.se << "vs" << b_check.se << "\n";
			cout << p + 1 << ">=" << a.size() << "\n";
			cout << p + 1 << ">=" << b.size() << "?\n\n";*/
			if (p + 1 >= a.size() && p + 1 >= b.size()
				&& b_check.fi==check_num.fi) {
				arr.insert(sum_num);/*
				cout << sum_num.fi << "," << sum_num.se << "넣음, 즉. ";
				cout << i << "~" << j << "가능.\n";*/
			}
		}
	}
	cout << arr.size();
}