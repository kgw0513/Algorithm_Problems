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

//digit dp
//[N의 수를 따라가는 중인가][현재 자릿수의 숫자][자릿수]={현재까지 다 더한 수}
bool visit[2][10][100002];
ll dp[2][10][100002];
ll counting[2][10][100002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	visit[1][0][0] = true;
	counting[1][0][0]++;
	int No_num;
	string n;
	cin >> No_num >> n;
	n = '0' + n;
	for (int i = 1; i < n.size(); i++) {
		//만약 N에 따라 이동중일때
		{
			//계속 N에 따라 이동할거라면
			{
				if (visit[1][n[i - 1] - '0'][i - 1]) {
					//현재 자릿수가 k일때
					if (n[i] - '0' == No_num) {
						dp[1][n[i] - '0'][i] += dp[1][n[i - 1] - '0'][i - 1];
						dp[1][n[i] - '0'][i] %= MOD1;
						counting[1][n[i] - '0'][i]+= counting[1][n[i - 1] - '0'][i - 1];
						counting[1][n[i] - '0'][i] %= MOD1;
						visit[1][n[i] - '0'][i] = true;
					}
					else { //현재 자릿수가 k가 아닐때
						dp[1][n[i] - '0'][i] += dp[1][n[i - 1] - '0'][i - 1] * 10 + (n[i] - '0')* counting[1][n[i - 1] - '0'][i - 1];
						dp[1][n[i] - '0'][i] %= MOD1;
						counting[1][n[i] - '0'][i]+= counting[1][n[i - 1] - '0'][i - 1];
						counting[1][n[i] - '0'][i] %= MOD1;
						visit[1][n[i] - '0'][i] = true;
					}
				}
			}

			//이제 N에 벗어나고 싶으면
			{
				if (visit[1][n[i - 1] - '0'][i - 1]) {
					for (int k = 0; k < n[i] - '0'; k++) {
						//갈 자릿수가 싫어하는 숫자일때
						if (k == No_num) {
							dp[0][k][i] += dp[1][n[i - 1] - '0'][i - 1];
							dp[0][k][i] %= MOD1;
							counting[0][k][i]+= counting[1][n[i - 1] - '0'][i - 1];
							counting[0][k][i] %= MOD1;
							visit[0][k][i] = true;
						}
						else {
							dp[0][k][i] += dp[1][n[i - 1] - '0'][i - 1] * 10 + k * counting[1][n[i - 1] - '0'][i - 1];
							dp[0][k][i] %= MOD1;
							counting[0][k][i]+= counting[1][n[i - 1] - '0'][i - 1];
							counting[0][k][i] %= MOD1;
							visit[0][k][i] = true;
						}
					}
				}
			}
		}

		//N에 따라 이동하고 있지 않을때
		{
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					if (visit[0][k][i - 1] == false)continue;
					//cout << i << "에서, " << j << "," << k << "들어왔다.\n";
					//cout << 0 << "," << k << "," << i - 1 << "들.\n";
					if (j == No_num) {
						dp[0][j][i] += dp[0][k][i - 1];
						dp[0][j][i] %= MOD1;
						counting[0][j][i]+= counting[0][k][i - 1];
						counting[0][j][i] %= MOD1;
						visit[0][j][i] = true;
					}
					else {
						dp[0][j][i] += dp[0][k][i - 1] * 10 + j * counting[0][k][i - 1];
						dp[0][j][i] %= MOD1;
						counting[0][j][i]+=counting[0][k][i - 1];
						counting[0][j][i] %= MOD1;
						visit[0][j][i] = true;
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) {
		//cout << "[0][" << i << "][" << n.size() - 1 << "] : " << dp[0][i][n.size() - 1] << "\n";
		if (visit[0][i][n.size() - 1]) {
			ans += dp[0][i][n.size() - 1];
			ans %= MOD1;
		}
		 //cout << "[1][" << i << "][" << n.size() - 1 << "] : " << dp[1][i][n.size() - 1] << "\n";
		if (visit[1][i][n.size() - 1]) {
			ans += dp[1][i][n.size() - 1];
			ans %= MOD1;
		}
		//cout << ans << "중.\n";
	}
	cout << ans;
}