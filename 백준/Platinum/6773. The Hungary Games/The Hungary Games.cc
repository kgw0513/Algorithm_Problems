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

class Dijk {
	ll s, e;
	vector<vector<ll_ll>>lines;
	set<ll_ll>block_line;
	//{{0또는 1, 위치} = {최소 값에 해당되는 이전 정점 위치들}
	map<ll_ll, vector<ll_ll>>track;
	vector<ll>costs[2];

	struct cmp {
		bool operator()(ll2_ll a, ll2_ll b) {
			return a.se > b.se;
		}
	};

	inline void insert_block_line(ll_ll a) {
		block_line.insert(a);
	}

	inline void Clear() {
		track.clear();
		fill(costs[0].begin(), costs[0].end(), nlINF);
		fill(costs[1].begin(), costs[1].end(), nlINF);
	}

public:
	Dijk() = delete;
	Dijk(int n) {
		s = 1;
		e = n;
		lines.resize(n + 2, vector<ll_ll>());
		costs[0].resize(n + 2, 0);
		costs[1].resize(n + 2, 0);
	}

	inline void insert_line(int a, int b, int cost) {
		lines[a].push_back({ b,cost });
	}

	void Cal_Dijk() {
		Clear();

		priority_queue<ll2_ll, vector<ll2_ll>, cmp>arr; //{위치,비용}
		arr.push({ {0,s},0 });
		costs[0][s] = 0;

		while (!arr.empty()) {
			ll_ll p = arr.top().fi;
			//cout << p.fi << "의 " << p.se << "방문.\n";
			ll c = arr.top().se;
			arr.pop();
			if (costs[p.fi][p.se] != c)continue;
			for (ll_ll next_p : lines[p.se]) {
				ll_ll p2 = { p.fi,next_p.fi };
				ll nc = c + next_p.se;
				if (block_line.find({ p.se,next_p.fi }) == block_line.end()) {
					p2.fi = 1;
				}
				if (costs[p2.fi][p2.se] >= nc) {
					if (costs[p2.fi][p2.se] > nc) {
						track[p2].clear();
						arr.push({ p2,nc });
					}
					costs[p2.fi][p2.se] = nc;
					track[p2].push_back(p);
				}
			}
		}

	}

	inline ll Give_ans() {
		return (costs[1][e] == nlINF ? -1 : costs[1][e]);
	}

	void Backtrack() {
		queue<ll_ll>arr;
		set<ll_ll>visit;
		visit.insert({ 1,e });
		visit.insert({ 0,s });

		arr.push({ 1,e });
		while (!arr.empty()) {
			ll_ll p = arr.front();
			arr.pop();
			for (ll_ll& lp : track[p]) {
				//cout << lp.fi << "," << lp.se << " => " << p.fi << "," << p.se << "\n";
				insert_block_line({ lp.se, p.se });
				if (visit.find(lp) == visit.end()) {
					arr.push(lp);
					visit.insert(lp);
				}
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	Dijk* ans = new Dijk(n);
	while (m--) {
		cin >> a >> b >> c;
		ans->insert_line(a, b, c);
	}

	ans->Cal_Dijk();
	ll min_cost = ans->Give_ans();
	if (min_cost == -1) {
		cout << -1;
		return 0;
	}
	ans->Backtrack();
	ans->Cal_Dijk();
	ll h = ans->Give_ans();
	cout << h;
	delete(ans);
}
