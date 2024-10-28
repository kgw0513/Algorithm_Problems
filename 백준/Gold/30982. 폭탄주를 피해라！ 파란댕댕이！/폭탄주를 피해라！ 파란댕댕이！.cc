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
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;

const int INF = 2147483647;
const int nINF = 10000000;

typedef long long ll;
typedef pair<int, int> intint;
typedef pair<int, ll> intlong;
typedef pair<intint, int> int2_int;
typedef pair<int, char> int_char;
typedef pair<double, double>dd;
typedef pair<double, int>dint;
ll dogs_left_team[100001];
ll dogs_right_team[100001];
vector<int>arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < 100001; i++) {
		dogs_left_team[i] = INF;
		dogs_right_team[i] = INF;
	}
	int n, m, w, t, p;
	cin >> n >> m >> t;
	while (n--) {
		cin >> w;
		arr.push_back(w);
	}
	cin >> p;
	p--;
	for (ll timer = 1; p - timer >= 0; timer++) {
		int i = p - timer;
		w = arr[i];
		for (int j = 100000; j >= w; j--) {
			if (dogs_left_team[j - w] != INF)dogs_left_team[j] = min(timer, dogs_left_team[j]);
		}
	}
	for (ll timer = 1; p + timer < arr.size(); timer++) {
		int i = p + timer;
		w = arr[i];
		for (int j = 100000; j >= w; j--) {
			if (dogs_right_team[j - w] != INF)dogs_right_team[j] = min(timer, dogs_right_team[j]);
		}
	}
	int s = 0, e = m - arr[p];
	while (e >= 0) {
		ll short_time = min(dogs_left_team[s], dogs_right_team[e]);
		ll long_time = max(dogs_left_team[s], dogs_right_team[e]);
		ll all_time = short_time * 2 + long_time;
		//cout << s << "," << e << "/" << dogs_left_team[s]<<"," << dogs_right_team[e] << "\n";
		if (all_time <= t) {
			cout << "YES";
			return 0;
		}
		s++;
		e--;
	}
	cout << "NO";
}
