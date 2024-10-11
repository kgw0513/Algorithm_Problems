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

ll arr[2001];
ll brr[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, r, d, m;
	cin >> n >> r >> d >> m;
	fill(arr, arr + 2001, INF);
	fill(brr, brr + 2001, INF);
	arr[r] = 0;
	brr[d] = 0;
	while (m--) {
		ll h, t, e1, e2;
		cin >> h >> t >> e1 >> e2;
		if (e1 > e2)swap(e1, e2);
		ll gap = e2 - e1;
		ll e1_up_gap = e1 - 1;
		ll e1_down_gap = h - e1;
		ll e2_up_gap = e2 - 1;
		ll e2_down_gap = h - e2;
		//좌측 기준
		{
			for (int i = 1; i <= n; i++) {
				//아래로 내려가는 모습
				if (arr[i] != INF && i - e1_up_gap >= 1) {
					for (int j = i; j + e1_down_gap <= n; j += gap) {
						ll next_j = j + gap;
						arr[next_j] = min(arr[j] + t, arr[next_j]);
						break;
					}
				}
				if (brr[i] != INF && i - e1_up_gap >= 1) {
					for (int j = i; j + e1_down_gap <= n; j += gap) {
						ll next_j = j + gap;
						brr[next_j] = min(brr[j] + t, brr[next_j]);
						break;
					}
				}

			}
			for (int i = n; i >= 1; i--) {
				//위로 올라가는 모습
				if (arr[i] != INF && i + e2_down_gap <= n) {
					for (int j = i; j - e2_up_gap >= 1; j -= gap) {
						ll next_j = j - gap;
						if (arr[j] + t >= arr[next_j])break;
						arr[next_j] = min(arr[j] + t, arr[next_j]);
					}
				}
				if (brr[i] != INF && i + e2_down_gap <= n) {
					for (int j = i; j - e2_up_gap >= 1; j -= gap) {
						ll next_j = j - gap;
						if (brr[j] + t >= brr[next_j])break;
						brr[next_j] = min(brr[j] + t, brr[next_j]);
					}
				}
			}
		}
	}
	ll ans = INF;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, arr[i] + brr[i]);
	}
	if (ans == INF)cout << -1;
	else cout << ans;
}