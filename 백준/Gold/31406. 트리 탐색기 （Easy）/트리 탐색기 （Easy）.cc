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

bool is_toggle[2001];
int last_file[2001];
deque<int>next_file[2001];
int rem_pos[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, m;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		next_file[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> next_file[i][j];
			last_file[next_file[i][j]] = i;
		}
	}
	last_file[1] = -1;
	int now_file = 1;
	int move_count;
	string w;
	while (q--) {
		cin >> w;
		if (w == "toggle") {
			if (rem_pos[now_file] >= next_file[now_file].size() || rem_pos[now_file] < 0)return -1; //이러한 값이 들어오면 오류
			is_toggle[next_file[now_file][rem_pos[now_file]]] = !is_toggle[next_file[now_file][rem_pos[now_file]]];
			continue;
		}

		//cout << w << "가 옴.\n";
		assert(w == "move");
		cin >> move_count;
		if (move_count > 0) {
			while (move_count>0) {
				move_count--;
				int next_move = next_file[now_file][rem_pos[now_file]];
				if (!is_toggle[next_move] || next_file[next_move].size() == 0) {
					//파일이 닫혀있을때
					rem_pos[now_file]++;
				}
				else if (is_toggle[next_move]) {
					//파일이 열려있을때
					now_file = next_move;
				}

				int rem_its_file = now_file;
				bool sorry_itsend = false;
				while (rem_pos[now_file] >= next_file[now_file].size()) {
					rem_pos[now_file] = next_file[now_file].size() - 1;
					if (now_file == 1) {
						sorry_itsend = true;
						break;
					}
					now_file = last_file[now_file];
					rem_pos[now_file]++;
				}
				if (sorry_itsend) {
					now_file = rem_its_file;
					move_count = 0; //어차피 마지막이라 더 내려갈곳도 없음.
				}
			}
			cout << next_file[now_file][rem_pos[now_file]] << "\n";
		}
		else {
			while (move_count < 0) {
				//cout << now_file << "파일이 " << rem_pos[now_file] <<
					//"가리키는 중.\n";
				move_count++;
				rem_pos[now_file]--;
				if (rem_pos[now_file] < 0) {
					rem_pos[now_file] = 0;
					if (now_file == 1) {
						move_count = 0;
						break;
					}
					now_file = last_file[now_file];
					continue;
				}

				//cout << now_file << "의 " << is_toggle[now_file] << "과" << next_file[now_file].size() << "상황.\n";
				//cout << rem_pos[now_file] << "가리키는 중.\n";
				while (!(!is_toggle[next_file[now_file][rem_pos[now_file]]] || next_file[next_file[now_file][rem_pos[now_file]]].size() == 0)) {
					//파일이 열려있을때
					//cout << now_file << "이. ";
					now_file = next_file[now_file][rem_pos[now_file]];
					//cout << now_file << "로 감.\n";
				}
			}
			cout << next_file[now_file][rem_pos[now_file]] << "\n";
		}
	}
}