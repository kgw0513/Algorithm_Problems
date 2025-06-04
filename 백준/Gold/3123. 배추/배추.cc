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

int x, y, n;

//[x][y]
bool visit[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		visit[a][b] = true;
	}
	
	double ans = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (visit[i][j] && visit[i + 1][j + 1]) {
				//cout << i << "," << j << ".성공1\n";
				ans++;
				continue;
			}
			if (visit[i][j + 1] && visit[i + 1][j]) {
				//cout << i << "," << j << ".성공2\n";
				ans++;
				continue;
			}
			if ((visit[i][j] && visit[i + 1][j]) || (visit[i][j] && visit[i][j + 1]) ||
				(visit[i][j + 1] && visit[i + 1][j + 1]) || (visit[i + 1][j] && visit[i + 1][j + 1])){
				//cout << i << "," << j << ".성공3\n";
				ans += 0.95661148;
				continue;
			}
			if (visit[i][j] || visit[i + 1][j] || visit[i][j + 1] || visit[i + 1][j + 1]) {
				ans += 0.785398163;
				//cout << i << "," << j << ".성공4\n";
				continue;
			}
		}
	}

	cout.precision(10);
	cout << ans;
}