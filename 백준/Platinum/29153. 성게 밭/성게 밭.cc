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

vector<int>line[15001];
set<int>vertex;
vector<int>new_line[15001];


set<int>start_vertex;
set<int>end_vertex;
vector<int>vertex_line[15001];
bool visit[15001];
int end_pos[15001];

bool dfs(int p) {
	if (visit[p])return false;
	visit[p] = true;

	for (int next_p : vertex_line[p]) {
		if (end_pos[next_p] == 0 || dfs(end_pos[next_p])) {
			end_pos[next_p] = p;
			return true;
		}
	}
	return false;
}

void make_dfs(int p, int deep) {
	if (visit[p])return;
	visit[p] = true;
	for (int next_p : new_line[p]) {
		if (deep %2 == 0) {
			start_vertex.insert(p);
			end_vertex.insert(next_p);
			vertex_line[p].push_back(next_p);
			//cout << p << "->" << next_p << "\n";
		}
		else {
			start_vertex.insert(next_p);
			end_vertex.insert(p);
			vertex_line[next_p].push_back(p);
			//cout << next_p << "->" << p << "\n";
		}

		make_dfs(next_p, deep + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		//cout << i << ":" << line[i].size() << "\n";
		if (line[i].size() == 1) {
			vertex.insert(line[i][0]);
		}
		else if (line[i].size() == 2) {
			vertex.insert(line[i][0]);
			vertex.insert(line[i][1]);
			new_line[line[i][0]].push_back(line[i][1]);
			new_line[line[i][1]].push_back(line[i][0]);
		}
	}

	for (int s : vertex) {
		make_dfs(s, 0);
	}

	int matching = 0;
	for (int s : start_vertex) {
		fill(visit, visit + 15001, false);
		if (dfs(s))matching++;
	}
	cout << vertex.size() - matching;
}