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
const long long nlINF = lINF / 10000;
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

bool visit[200001];
vector<int2_int2>find_num;
vector<int_int2>lines[200001];

int find_mid = -1;
bool dfs(int p, int parent) {
	if (visit[p]) {
		find_mid = p;
		return true;
	}
	visit[p] = true;
	for (int_int2 next : lines[p]) {
		int next_p = next.fi;
		int cost = next.se.fi;
		int line = next.se.se;
		if (next_p == parent)continue;
		if (dfs(next_p, p)) {
			if (find_mid != -1)find_num.push_back({ {p,next_p},{cost,line} });
			if (p == find_mid)find_mid = -1;
			return true;
		}
	}
	return false;
}

int Union[200001];

int find(int p) {
	if (p == Union[p])return p;
	return Union[p] = find(Union[p]);
}

struct cmp {
	bool operator()(int2_int2& a, int2_int2& b) {
		return a.se.fi < b.se.fi;
	}
};
bool cmp2(int2_int2& a, int2_int2& b) {
	return a.se.fi < b.se.fi;
}
priority_queue<int2_int2, vector<int2_int2>, cmp>arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		Union[i] = i;
	}
	for(int i=1;i<=m;i++){
		cin >> a >> b >> c;
		lines[a].push_back({ b,{c,i} });
		lines[b].push_back({ a,{c,i} });
		arr.push({ {a,b},{c,i} });
	}
	if (!dfs(1, -1)) {
		cout << "NO";
		return 0;
	}
	sort(find_num.begin(), find_num.end(), cmp2);

	assert(find_num.size() >= 3);

	cout << "YES\n";


	ll ans = find_num[0].se.fi;
	
	cout << find_num[0].se.se;
	{
		a = find(find_num[0].fi.fi);
		b = find(find_num[0].fi.se);
		if (a != b) {
			if (a > b)swap(a, b);
			Union[a] = b;
		}
	}

	while (!arr.empty()) {
		intint dest = arr.top().fi;
		ll cost = arr.top().se.fi;
		int line = arr.top().se.se;
		arr.pop();
		a = find(dest.fi);
		b = find(dest.se);
		if (a != b) {
			if (a > b)swap(a, b);
			Union[a] = b;
			ans += cost;
			cout << " " << line;
		}
	}
	
}