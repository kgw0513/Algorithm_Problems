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

int n, m;
//1~n 해당 후보 당선 성공
//n+1~2n 해당 후보 당선 실패

vector<int>lines[2002];
vector<int>reverse_lines[2002];

bool visit1[2002];
bool visit2[2002];
int scc[2002];

inline int reverse_num(int num) {
	if (num <= n)return num + n;
	return num - n;
}

void dfs1(int p,stack<int>& arr) {
	if (visit1[p])return;
	visit1[p] = true;
	for (int h : lines[p]) {
		dfs1(h, arr);
	}
	arr.push(p);
}

void dfs2(int p,const int give_n) {
	if (visit2[p])return;
	visit2[p] = true;
	scc[p] = give_n;
	for (int h : reverse_lines[p]) {
		dfs2(h, give_n);
	}
}
void cal() {
	for (int i = 1; i <= 2*n; i++) {
		lines[i].clear();
		reverse_lines[i].clear();
		scc[i] = 0;
		visit1[i] = false;
		visit2[i] = false;
	}

	string st1, st2;
	for (int i = 0; i < m; i++) {
		cin >> st1 >> st2;
		int a = stoi(st1.substr(1));
		int b = stoi(st2.substr(1));
		if (st1[0] == '-')a = reverse_num(a);
		if (st2[0] == '-')b = reverse_num(b);
		int re_a = reverse_num(a);
		int re_b = reverse_num(b);

		lines[re_a].push_back(b);
		reverse_lines[b].push_back(re_a);

		lines[re_b].push_back(a);
		reverse_lines[a].push_back(re_b);
	}

	stack<int>arr;
	for (int i = 1; i <= 2*n; i++) {
		dfs1(i, arr);
	}
	int give_scc = 0;
	while (arr.size()) {
		dfs2(arr.top(), ++give_scc);
		arr.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i + n]) {
			cout << "0\n";
			return;
		}
	}
	cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n) {
		cin >> m;
		cal();
	}
}