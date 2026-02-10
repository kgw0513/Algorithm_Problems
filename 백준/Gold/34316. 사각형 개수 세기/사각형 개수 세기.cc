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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>inputs(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> inputs[i][j];
		}
	}

	ll ans = 0;

	if (n > m) {
        vector<vector<unordered_map<int, ll>>>arr;
        arr.resize(m,vector<unordered_map<int, ll>>(20));
		for (int i = 0; i < n; i++) {
			for (int j_s = 0; j_s < m; j_s++) {
				for (int j_e = j_s + 1; j_e < m; j_e++) {
					int sum = inputs[i][j_s] + inputs[i][j_e]; 
					arr[j_s][sum][j_e]++;
				}
			}
		}

		for (int j_s = 0; j_s < m; j_s++) {
			for (int j_e = j_s + 1; j_e < m; j_e++) {
				for (int num_s = 2; num_s <= 9; num_s++) {
					int num_e = 20 - num_s;

					ans += arr[j_s][num_s][j_e] * arr[j_s][num_e][j_e];
				}
				if (arr[j_s][10][j_e] >= 2)ans += arr[j_s][10][j_e] * (arr[j_s][10][j_e] - 1) / 2;
			}
		}
	}
	else {
        vector<vector<unordered_map<int, ll>>>arr;
        arr.resize(n,vector<unordered_map<int, ll>>(20));
		for (int j = 0; j < m; j++) {
			for (int i_s = 0; i_s < n; i_s++) {
				for (int i_e = i_s + 1; i_e < n; i_e++) {
					int sum = inputs[i_s][j] + inputs[i_e][j];
					arr[i_s][sum][i_e]++;
				}
			}
		}

		for (int i_s = 0; i_s < n; i_s++) {
			for (int i_e = i_s + 1; i_e < n; i_e++) {
				for (int num_s = 2; num_s <= 9; num_s++) {
					int num_e = 20 - num_s;

					ans += arr[i_s][num_s][i_e] * arr[i_s][num_e][i_e];
				}
				if (arr[i_s][10][i_e] >= 2)ans += arr[i_s][10][i_e] * (arr[i_s][10][i_e] - 1) / 2;
			}
		}
	}
	cout << ans;
}