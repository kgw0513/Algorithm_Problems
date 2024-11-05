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

vector<ll_ll>have_block;

ll arr[3][300005] = {};
ll_ll pos[300005][3] = {};
//[0: 좌측 넘어트림, 1: 그대로, 2: 우측 넘어트림][have_block 위치]
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, w;
	cin >> n;
	have_block.push_back({ -1,-1 });
	for (ll i = 1; i <= n; i++) {
		cin >> w;
		if (w == 0)continue;
		have_block.push_back({ i,w });
		pos[have_block.size() - 1][0] = { i - w,i - 1 };
		pos[have_block.size() - 1][1] = { i,i };
		pos[have_block.size() - 1][2] = { i + 1,i + w };

	}

	have_block.push_back({ n+1,0 });
	pos[have_block.size() - 1][0] = { n + 1,2 * n + 101 };
	pos[have_block.size() - 1][1] = { n + 1,2 * n + 101 };
	pos[have_block.size() - 1][2] = { n + 1,2 * n + 101 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 300005; j++) {
			arr[i][j] = lINF;
		}
	}
	
	arr[1][0] = 0;

	for (int i = 1; i < have_block.size(); i++) {
		//일단 현재 블록을 냅뒀을때 기준 보기
		for (int h = 0; h < 3; h++) { //블록 냅둔 상태
			for (int j = 0; j < 3; j++) { //이전 블록 상태
				ll_ll now_p = pos[i][h];
				ll_ll last_p = pos[i - 1][j];
				if (now_p.fi <= last_p.fi && last_p.fi <= now_p.se)continue; //블록은 겹칠 수 없다.
				if (now_p.fi <= last_p.se && last_p.se <= now_p.se)continue; //블록은 겹칠 수 없다.
				if (last_p.fi <= now_p.fi && now_p.fi <= last_p.se)continue; //블록은 겹칠 수 없다.
				if (last_p.fi <= now_p.se && now_p.se <= last_p.se)continue; //블록은 겹칠 수 없다.
				if (last_p.fi >= now_p.se)continue;
				//cout << i << "에서" << j << "vs" << h << "상태 비교 통과.\n";
				//cout << "last : " << last_p.fi << "~" << last_p.se << "\n";
				//cout << "now : " << now_p.fi << "~" << now_p.se << "\n";
				ll now_price = arr[h][i];
				ll new_price = arr[j][i - 1] + (now_p.fi - last_p.se - 1);
				if (now_price > new_price) {
					arr[h][i] = new_price;
				}
				//cout << "arr[" << h << "][" << i << "]:" << arr[h][i] << "\n\n";
			}
		}
	}

	ll h = have_block.size() - 1;
	ll a = arr[0][h];
	ll b = arr[1][h];
	ll c = arr[2][h];
	cout << min({ a,b,c });
}