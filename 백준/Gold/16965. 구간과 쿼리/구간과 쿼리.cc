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

vector<int>lines[102];

bool bAgoB(intint a, intint b) {
	if (b.fi < a.fi && a.fi < b.se)return true;
	if (b.fi < a.se && a.se < b.se)return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t, a, b;
	cin >> n;
	vector<intint>arr = { {-1,-1} };
	while (n--) {
		cin >> t >> a >> b;
		if (t == 1) {
			for (int i = 1; i < arr.size(); i++) {
				if (bAgoB({ a,b }, arr[i])) {
					lines[arr.size()].push_back(i);
				}
				if (bAgoB(arr[i], { a,b })) {
					lines[i].push_back(arr.size());
				}
			}
			arr.push_back({ a,b });
		}
		else {
			queue<int>brr;
			brr.push(a);
			bool visit[102] = {};
			visit[a] = true;
			while (!brr.empty()) {
				int p = brr.front();
				brr.pop();
				for (int np : lines[p]) {
					if (visit[np])continue;
					visit[np] = true;
					brr.push(np);
				}
			}
			cout << int(visit[b]) << "\n";
		}
	}
}