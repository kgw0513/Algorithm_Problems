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
pbds c++ set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset                     ڵ忡           ٸ   Ʒ   ڵ       .(    erase        ۵        ʴ´ .)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

 ̿ܿ          ø           Ÿ Ժ    ϸ   ȴ .
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

intint Check[402][402][402] = {};

int S_Next[1003][1003];
int M_Next[1003][1003];
int E_Next[1003][1003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 1003; i++) {
		for (int j = 0; j < 1003; j++) {
			S_Next[i][j] = -1;
			M_Next[i][j] = -1;
			E_Next[i][j] = -1;
		}
	}
	for (int i = 0; i < 402; i++)
	{
		for (int j = 0; j < 402; j++)
		{
			for (int k = 0; k < 402; k++)
			{
				Check[i][j][k] = { INF,INF };
			}
		}
	}

	int n;
	cin >> n;
	vector<int>arr;
	{
		int max_time;
		cin >> max_time;

		int last_time = 0;
		int w;
		for (int i = 0; i < n; i++) {
			cin >> w;
			int left_time = w - last_time - 1;
			if (left_time > 0)
				arr.push_back(left_time);
			last_time = w;
		}

		int left_time = max_time - last_time - 1;
		if (left_time > 0)
			arr.push_back(left_time);

		if (arr.empty()) {
			cout << 0;
			return 0;
		}

		Check[0][0][0] = { 0,arr[0] };
	}

	//for (int i = 0; i < arr.size(); i++) {
	//	cout << arr[i] << ",";
	//}
	//cout << "\n";
	int S, M, E;
	cin >> S >> M >> E;
	vector<int>Science(S);
	vector<int>Math(M);
	vector<int>English(E);
	for (int i = 0; i < S; i++) {
		cin >> Science[i];
		int find_last = 1;
		for (int j = 0; j < arr.size(); j++) {
			for (; find_last < arr.size(); find_last++) {
				if (find_last <= j)find_last = j + 1;
				if (find_last >= arr.size())break;
				if (Science[i] > arr[find_last])continue;
				S_Next[i][j] = find_last;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> Math[i];
		int find_last = 1;
		for (int j = 0; j < arr.size(); j++) {
			for (; find_last < arr.size(); find_last++) {
				if (find_last <= j)find_last = j + 1;
				if (find_last >= arr.size())break;
				if (Math[i] > arr[find_last])continue;
				M_Next[i][j] = find_last;
				break;
			}
		}
	}
	for (int i = 0; i < E; i++) {
		cin >> English[i];
		int find_last = 1;
		for (int j = 0; j < arr.size(); j++) {
			for (; find_last < arr.size(); find_last++) {
				if (find_last <= j)find_last = j + 1;
				if (find_last >= arr.size())break;
				if (English[i] > arr[find_last])continue;
				E_Next[i][j] = find_last;
				break;
			}
		}
	}

	int ans = 0;
	for (int s = 0; s <= S; s++) {
		for (int m = 0; m <= M; m++) {
			for (int e = 0; e <= E; e++) {
				//cout << s << "," << m << "," << e << "방문.\n";
				if (Check[s][m][e].fi == INF)
					continue;

				//cout << "시작~\n";
				if (s < S) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = Science[s];

					if (need_time > left_time) {
						//cout << "고고고1\n";
						//cout << s << "," << now_p << " ?(1)\n";
						int move_next = S_Next[s][now_p];
						now_p = move_next;
						if (move_next != -1)left_time = arr[move_next] - need_time;
						//cout << move_next << "," << left_time << " !(1)\n";
						//cout << "ㄱㅊ1.\n";

					}
					else {
						left_time -= need_time;
					}

					if (now_p != -1) {
						if (Check[s + 1][m][e].fi > now_p || (Check[s + 1][m][e].fi == now_p && Check[s + 1][m][e].se < left_time))
						{
							Check[s + 1][m][e] = { now_p,left_time };

							//cout << "S 성공.(" << now_p << "," << left_time << ")/(" << s + 1 << "," << m << "," << e << ")\n";
							ans = max(ans, s + m + e + 1);
						}
					}
				}

				if (m < M) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = Math[m];

					if (need_time > left_time) {
						//cout << "고고고2\n";
						//cout << m << "," << now_p << " ?(2)\n";
						int move_next = M_Next[m][now_p];
						now_p = move_next;
						if (move_next != -1)left_time = arr[move_next] - need_time;
						//cout << move_next << "," << left_time << " !(2)\n";
						//cout << "ㄱㅊ2.\n";

					}
					else {
						left_time -= need_time;
					}


					if (now_p != -1) {
						if (Check[s][m + 1][e].fi > now_p || (Check[s][m + 1][e].fi == now_p && Check[s][m + 1][e].se < left_time))
						{
							Check[s][m + 1][e] = { now_p,left_time };

							//cout << "M 성공.(" << now_p << "," << left_time << ")/(" << s << "," << m + 1 << "," << e << ")\n";
							ans = max(ans, s + m + e + 1);
						}
					}
				}

				if (e < E) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = English[e];

					if (need_time > left_time) {
						//cout << "고고고3\n";
						//cout << e << "," << now_p << " ?(3)\n";
						int move_next = E_Next[e][now_p];
						now_p = move_next;
						if (move_next != -1)left_time = arr[move_next] - need_time;
						//cout << move_next << "," << left_time << " !(3)\n";
						//cout << "ㄱㅊ3.\n";

					}
					else {
						left_time -= need_time;
					}

					if (now_p != -1) {
						if (Check[s][m][e + 1].fi > now_p || (Check[s][m][e + 1].fi == now_p && Check[s][m][e + 1].se < left_time))
						{
							Check[s][m][e + 1] = { now_p,left_time };

							//cout << "E 성공.(" << now_p << "," << left_time << ")/(" << s << "," << m << "," << e + 1 << ")\n";
							ans = max(ans, s + m + e + 1);
						}
					}
				}
			}
		}
	}

	cout << ans;
}