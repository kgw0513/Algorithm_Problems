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

double dist(dd a, dd b) {
	return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
int cal(int n) {
	vector<dd>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fi >> arr[i].se;
	}

	int ans = 1;
	for (int i = 0; i < n; i++) {
		//cout << i << "상태.\n";
		vector<pair<double,int>>brr;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			double h = dist(arr[i], arr[j]);
			if (h > 2)continue;
			double now_angle = atan2(arr[j].se - arr[i].se, arr[j].fi - arr[i].fi);
			//cout << h << "거리.\n";
			double max_angle = acos(h/2);
			//cout << now_angle << "+-" << max_angle << "결론 : " << j << "\n";
			brr.push_back({ now_angle - max_angle ,1 });
			brr.push_back({ now_angle + max_angle ,-1 });
		}
		sort(brr.begin(), brr.end());
		int sum = 1;
		for (int i = 0; i < brr.size(); i++) {
			//cout << brr[i].fi<<","<<brr[i].se << "?\n";
			sum += brr[i].se;
			ans = max(ans, sum);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (1) {
		cin >> n;
		if (n == 0)break;
		cout << cal(n) << "\n";
	}
}