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
	string a, b;
	vector<char>arr;
	cin >> a >> b;
	if (a.size() < b.size()) {
		cout << a;
		return 0;
	}
	for (int i = 0; i < a.size(); i++) {
		arr.push_back(a[i]);
		if (arr.size() >= b.size()) {
			bool matching = true;
			int k = arr.size() - 1;
			for (int j = b.size()-1; j >= 0; j--) {
				if (arr[k] != b[j]) {
					matching = false;
					break;
				}
				k--;
			}
			if (matching) {
				for (int i = 0; i < b.size(); i++) {
					arr.pop_back();
				}
			}
		}
	}
	if (arr.size()) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}
	else cout << "FRULA";
}