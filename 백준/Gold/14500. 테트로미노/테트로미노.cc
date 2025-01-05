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
#pragma warning(disable:4996)
#define nINF -1000000000
#define INF 1000000000

using namespace std;
int brr[500][500] = {};
bool visit[500][500] = {};

int n, m;
int loop(int now, int x, int y) {
	if (now == 3)return brr[x][y];
	visit[x][y] = true;
	int maximum = -1;
	if (x != 0 && visit[x - 1][y] == false) {
		maximum = max(maximum, loop(now + 1, x - 1, y));
	}
	if (x != n - 1 && visit[x + 1][y] == false) {
		maximum = max(maximum, loop(now + 1, x + 1, y));
	}
	if (y != 0 && visit[x][y - 1] == false) {
		maximum = max(maximum, loop(now + 1, x, y - 1));
	}
	if (y != m - 1 && visit[x][y + 1] == false) {
		maximum = max(maximum, loop(now + 1, x, y + 1));
	}
	if (now == 0) {
		if (x != 0 && x != n - 1) {
			if (y != 0) {
				maximum = max(maximum, loop(now + 3, x, y - 1) + brr[x - 1][y] + brr[x + 1][y]);
			}
			if (y != m - 1) {
				maximum = max(maximum, loop(now + 3, x, y + 1) + brr[x - 1][y] + brr[x + 1][y]);
			}
		}
		if (y != 0 && y != m - 1) {
			if (x != 0) {
				maximum = max(maximum, loop(now + 3, x - 1, y) + brr[x][y - 1] + brr[x][y + 1]);
			}
			if (x != n - 1) {
				maximum = max(maximum, loop(now + 3, x + 1, y) + brr[x][y - 1] + brr[x][y + 1]);
			}
		}
	}
	visit[x][y] = false;
	return brr[x][y] + maximum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int maximum = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> brr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k = loop(0, i, j);
			if (k > maximum) {
				maximum = k;
				//cout << i << "," << j << "에서 변동:" << k << "\n";
			}
		}
	}
	cout << maximum;
}