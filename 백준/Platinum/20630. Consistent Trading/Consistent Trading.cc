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
unsigned long long MOD = 1000000363;
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

//{이동 위치,{+면 *수, -면 /수}}
vector<ll_ll>line[100001];

bool visit[100001];
ll cost[100001];

ll custom_pow(ll a, ll n) {
	if (n == 0)return 1;
	if (n == 1)return a;
	ll sum = custom_pow(a, n / 2);
	sum = (sum * sum) % MOD;
	if (n % 2 == 1)sum = (sum * a) % MOD;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		line[a].push_back({ b,c });
		line[b].push_back({ a,-c });
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		cost[i] = 1;
		queue<ll_ll>arr;
		arr.push({ i,1ll });
		while (arr.size()) {
			ll now_p = arr.front().fi;
			ll now_cost = arr.front().se;
			arr.pop();
			for (ll_ll h : line[now_p]) {
				ll new_p = h.fi;
				ll new_cost = (now_cost * h.se) % MOD;
				if (h.se < 0) {
					new_cost = (now_cost * custom_pow(-h.se, MOD - 2)) % MOD;
				}
				if (!visit[new_p]) {
					visit[new_p] = true;
					cost[new_p] = new_cost;
					//cout << new_p << ":" << new_cost << "\n";
					arr.push({ new_p,new_cost });
					continue;
				}
				if (cost[new_p] == new_cost)continue;
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}