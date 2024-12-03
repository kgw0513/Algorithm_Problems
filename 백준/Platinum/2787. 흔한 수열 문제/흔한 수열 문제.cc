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

bool check_num[201][201];
//[현 위치][가능 숫자] = true면 가능숫자 o, false면 ㄴㄴ

vector<int>lines[201];
int bipartite[201];
bool visit[201];
bool dfs(int p) {
	visit[p] = true;
	for (int new_p : lines[p]) {
		//cout << p << "->" << new_p << ".\n";
		if (bipartite[new_p] == 0) {
			//cout << "들.\n";
			bipartite[new_p] = p;
			return true;
		}
		int h = bipartite[new_p];
		if (visit[h])continue;
		bipartite[new_p] = p;
		if (dfs(h))return true;
		bipartite[new_p] = h;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	//초기값 각 위치 가능숫자 전부 가능으로 바꾸기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check_num[i][j] = true;
		}
	}

	while (m--) {
		int h, a, b, c;
		cin >> h >> a >> b >> c;
		for (int i = 1; i <= n; i++) {
			if (i < a || b < i) {
				//현 범위 밖에 있을때
				//현 범위 내에는 무조건 c는 있는거니
				//c만 제외 시켜주면 됨
				check_num[i][c] = false;
				continue;
			}
			//현 범위 내에 있을때
			// h=1이면 무조건 c값 이하만 들어가야 하니 그 위 제거
			// h=2면 무조건 c값 이상만 들어가야 하니 그 아래 제거
			if (h == 1) {
				for (int j = c + 1; j <= n; j++) {
					check_num[i][j] = false;
				}
			}
			else if (h == 2) {
				for (int j = c - 1; j >= 1; j--) {
					check_num[i][j] = false;
				}
			}
		}
	}

	//그렇게 처리하고 나면 각 1부터 들어가야 할 범위가 나와짐
	//이분매칭으로 쓰기 위해 간선으로 넣기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check_num[i][j]) {
				lines[j].push_back(i);
			}
		}
	}

	//그걸 이분매칭으로 이어주는데 n개 안이어지면 -1출력
	for (int i = 1; i <= n; i++) {
		fill(visit, visit + n + 1, false);
		if (!dfs(i)) {
			//cout << i << "번째 실패.\n";
			cout << -1;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << bipartite[i] << " ";
	}
}