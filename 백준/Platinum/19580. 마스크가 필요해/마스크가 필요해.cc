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

struct cmp1 {
	bool operator()(ll_ll& a, ll_ll& b) {
		if (a.fi == b.fi && a.se* b.se < 0) {
			return a.se < b.se;
		}
		return a.fi > b.fi;
	}
};

struct cmp2 {
	bool operator()(ll_ll& a, ll_ll& b) {
		return a.se > b.se;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	priority_queue<ll_ll, vector<ll_ll>, cmp1>arr;
	priority_queue<ll_ll, vector<ll_ll>, cmp2>brr;
	for (int num = 1; num <= n; num++) {
		ll a, b;
		cin >> a >> b;
		arr.push({ a,b });
	}

	while (m--) {
		ll a, b;
		cin >> a >> b;
		arr.push({ a,-b });
	}

	int ans = 0;
	while (!arr.empty()) {
		ll a = arr.top().fi;
		ll b = arr.top().se;
		arr.pop();
		if (b < 0) { //상점일 경우
			//이때 b는 판매 갯수
			// a는 판매 가격이다.
			b = abs(b);
			while (b > 0 && !brr.empty()) {
				ll citizen_sell_max = brr.top().se;
				brr.pop();
				if (citizen_sell_max < a) {
					continue;
				}
				ans++;
				b--;
			}
		}
		else { //시민일 경우
			brr.push({ a,b });
		}
	}
	cout << ans;
}