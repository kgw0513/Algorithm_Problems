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
//#include <ext/rope>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
//using namespace __gnu_cxx;

const long long INF = 2147483647;
const long long lINF = 9000000000000000000;
const int nINF = 1000000000;
unsigned long long MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;

int Union[20][300001];

int cost[300001];
intint move_Union[300001];
int counting[20][300001];
int find(int a,int p) {
	if (Union[p][a] != a)return Union[p][a] = find(Union[p][a], p);
	return a;
}
void UnionInput(int a,int b,int p) {//일치 안하면 들어옴.
	int ha = find(a, p);
	int hb = find(b, p);
	if (ha > hb)swap(ha, hb);
	if (ha == hb) {
		exit(-1);
		//같은게 들어올 수가 없음.
	}
	counting[p][hb] += counting[p][ha];
	counting[p][ha] = 0;
	Union[p][ha] = hb;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 300001; j++) {
			Union[i][j] = j;
			cost[j] = (1 << 20) - 1;
			counting[i][j] = 1;
		}
	}
	int n, q, a, b, w;
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b >> w;
		int h = cost[i] & w;
		for (int j = 0; j < 20; j++) {
			int nh = (1 << j);
			if ((h & nh) == (cost[i] & nh))continue;
			UnionInput(a, b, j);
		}
		cost[i] = h;
		move_Union[i] = { a,b };
	}
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> a >> w;
			int i = a;
			a = move_Union[i].f;
			b = move_Union[i].s;
			int h = cost[i] & w;
			for (int j = 0; j < 20; j++) {
				int nh = (1 << j);
				if ((h & nh) == (cost[i] & nh))continue;
				UnionInput(a, b, j);
			}
			cost[i] = h;
			move_Union[i] = { a,b };
			continue;
		}
		cin >> a;
		ll sum = 0;
		for (int p = 0; p < 20; p++) {
			ll left_n = n - counting[p][find(a, p)];
			sum += (1 << p) * left_n;
		}
		cout << sum << "\n";
	}
}