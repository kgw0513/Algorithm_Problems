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
const long long lINF = 9223372036854775807;
const long long nlINF = 90000000000000;
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

bool arr[502][502];

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,ans=0,counting=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!arr[i][j])continue;
			counting++;
			int sum = 1;
			queue<intint>brr;
			brr.push({ i,j });
			arr[i][j] = false;
			while (brr.size()) {
				intint p = brr.front();
				brr.pop();
				for (int k = 0; k < 4; k++) {
					intint new_p = { p.f + dxdy[k].f,p.s + dxdy[k].s };
					if (arr[new_p.f][new_p.s]) {
						brr.push(new_p);
						arr[new_p.f][new_p.s] = false;
						sum++;
					}
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << counting << "\n" << ans;
}
