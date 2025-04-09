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

int dp[402][402][402];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 402; i++) {
		for (int j = 0; j < 402; j++) {
			for (int k = 0; k < 402; k++) {
				dp[i][j][k] = -nINF;
			}
		}
	}
	dp[0][0][0]=0;
	int n, w;
	cin >> n;
	vector<int>arr;
	vector<int>brr;
	for (int i = 0; i < n; i++) {
		cin >> w;
		if (w == 0)continue;
		arr.push_back(w);
	}
	for (int i = 0; i < n; i++) {
		cin >> w;
		if (w == 0)continue;
		brr.push_back(w);
	}

	if(arr.empty()||brr.empty()){
		cout<<0;
		return 0;
	}
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= arr.size(); j++) {
			for (int k = 0; k <= brr.size(); k++) {
				if(j!=arr.size() && k!=brr.size())dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + arr[j] * brr[k]);
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
				dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);
				dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
				//cout<<i<<","<<j<<","<<k<<":"<<dp[i][j][k]<<"\n";
				
			}
		}
	}

	cout << dp[n][arr.size()][brr.size()];
}