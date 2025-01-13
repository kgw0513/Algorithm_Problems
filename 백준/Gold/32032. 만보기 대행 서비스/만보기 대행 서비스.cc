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
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, d;
	cin >> n >> d;
	vector<ll>pos;
	vector<ll>neg;
	for (int i = 0; i < n; i++) {
		ll w;
		cin >> w;
		if (w > 0)pos.push_back(w);
		else neg.push_back(-w);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	if (neg.empty()) {
		cout << pos.back() * 2 + d;
		return 0;
	}
	if (pos.empty()) {
		cout << neg.back() * 2 + d;
		return 0;
	}
	ll dist = (pos.back() + neg.back());

	//동동 서서, 서서 동동
	ll ans1 = pos.back() * 2 + neg.back() * 2 + d * 2;

	//동서동서
	ll ans2 = 0;
	{
		ans2 += pos.back();
		ans2 += dist * 2;
		ll pos_left_time = max(0ll, d - dist * 2);
		ans2 += pos_left_time;
		ans2 += dist;
		ll neg_left_time = max(0ll, d - dist * 2 - pos_left_time);
		ans2 += neg_left_time;
		ans2 += neg.back();
	}

	//서동서동
	ll ans3 = 0;
	{
		ans3 += neg.back();
		ans3 += dist * 2;
		ll neg_left_time = max(0ll, d - dist * 2);
		ans3 += neg_left_time;
		ans3 += dist;
		ll pos_left_time = max(0ll, d - dist * 2 - neg_left_time);
		ans3 += pos_left_time;
		ans3 += pos.back();
	}

	//서동동서
	ll ans4 = 0;
	{
		ans4 += neg.back(); //서 도달

		ans4 += dist; //동 도달
		ans4 += d;
		ans4 += dist;
		ans4 += neg.back();
	}

	//동서서동
	ll ans5 = 0;
	{
		ans5 += pos.back(); //동 도달

		ans5 += dist; //서 도달
		ans5 += d;
		ans5 += dist;
		ans5 += pos.back();
	}
	cout << min({ ans1, ans2,ans3,ans4,ans5 });
}