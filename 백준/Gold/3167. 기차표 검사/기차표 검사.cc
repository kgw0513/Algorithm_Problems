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
	int n, k, a, b;
	cin >> n >> k;
	//{티켓 미확인, 티켓 확인}

	intint min_ans = { 0,0 };
	int min_all = 0;
	intint max_ans = { 0,0 };
	int max_all = 0;
	for (int station = 1; station <= n; station++) {
		cin >> a >> b;
		
		{
			int h1 = a;
			int h2 = min(h1, min_ans.se);
			min_ans.se -= h2;
			h1 -= h2;
			min_ans.fi -= h1;

			min_all += h1;
		}

		{
			int h1 = a;
			int h2 = min(h1, max_ans.fi);
			max_ans.fi -= h2;
			h1 -= h2;
			max_ans.se -= h1;
			max_all += h2;
		}

		min_ans.fi += b;
		max_ans.fi += b;
		if (station % k == 1 || k==1) {
			min_ans.se += min_ans.fi;
			min_ans.fi = 0;
			max_ans.se += max_ans.fi;
			max_ans.fi = 0;
		}
	}
	cout << min_all << " " << max_all;
}