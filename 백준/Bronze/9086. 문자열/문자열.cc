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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string a;
	cin >> t;
	while (t--) {
		cin >> a;
		cout << a[0] << a[a.size() - 1] << "\n";
	}
}