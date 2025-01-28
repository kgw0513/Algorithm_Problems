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

//true가 양수, false가 음수 이동
pair<bool, bool> two_move[4] = { {true,false},{false,false},{false,true},{true,true} };
bool cmp(ll2_ll& a, ll2_ll& b) {
	return a.se < b.se;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, a, b, c;
	cin >> n;
	vector<ll2_ll>inputs(n);
	ll first_num = -1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		inputs[i] = { {a,b},c };
		if (i == 0) {
			first_num = a + b + c;
		}
		else {
			if (first_num % 2 != (a + b + c) % 2) {
				cout << "NO";
				return 0;
			}
		}
	}
	sort(inputs.begin(), inputs.end(),cmp);

	//<-,위,->,아래
	vector<ll_ll>points = {
		{inputs[0].fi.fi - inputs[0].se,inputs[0].fi.se} ,
		{inputs[0].fi.fi,inputs[0].fi.se + inputs[0].se} ,
		{inputs[0].fi.fi + inputs[0].se,inputs[0].fi.se} ,
		{inputs[0].fi.fi,inputs[0].fi.se - inputs[0].se}
	};


	/*
	풀기전 우린 아래 방식에 따라 대각선 모양 직사각형이(또는 마름모가) 이전 모양과 비교해서 (이때 도형이 점점 커지는 순서)
	각각 구분을 할 예정.

	1. 일단 범위 안에 들어서 그 다음 모양을 만들 수 있는지 확인. (못들면 NO출력)
	2. 만약 이전 모양 범위가 현재 모양 안에 든다면 들어오는 점 갯수에 따라 처리 방식 따로 처리
	2-1. 들어오는 갯수가 4개면 이전 모양 그대로
	2-2. 들어오는 갯수가 2개면 대각선 선에 걸쳐졌다는 거니 직사각형 모양으로 처리.
	2-3. 들어오는 갯수가 1개면 끝점에 걸쳐져있다는 거니 이 역시 직사각형 모양 처리.
	+ 이때 걸쳐진 거는 직선끼리 교차점으로 구하기
	*/

	for (int i = 1; i < n; i++) {
		//<-,위,->,아래
		vector<ll_ll>new_points = {
		{inputs[i].fi.fi - inputs[i].se,inputs[i].fi.se} ,
		{inputs[i].fi.fi,inputs[i].fi.se + inputs[i].se} ,
		{inputs[i].fi.fi + inputs[i].se,inputs[i].fi.se} ,
		{inputs[i].fi.fi,inputs[i].fi.se - inputs[i].se}
		};
		ll_ll mid_point = inputs[i].fi;
		ll new_len = inputs[i].se;

		vector<ll_ll>setting_points(4);
		int complete_count = 0;
		bool is_in[4] = {};

		//1
		for (int j = 0; j < 4; j++) {
			ll dist = abs(points[j].fi - mid_point.fi) +
				abs(points[j].se - mid_point.se);
			if (dist <= new_len) {
				setting_points[j] = points[j];
				complete_count++;
				is_in[j] = true;
			}
		}
		assert(complete_count != 3);

		if (complete_count == 0) {
			cout << "NO";
			return 0;
		}

		//2

		//2-1
		if (complete_count == 4) {
			points = setting_points;
			continue;
		}

		//2-2
		if (complete_count == 2) {
			for (int j = 0; j < 4; j++) {
				int next_j = (j + 1) % 4;
				if (!is_in[j] || !is_in[next_j])continue;
				ll j_dist = 0;
				ll next_j_dist = 0;

				//y거리 계산
				if (j == 0 || j == 1) {
					j_dist -= setting_points[j].se - mid_point.se;
					next_j_dist -= setting_points[next_j].se - mid_point.se;
				}
				else {
					j_dist += setting_points[j].se - mid_point.se;
					next_j_dist += setting_points[next_j].se - mid_point.se;
				}
				//cout  << "y거리 : " << j_dist << "\n";
				//x거리 계산
				if (j == 1 || j == 2) {
					j_dist -= setting_points[j].fi - mid_point.fi;
					next_j_dist -= setting_points[next_j].fi - mid_point.fi;
				}
				else {
					j_dist += setting_points[j].fi - mid_point.fi;
					next_j_dist += setting_points[next_j].fi - mid_point.fi;
				}

				j_dist = new_len - j_dist;
				next_j_dist = new_len - next_j_dist;

				if (j_dist % 2 == 1)return -1;
				if (next_j_dist % 2 == 1)return -1;

				setting_points[((j + 3) % 4)].fi = setting_points[j].fi + (two_move[j].fi ? j_dist / 2 : -j_dist / 2);
				setting_points[((j + 3) % 4)].se = setting_points[j].se + (two_move[j].se ? j_dist / 2 : -j_dist / 2);

				setting_points[((next_j + 1) % 4)].fi = setting_points[next_j].fi + (two_move[j].fi ? next_j_dist / 2 : -next_j_dist / 2);
				setting_points[((next_j + 1) % 4)].se = setting_points[next_j].se + (two_move[j].se ? next_j_dist / 2 : -next_j_dist / 2);

				break;
			}

			points = setting_points;
			continue;
		}

		//2-3
		if (complete_count == 1) {
			for (int j = 0; j < 4; j++) {
				if (!is_in[j])continue;

				setting_points[(j + 2) % 4] = new_points[(j + 2) % 4];

				int for_dist_j = (j + 3) % 4;
				ll j_dist = 0;

				{
					//y거리 계산
					if (for_dist_j == 0 || for_dist_j == 1) {
						j_dist -= setting_points[j].se - mid_point.se;
					}
					else {
						j_dist += setting_points[j].se - mid_point.se;
					}

					//x거리 계산
					if (for_dist_j == 1 || for_dist_j == 2) {
						j_dist -= setting_points[j].fi - mid_point.fi;
					}
					else {
						j_dist += setting_points[j].fi - mid_point.fi;
					}

					j_dist = new_len - j_dist;

					if (j_dist % 2 == 1)return -1;


					setting_points[((j + 1) % 4)].fi = setting_points[j].fi + (two_move[for_dist_j].fi ? j_dist / 2 : -j_dist / 2);
					setting_points[((j + 1) % 4)].se = setting_points[j].se + (two_move[for_dist_j].se ? j_dist / 2 : -j_dist / 2);
				}

				int for_dist_j_back = j;
				ll j_dist_back = 0;
				{
					//y거리 계산
					if (for_dist_j_back == 0 || for_dist_j_back == 1) {
						j_dist_back -= setting_points[j].se - mid_point.se;
					}
					else {
						j_dist_back += setting_points[j].se - mid_point.se;
					}

					//x거리 계산
					if (for_dist_j_back == 1 || for_dist_j_back == 2) {
						j_dist_back -= setting_points[j].fi - mid_point.fi;
					}
					else {
						j_dist_back += setting_points[j].fi - mid_point.fi;
					}

					j_dist_back = new_len - j_dist_back;

					if (j_dist_back % 2 == 1)return -1;

					setting_points[((j + 3) % 4)].fi = setting_points[j].fi + (two_move[for_dist_j_back].fi ? j_dist_back / 2 : -j_dist_back / 2);
					setting_points[((j + 3) % 4)].se = setting_points[j].se + (two_move[for_dist_j_back].se ? j_dist_back / 2 : -j_dist_back / 2);
				}
				break;
			}

			points = setting_points;
			continue;
		}

		return -1;
	}

	ll_ll ans = points[0];
	for (int i = 1; i < 4; i++) {
		if (points[i].fi < ans.fi || (points[i].fi == ans.fi && ans.se > points[i].se))ans = points[i];
	}
	cout << points[0].fi << " " << points[0].se;
}