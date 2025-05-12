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
 
int arr[2][200000];
int brr[200001];
 
bool sosu[200001];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= sqrt(200000); i++) {
		for (int j = i * i; j <= 200000; j += i) {
			sosu[j] = true;
		}
	}
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
 
	brr[1] = (!sosu[arr[0][1] + arr[1][1]] ? a : b);
	for (int i = 2; i <= n; i++) {
		int h1 = brr[i - 2];
		if (!sosu[arr[0][i - 1] + arr[0][i]])h1 += a;
		else h1 += b;
		if (!sosu[arr[1][i - 1] + arr[1][i]])h1 += a;
		else h1 += b;
 
		int h2 = brr[i - 1];
		if (!sosu[arr[0][i] + arr[1][i]])h2 += a;
		else h2 += b;
 
		brr[i] = max(h1, h2);
	}
 
	cout << brr[n];
}
