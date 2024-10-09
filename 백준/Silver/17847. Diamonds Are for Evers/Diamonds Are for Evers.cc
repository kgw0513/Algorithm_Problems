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

char arr[33][33];
int n;
void print_right_up(intint p, int line) {
	vector<char>brr;
	while (p.fi >= line && p.fi <= n - line + 1 && p.se >= line && p.se <= n - line + 1) {
		brr.push_back(arr[p.fi][p.se]);
		p.fi--;
		p.se++;
	}
	if (brr.size()) {
		brr.pop_back();
		//cout << "시작.\n";
		for (int i = 0; i < brr.size(); i++) {
			cout << brr[i];
		}
		//cout << "깢.\n";
	}
}
void print_right_down(intint p, int line) {
	vector<char>brr;
	while (p.fi >= line && p.fi <= n - line + 1 && p.se >= line && p.se <= n - line + 1) {
		brr.push_back(arr[p.fi][p.se]);
		p.fi++;
		p.se++;
	}
	if (brr.size()) {
		brr.pop_back();
		for (int i = 0; i < brr.size(); i++) {
			cout << brr[i];
		}
	}
}
void print_left_down(intint p, int line) {
	vector<char>brr;
	while (p.fi >= line && p.fi <= n - line + 1 && p.se >= line && p.se <= n - line + 1) {
		brr.push_back(arr[p.fi][p.se]);
		p.fi++;
		p.se--;
	}
	if (brr.size()) {
		brr.pop_back();
		for (int i = 0; i < brr.size(); i++) {
			cout << brr[i];
		}
	}
}
void print_left_up(intint p, int line) {
	vector<char>brr;
	while (p.fi >= line && p.fi <= n - line + 1 && p.se >= line && p.se <= n - line + 1) {
		brr.push_back(arr[p.fi][p.se]);
		p.fi--;
		p.se--;
	}
	if (brr.size()) {
		brr.pop_back();
		for (int i = 0; i < brr.size(); i++) {
			cout << brr[i];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string w;
	cin >> w;
	n = sqrt(w.size());
	assert(n * n == w.size());
	int mid = (n + 1) / 2;
	int p = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = w[p++];
		}
	}
	for (int i = 1; i <= mid; i++) {
		//cout << mid << "," << i << "?\n";
		print_right_up({ mid,i },i);
		print_right_down({ i,mid },i);
		print_left_down({ mid,n - i + 1 },i);
		print_left_up({ n - i + 1,mid },i);
	}
	cout << arr[mid][mid];
}