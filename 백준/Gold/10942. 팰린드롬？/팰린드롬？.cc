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
#define INF -1000000000

using namespace std;

int arr[2000] = {};
int brr[2001][2000] = {};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		brr[1][i] = 1;
		brr[0][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			if (arr[j] == arr[j + i - 1] && brr[i - 2][j + 1])brr[i][j] = 1;
		}
	}
	cin >> n;
	while (n--) {
		cin >> w >> a;
		w--;
		a--;
		cout << brr[a - w + 1][w] << "\n";
	}
}